/* Incomplete Implementation of Recursive-Descent Parser
 * parse.cpp
 * Programming Assignment 2
 * Fall 2021
 */

#include <bits/stdc++.h>

#include "parse.h"

// Comment the following line do disable debug messages
#define DEBUG

#ifdef DEBUG
unsigned int depth = 0;
#define ECHO(STR, LINE)                      \
    for (unsigned int i = 0; i < depth; i++) \
        cout << "|";                         \
    cout << STR << ": " << LINE << endl
#define INC depth++
#define DEC depth--
#else
#define ECHO(STR, LINE)
#define INC
#define DEC
#endif

stack<string> identStack;

map<string, bool> defVar;
map<string, Token> SymTable;

namespace Parser
{
    bool pushed_back = false;
    LexItem pushed_token;

    static LexItem GetNextToken(istream &in, int &line)
    {
        if (pushed_back)
        {
            pushed_back = false;
#ifdef DEBUG
            cout << pushed_token << endl;
#endif
            return pushed_token;
        }
        LexItem nextToken = getNextToken(in, line);
#ifdef DEBUG
        cout << nextToken << endl;
#endif
        return nextToken;
    }

    static void PushBackToken(LexItem &t)
    {
        if (pushed_back)
        {
            abort();
        }
        pushed_back = true;
        pushed_token = t;
    }

}

static int error_count = 0;

int ErrCount()
{
    return error_count;
}

void ParseError(int line, string msg)
{
    ++error_count;
    cout << line << ": " << msg << endl;
}

// Decl = Type IdentList
// Type = INTEGER | REAL | CHAR
bool DeclStmt(istream &in, int &line)
{
    bool status = false;
    LexItem tok;
    ECHO("in Decl", line);
    LexItem t = Parser::GetNextToken(in, line);

    if (t == INT || t == FLOAT)
    {

        INC;
        status = IdentList(in, line, t);
        DEC;

        while (!identStack.empty())
        {
            if (SymTable.find(identStack.top()) != SymTable.end())
            {
                ParseError(line, "Redeclaration of variable");
                return false;
            }
            SymTable.insert(pair<string, Token>(identStack.top(), t.GetToken()));
            identStack.pop();
        }

        // cout<< "returning from IdentList" << " " << (status? 1: 0) << endl;
        if (!status)
        {
            ParseError(line, "Incorrect variable in Declaration Statement.");
            return status;
        }
    }
    else
    {
        Parser::PushBackToken(t);
        ParseError(line, "Incorrect Type.");
        return false;
    }
    return true;
}

bool Stmt(istream &in, int &line)
{
    bool status = true;
    ECHO("in Stmt", line);
    LexItem t = Parser::GetNextToken(in, line);

    switch (t.GetToken())
    {
    case INT:
    case FLOAT:
        Parser::PushBackToken(t);

        INC;
        status = DeclStmt(in, line);
        DEC;

        if (!status)
        {
            ParseError(line, "Incorrect Declaration Statement.");
            return status;
        }
        break;
    case IF:
    case WRITE:
    case IDENT:
        Parser::PushBackToken(t);

        INC;
        status = ControlStmt(in, line);
        DEC;

        if (!status)
        {
            ParseError(line, "Incorrect control Statement.");
            return status;
        }
        break;
    default:
        Parser::PushBackToken(t);
    }
    return status;
}

// WriteStmt:= wi, ExpreList
bool WriteStmt(istream &in, int &line)
{
    LexItem t;
    ECHO("in WriteStmt", line);

    INC;
    bool ex = ExprList(in, line);
    DEC;

    if (!ex)
    {
        ParseError(line, "Missing expression after Write");
        return false;
    }

    // Evaluate: print out the list of expressions values

    return ex;
}

bool StmtList(istream &in, int &line)
{
    ECHO("in StmtList", line);
    bool status = true;
    LexItem t;
    t = Parser::GetNextToken(in, line);

    while (t.GetToken() != END)
    {
        Parser::PushBackToken(t);

        INC;
        status = Stmt(in, line);
        DEC;

        if (!status)
        {

            return status;
        }

        t = Parser::GetNextToken(in, line);
        if (t.GetToken() == PROGRAM)
        {
            Parser::PushBackToken(t);
            ParseError(line, "Missing END at end of program.");
            return false;
        }
        if (t.GetToken() != SEMICOL)
        {
            ParseError(line, "Missing a semicolon.");
            return false;
        }
        t = Parser::GetNextToken(in, line);
    }

    Parser::PushBackToken(t);

    return status;
}

bool ControlStmt(istream &in, int &line)
{
    ECHO("in ControlStmt", line);
    bool status = true;
    LexItem t;
    t = Parser::GetNextToken(in, line);

    INC;
    if (t.GetToken() == IF)
    {
        status = IfStmt(in, line);
    }
    else if (t.GetToken() == WRITE)
    {
        status = WriteStmt(in, line);
    }
    else
    {
        Parser::PushBackToken(t);
        status = AssignStmt(in, line);
    }
    DEC;

    return status;
}

bool IfStmt(istream &in, int &line)
{
    ECHO("in IfStmt", line);
    bool status = true;
    LexItem t;
    t = Parser::GetNextToken(in, line);

    if (t.GetToken() != LPAREN)
    {
        ParseError(line, "Parentesis missing");
        return false;
    }

    INC;
    status = LogicExpr(in, line);
    DEC;

    t = Parser::GetNextToken(in, line);

    if (t.GetToken() != RPAREN)
    {
        ParseError(line, "Parentesis missing");
        return false;
    }

    INC;
    status = ControlStmt(in, line);
    DEC;

    return status;
}

bool IdentList(istream &in, int &line, LexItem tok)
{
    ECHO("in IdentList", line);
    LexItem t;

label:
    t = Parser::GetNextToken(in, line);
    if (t.GetToken() != IDENT)
    {
        ParseError(line, "Unexpected Token");
        return false;
    }

    identStack.push(t.GetLexeme());
    t = Parser::GetNextToken(in, line);
    if (t.GetToken() == COMMA)
        goto label;

    // TERMINAL

    Parser::PushBackToken(t);
    return true;
}

bool Var(istream &in, int &line)
{
    ECHO("in Var", line);
    LexItem t;
    t = Parser::GetNextToken(in, line);

    if (t.GetToken() != IDENT)
    {
        ParseError(line, "Unexpected token");
        return false;
    }

    if (SymTable.find(t.GetLexeme()) == SymTable.end())
    {
        ParseError(line, "Undeclared variable");
        return false;
    }

    return true;
}

bool AssignStmt(istream &in, int &line)
{
    ECHO("in AssignStmt", line);
    bool status = true;
    LexItem t;

    INC;
    status = Var(in, line);
    DEC;
    t = Parser::GetNextToken(in, line);
    if (t.GetToken() != ASSOP)
    {
        ParseError(line, "Unexpected token");
        return false;
    }

    INC;
    status = Expr(in, line);
    DEC;

    if (!status)
    {
        ParseError(line, "Missing Expression in Assignment Statment");
        return status;
    }

    return status;
}

bool ExprList(istream &in, int &line)
{
    ECHO("in ExprList", line);
    LexItem t;
    bool status = true;

label:
    INC;
    status = Expr(in, line);
    DEC;
    t = Parser::GetNextToken(in, line);

    if (t.GetToken() == COMMA)
        goto label;

    Parser::PushBackToken(t);

    return status;
}

bool LogicExpr(istream &in, int &line)
{
    ECHO("in LogicExpr", line);
    LexItem t;
    bool status = true;

    INC;
    status = Expr(in, line);
    DEC;

    t = Parser::GetNextToken(in, line);
    if (!(t.GetToken() == EQUAL || t.GetToken() == GTHAN))
    {
        ParseError(line, "Unexpected token");
        return false;
    }

    INC;
    status = Expr(in, line);
    DEC;

    return status;
}

bool Expr(istream &in, int &line)
{
    ECHO("in Expr", line);
    LexItem t;
    bool status = true;

    INC;
    status = Term(in, line);
    DEC;

    t = Parser::GetNextToken(in, line);
    if (t.GetToken() == PLUS || t.GetToken() == MINUS)
    {
    label:
        INC;
        status = Term(in, line);
        DEC;
    }
    else
    {
        Parser::PushBackToken(t);
    }
    t = Parser::GetNextToken(in, line);
    if (t.GetToken() == PLUS || t.GetToken() == MINUS)
        goto label;
    else
        Parser::PushBackToken(t);

    return status;
}

bool Term(istream &in, int &line)
{
    ECHO("in Term", line);
    LexItem t;
    bool status = true;

    INC;
    status = SFactor(in, line);
    DEC;

    t = Parser::GetNextToken(in, line);
    if (t.GetToken() == MULT || t.GetToken() == DIV || t.GetToken() == REM)
    {
    label:
        INC;
        status = SFactor(in, line);
        DEC;
    }
    else
    {
        Parser::PushBackToken(t);
    }
    t = Parser::GetNextToken(in, line);
    if (t.GetToken() == MULT || t.GetToken() == DIV || t.GetToken() == REM)
        goto label;
    else
        Parser::PushBackToken(t);

    return status;
}

bool SFactor(istream &in, int &line)
{
    ECHO("in SFactor", line);
    LexItem t;
    bool status = true;

    t = Parser::GetNextToken(in, line);
    if (!(t.GetToken() == PLUS || t.GetToken() == MINUS))
        Parser::PushBackToken(t);

    INC;
    status = Factor(in, line, true);
    DEC;

    return status;
}

bool Factor(istream &in, int &line, int sign)
{
    ECHO("in Factor", line);
    LexItem t;
    bool status = true;

    t = Parser::GetNextToken(in, line);
    switch (t.GetToken())
    {
    case IDENT:
        if (SymTable.find(t.GetLexeme()) == SymTable.end())
        {
            ParseError(line, "Undeclared variable");
            return false;
        }
    case ICONST:
    case RCONST:
    case SCONST:
        return true;
    case LPAREN:
        INC;
        status = Expr(in, line);
        DEC;
        t = Parser::GetNextToken(in, line);
        if (t.GetToken() != RPAREN)
        {
            ParseError(line, "Missing ) after expression");
            return false;
        }
        break;
    default:
        ParseError(line, "Unexpected token");
        return false;
    }

    return status;
}

bool Prog(istream &in, int &line)
{
    ECHO("in Prog", line);
    LexItem t;
    bool status = true;

    t = Parser::GetNextToken(in, line);
    if (t.GetToken() == DONE)
    {
        ParseError(line, "Empty File");
        return false;
    }

    if (t.GetToken() != PROGRAM)
    {
        ParseError(line, "Missing PROGRAM.");
        return false;
    }

    t = Parser::GetNextToken(in, line);
    if (t.GetToken() != IDENT)
    {
        ParseError(line, "Missing Program Name.");
        return false;
    }

    INC;
    status = StmtList(in, line);
    DEC;

    if (!status)
    {
        ParseError(line, "Missing END of Program");
        return status;
    }

    t = Parser::GetNextToken(in, line);
    if (t.GetToken() != END)
    {
        ParseError(line, "Incorrect Syntax in the Program");
        return false;
    }

    t = Parser::GetNextToken(in, line);
    if (t.GetToken() != PROGRAM)
    {
        ParseError(line, "Missing PROGRAM at the End");
        return false;
    }

    return status;
}
