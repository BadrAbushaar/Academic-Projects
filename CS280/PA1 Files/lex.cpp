#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include "lex.h"
using namespace std;

map<string, Token> keyWords = {
    {"PROGRAM", PROGRAM},
    {"PRINT", PRINT},
    {"INT", INT},
    {"END", END},
    {"FLOAT", FLOAT},
    {"ELSE", ELSE},
    {"IF", IF},
    {"THEN", THEN},
    {"TRUE", TRUE},
    {"FALSE", FALSE},
    {"BOOL", BOOL}};

map<Token, string> tokenPrint = {
    {PROGRAM, "PROGRAM"},
    {PRINT, "PRINT"},
    {INT, "INT"},
    {END, "END"},
    {FLOAT, "FLOAT"},
    {BOOL, "BOOL"},

    {ELSE, "ELSE"},
    {IF, "IF"},

    {THEN, "THEN"},
    {TRUE, "TRUE"},
    {FALSE, "FALSE"},

    {IDENT, "IDENT"},

    {ICONST, "ICONST"},
    {RCONST, "RCONST"},
    {SCONST, "SCONST"},
    {BCONST, "BCONST"},

    {PLUS, "PLUS"},
    {MINUS, "MINUS"},
    {MULT, "MULT"},
    {DIV, "DIV"},
    {ASSOP, "ASSOP"},
    {EQUAL, "EQUAL"},
    {GTHAN, "GTHAN"},
    {LTHAN, "LTHAN"},
    {AND, "AND"},
    {OR, "OR"},
    {NOT, "NOT"},

    {COMMA, "COMMA"},
    {LPAREN, "LPAREN"},
    {RPAREN, "RPAREN"},

    {SEMICOL, "SEMICOL"},

    {ERR, "ERR"},

    {DONE, "DONE"},
};

map<string, Token> tokString = {
    {"PROGRAM", PROGRAM},
    {"PRINT", PRINT},
    {"INT", INT},
    {"END", END},
    {"FLOAT", FLOAT},
    {"BOOL", BOOL},

    {"ELSE", ELSE},
    {"IF", IF},

    {"THEN", THEN},
    {"TRUE", TRUE},
    {"FALSE", FALSE},

    {"IDENT", IDENT},

    {"ICONST", ICONST},
    {"RCONST", RCONST},
    {"SCONST", SCONST},
    {"BCONST", BCONST},

    {"PLUS", PLUS},
    {"MINUS", MINUS},
    {"MULT", MULT},
    {"DIV", DIV},
    {"ASSOP", ASSOP},
    {"EQUAL", EQUAL},
    {"GTHAN", GTHAN},
    {"LTHAN", LTHAN},
    {"AND", AND},
    {"OR", OR},
    {"NOT", NOT},

    {"COMMA", COMMA},
    {"LPAREN", LPAREN},
    {"RPAREN", RPAREN},

    {"SEMICOL", SEMICOL},

    {"ERR", ERR},

    {"DONE", DONE},
};

extern ostream &operator<<(ostream &out, const LexItem &tok)
{
    Token token = tok.GetToken();
    out << tokenPrint[token];

    if (token == IDENT || token == ICONST || token == RCONST || token == SCONST || token == BCONST)
    {
        out << '(' << tok.GetLexeme() << ')';
    }
    out << endl;
    return out;
}

LexItem id_or_kw(const string &lexeme, int linenum)
{
    map<string, Token>::iterator it;
    it = keyWords.find(lexeme);

    if (it != keyWords.end())
    {
        if (it->first == "TRUE" || it->first == "FALSE")
            return LexItem(BCONST, lexeme, linenum);
        else
            return LexItem(it->second, lexeme, linenum);
    }
    else
        return LexItem(IDENT, lexeme, linenum);
}

LexItem getNextToken(istream &in, int &linenum)
{
    enum TokState
    {
        START,
        INID,
        INSTRING,
        ININT,
        INREAL,
        INCOMMENT
    } lexstate = START;
    string lexeme;
    char ch;
    bool isRealFlag = false;
    bool isCommentFlag = false;

    while (in.get(ch))
    {
        switch (lexstate)
        {
        case START:
            if (ch == '\n')
                linenum++;

            if (isspace(ch))
                continue;

            lexeme = ch;
            if (isalpha(ch) || ch == '_')
            {
                lexeme = toupper(ch);
                lexstate = INID;
            }
            else if (ch == '/' && char(in.peek()) == '*')
            {
                in.get(ch);
                isCommentFlag = true;
                lexstate = INCOMMENT;
            }

            else if (ch == '"')
            {
                lexstate = INSTRING;
            }
            else if (isdigit(ch))
            {
                lexstate = ININT;
            }

            else
            {
                Token opToken = ERR;
                if (ch == '+')
                    opToken = PLUS;

                else if (ch == '-')
                    opToken = MINUS;

                else if (ch == '*')
                {
                    if (in.peek() == '/')
                    {
                        in.putback(ch);
                        lexstate = INCOMMENT;
                        continue;
                    }
                    else
                    {
                        opToken = MULT;
                    }
                }

                else if (ch == '/' && !isCommentFlag)
                {
                    return LexItem(DIV, lexeme, linenum);
                }

                else if (ch == '=')
                {
                    if (in.peek() == '=')
                    {
                        in.get(ch);
                        return LexItem(EQUAL, lexeme, linenum);
                        continue;
                    }
                    return LexItem(ASSOP, lexeme, linenum);
                }

                else if (ch == '(')
                    opToken = LPAREN;

                else if (ch == ')')
                    opToken = RPAREN;

                else if (ch == ';')
                    opToken = SEMICOL;

                else if (ch == ',')
                    opToken = COMMA;

                else if (ch == '<')
                    opToken = LTHAN;

                else if (ch == '>')
                    opToken = GTHAN;

                else if (ch == '!')
                    opToken = NOT;

                else if (ch == '&')
                {
                    if (in.peek() == '&')
                    {
                        opToken = AND;
                    }
                    else
                    {
                        opToken = ERR;
                        continue;
                    }
                }

                else if (ch == '|')
                {
                    if (in.peek() == '|')
                    {
                        opToken = OR;
                    }
                    else
                    {
                        opToken = ERR;
                        continue;
                    }
                }

                return LexItem(opToken, lexeme, linenum);
            }
            break;

        case INID:
            if (isalpha(ch) || isdigit(ch) || ch == '@' || ch == '_')
            {
                lexeme += toupper(ch);
            }
            else
            {
                in.putback(ch);
                return id_or_kw(lexeme, linenum);
            }
            break;

        case INSTRING:
            if (ch == '\n')
            {
                return LexItem(ERR, lexeme, linenum);
            }
            lexeme += ch;
            if (ch == '"')
            {
                lexeme = lexeme.substr(1, lexeme.length() - 2);
                return LexItem(SCONST, lexeme, linenum);
            }
            break;

        case ININT:
            if (isdigit(ch))
            {
                lexeme += ch;
            }
            else if (ch == '.')
            {
                lexeme += ch;
                isRealFlag = true;
                lexstate = INREAL;
            }
            else
            {
                in.putback(ch);
                return LexItem(ICONST, lexeme, linenum);
            }
            break;

        case INREAL:
            if (isdigit(ch))
            {
                lexeme += ch;
            }
            else if (lexeme.back() == '.' && isspace(ch))
            {
                return LexItem(ERR, lexeme, linenum);
            }

            else if (ch == '.' && isRealFlag)
            {
                lexeme += ch;
                return LexItem(ERR, lexeme, linenum);
            }
            else
            {
                in.putback(ch);
                return LexItem(RCONST, lexeme, linenum);
            }
            break;

        case INCOMMENT:
            if (ch == '\n')
                linenum++;

            if (ch == '*' && in.peek() == '/')
            {
                isCommentFlag = false;
                lexstate = START;
            }
            break;
        }
    }

    if (isCommentFlag)
    {
        return LexItem(DONE, "Missing a comment end delimiters '*/' at line ", linenum);
    }
    if (in.eof())
        return LexItem(DONE, "DONE", linenum);
    return LexItem(ERR, "I/O Error", linenum);
}
