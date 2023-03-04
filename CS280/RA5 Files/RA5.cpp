#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "lex.h"
using namespace std;

map<string, Token> kwmap = {
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

map<string, char> operators = {
    {"PLUS", '+'},
    {"MINUS", '-'},
    {"COMMA", ','},
    {"SEMICOL", ';'},
    {"ASSOP", '='},
    {"ERROR", '$'},
    {"RPAREN", ')'},
    {"LPAREN", '('}};

LexItem id_or_kw(const string &lexeme, int linenum)
{
    map<string, Token>::iterator it;
    it = kwmap.find(lexeme);
    if (it != kwmap.end())
        return LexItem(it->second, lexeme, linenum);
    else
        return LexItem(IDENT, lexeme, linenum);
}

ostream &operator<<(ostream &out, const LexItem &tok)
{
    string tokenString = tokenPrint[tok.GetToken()];
    map<string, Token>::iterator it = kwmap.find(tok.GetLexeme());

    if (tokenString == "SCONST")
    {
        out << tokenString << ": \"" << tok.GetLexeme() << "\" at Line ";
    }
    else if (tokenString == "ICONST" || tokenString == "RCONST" || tokenString == "BCONST")
    {
        out << tokenString << ": (" << tok.GetLexeme() << ") at Line ";
    }
    else if (tokenString == "ERR")
    {
        out << "Error: : \"" << tok.GetLexeme() << "\" at Line ";
    }
    else if (tokenString == "PLUS" || tokenString == "MINUS" || tokenString == "COMMA" || tokenString == "SEMICOL" || tokenString == "ASSOP" || tokenString == "ERROR" || tokenString == "RPAREN" || tokenString == "LPAREN")
    {
        out << tokenString << ": \'" << operators[tokenString] << "\' at Line ";
    }
    else if (it != kwmap.end())
    {
        out << "KEYWORD: " << tok.GetLexeme() << " at Line ";
    }
    else if (tokenString == "IDENT")
    {
        out << "IDENT: " << tok.GetLexeme() << " at Line ";
    }

    out << tok.GetLinenum() << endl;
    return out;
}
