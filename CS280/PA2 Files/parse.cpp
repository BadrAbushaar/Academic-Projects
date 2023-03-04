/* Implementation of Recursive-Descent Parser
 * parse.cpp
 * Programming Assignment 2
 * Fall 2022
 */

#include "parse.h"

map<string, bool> defVar;

namespace Parser
{
	bool pushed_back = false;
	LexItem pushed_token;

	static LexItem GetNextToken(istream &in, int &line)
	{
		if (pushed_back)
		{
			pushed_back = false;
			return pushed_token;
		}
		return getNextToken(in, line);
	}

	static void PushBackToken(LexItem &t)
	{
		if (pushed_back)
		{
			cout << "DOUBLE PUSHBACK" << endl;
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

bool IdentList(istream &in, int &line);

// Prog ::= PROGRAM IDENT StmtList END PROGRAM
bool Prog(istream &in, int &line)
{
	cout << "HIT PROG" << line << endl;
	bool status = false;
	LexItem t = Parser::GetNextToken(in, line);
	if (t != PROGRAM)
	{
		ParseError(line, "Missing PROGRAM.");
		return false;
	}

	t = Parser::GetNextToken(in, line);
	if (t != IDENT)
	{
		ParseError(line, "Missing Program Name.");
		return false;
	}

	status = StmtList(in, line);
	if (!status)
	{
		ParseError(line, "Incorrect StmtList");
		return false;
	}

	cout << "LOOKING FOR END" << endl;
	t = Parser::GetNextToken(in, line);
	if (t != END)
	{
		ParseError(line, "Missing END.");
		return false;
	}

	cout << "LOOKING FOR PROGRAM" << endl;
	t = Parser::GetNextToken(in, line);
	if (t != PROGRAM)
	{
		ParseError(line, "Missing ending PROGRAM.");
		return false;
	}

	return status;

} // End of Prog

// StmtList ::= Stmt; { Stmt; }
bool StmtList(istream &in, int &line)
{
	cout << "HIT STMTLIST" << line << endl;
	bool status = false;
	status = Stmt(in, line);
	if (!status)
	{
		ParseError(line, "Syntactic error in program body.");
		return false;
	}

	LexItem t = Parser::GetNextToken(in, line);

	if (t == SEMICOL)
	{
		cout << "HIT A SEMICOL" << endl;
		t = Parser::GetNextToken(in, line);

		if (t == END || t == ELSE)
		{
			return true;
		}
		else
		{
			Parser::PushBackToken(t);
			status = StmtList(in, line);
		}
	}
	else
	{

		ParseError(line, "Missing semicolon.");
		return false;
	}

	return status;
} // End of StmtList

// Stmt ::= DeclStmt | ControlStmt
bool Stmt(istream &in, int &line)
{
	cout << "HIT STMT" << line << endl;
	bool status = false;
	LexItem t = Parser::GetNextToken(in, line);
	cout << "STMT" << endl;
	cout << "TOKEN: " << t.GetToken() << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;
	switch (t.GetToken())
	{
	case INT:
		cout << "HIT STMT INT" << endl;
		Parser::PushBackToken(t);
		status = DeclStmt(in, line);
		break;
	case FLOAT:
		cout << "HIT STMT FLOAT" << endl;
		Parser::PushBackToken(t);
		status = DeclStmt(in, line);
		break;
	case BOOL:
		cout << "HIT STMT BOOL" << endl;
		Parser::PushBackToken(t);
		status = DeclStmt(in, line);
		break;
	case PRINT:
		cout << "HIT STMT PRINT" << endl;
		Parser::PushBackToken(t);
		status = ControlStmt(in, line);
		break;
	case IF:
		cout << "HIT STMT IF" << endl;
		Parser::PushBackToken(t);
		status = ControlStmt(in, line);
		break;
	case IDENT:
		cout << "HIT STMT IDENT" << endl;
		Parser::PushBackToken(t);
		status = ControlStmt(in, line);
		break;
	default:
		ParseError(line, "Invalid declaration or control statement.");
		return false;
	}

	return status;
} // End of stmt

// DeclStmt ::= ( INT | FLOAT | BOOL ) VarList
bool DeclStmt(istream &in, int &line)
{
	cout << "HIT DECLSTMT" << line << endl;
	bool status = false;
	LexItem t = Parser::GetNextToken(in, line);
	switch (t.GetToken())
	{
	case INT:
		status = VarList(in, line);
	case FLOAT:
		status = VarList(in, line);
	case BOOL:
		status = VarList(in, line);
	default:
		ParseError(line, "Incorrect variable in declaration statement");
		return false;
	}

	return status;
} // End of DeclStmt

// ControlStmt ::= AssigStmt | IfStmt | PrintStmt
bool ControlStmt(istream &in, int &line)
{
	cout << "HIT CNTRLSTMT" << line << endl;
	bool status;

	LexItem t = Parser::GetNextToken(in, line);

	switch (t.GetToken())
	{

	case PRINT:
		status = PrintStmt(in, line);
		break;

	case IF:
		Parser::PushBackToken(t);
		status = IfStmt(in, line);
		break;

	case IDENT:
		Parser::PushBackToken(t);
		status = AssignStmt(in, line);
		break;

	default:
		Parser::PushBackToken(t);
		return false;
	}

	return status;
} // End of ControlStmt

// PrintStmt:= PRINT (ExprList)
bool PrintStmt(istream &in, int &line)
{
	cout << "HIT PRINTSTMT" << line << endl;
	LexItem t = Parser::GetNextToken(in, line);
	if (t != LPAREN)
	{

		ParseError(line, "Missing Left Parenthesis");
		return false;
	}

	bool ex = ExprList(in, line);

	if (!ex)
	{
		ParseError(line, "Missing expression list after Print");
		return false;
	}

	t = Parser::GetNextToken(in, line);
	if (t != RPAREN)
	{

		ParseError(line, "Missing Right Parenthesis");
		return false;
	}
	return ex;
} // End of PrintStmt

// IfStmt ::= IF (Expr) THEN StmtList [ ELSE StmtList ] END IF
bool IfStmt(istream &in, int &line)
{
	cout << "HIT IFSTMT" << line << endl;
	LexItem t = Parser::GetNextToken(in, line);
	cout << "TOKEN: " << t << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;
	cout << "CHECKIGN FIRST IF HERE" << endl;
	if (t != IF)
	{
		ParseError(line, "Missing IF.");
		return false;
	}

	bool status = Expr(in, line);
	if (!status)
	{
		ParseError(line, "Missing Expression.");
		return false;
	}
	t = Parser::GetNextToken(in, line);
	cout << "TOKEN: " << t << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;
	cout << "CHECKING THEN HERE" << endl;
	if (t != THEN)
	{
		ParseError(line, "Missing THEN");
		return false;
	}

	status = StmtList(in, line);
	if (!status)
	{
		ParseError(line, "Missing StmtList.");
		return false;
	}

	t = Parser::GetNextToken(in, line);
	cout << "TOKEN: " << t << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;
	cout << "CHECKING ELSE HERE" << endl;
	if (t == ELSE)
	{
		status = StmtList(in, line);
		if (!status)
		{
			ParseError(line, "Missing StmtList in ELSE.");
			return false;
		}
	}
	else
	{
		Parser::PushBackToken(t);
	}

	t = Parser::GetNextToken(in, line);
	cout << "TOKEN: " << t << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;
	cout << "CHECKING END HERE" << endl;
	// if (t != END)
	// {
	// 	ParseError(line, "Missing END for IF");
	// 	return false;
	// }
	cout << "TOKEN: " << t << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;
	cout << "CHECKING IF HERE" << endl;
	if (t != IF)
	{
		ParseError(line, "Missing ending IF");
		return false;
	}

	return status;
} // End of ifStmt

// AssignStmt ::= Var = Expr
bool AssignStmt(istream &in, int &line)
{
	cout << "HIT ASSIGNSTMT" << line << endl;
	bool status = false;
	status = Var(in, line);
	if (!status)
	{
		ParseError(line, "Invalid Variable.");
		return false;
	}

	LexItem t = Parser::GetNextToken(in, line);
	if (t != ASSOP)
	{
		ParseError(line, "Missing Assignment Operator.");
		return false;
	}

	status = Expr(in, line);
	if (!status)
	{
		ParseError(line, "Missing expression in assignment statement.");
		return false;
	}

	return status;
} // End of AssignStmt

// VarList ::= Var { ,Var }
bool VarList(istream &in, int &line)
{

	cout << "HIT VARLIST" << line << endl;

	bool status = false;
	status = Var(in, line);
	if (!status)
	{
		ParseError(line, "Invalid Variable.");
		return false;
	}

	LexItem t = Parser::GetNextToken(in, line);
	if (t == COMMA)
	{
		cout << "HIT A COMMA" << endl;
		status = VarList(in, line);
	}
	else if (t == SEMICOL)
	{
		status = StmtList(in, line);
	}
	else if (t == ERR)
	{
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << t.GetLexeme() << ")" << endl;
		return false;
	}
	else
	{
		cout << "PUSING BACK IN VARLIST" << endl;
		Parser::PushBackToken(t);
		return true;
	}
	return status;
} // End of varList

// Var ::= IDENT
bool Var(istream &in, int &line)
{
	cout << "HIT VAR" << line << endl;

	LexItem t = Parser::GetNextToken(in, line);
	if (t == IDENT)
	{
		auto it = defVar.find(t.GetLexeme());
		if (it == defVar.end())
		{
			// not found
			it->second = true;
			return true;
		}
		else
		{
			ParseError(line, "Variable already declared");
			return false;
		}
	}
	else
	{
		ParseError(line, "Invalid variable.");
		return false;
	}

} // End of var

// ExprList:= Expr {,Expr}
bool ExprList(istream &in, int &line)
{
	cout << "HIT EXPRLIST" << line << endl;
	bool status = Expr(in, line);
	if (!status)
	{
		ParseError(line, "Missing Expression");
		return false;
	}

	LexItem tok = Parser::GetNextToken(in, line);

	if (tok == COMMA)
	{
		status = ExprList(in, line);
	}
	else if (tok == ERR)
	{
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << tok.GetLexeme() << ")" << endl;
		return false;
	}
	else
	{
		Parser::PushBackToken(tok);
		return true;
	}
	return status;
} // End of ExprList

// Expr ::= LogANDExpr { || LogANDRxpr }
bool Expr(istream &in, int &line)
{
	cout << "HIT EXPR" << line << endl;
	bool status = false;
	status = LogANDExpr(in, line);

	if (!status)
	{
		ParseError(line, "Missing AND Expression");
		return false;
	}

	LexItem t = Parser::GetNextToken(in, line);
	if (t == OR)
	{
		status = LogANDExpr(in, line);
	}
	else
	{
		Parser::PushBackToken(t);
		return true;
	}

	return status;
} // End of Expr

// LogANDExpr ::= EqualExpr { && EqualExpr }
bool LogANDExpr(istream &in, int &line)
{
	cout << "HIT LOGAND" << line << endl;
	bool status = false;
	status = EqualExpr(in, line);
	if (!status)
	{
		ParseError(line, "Missing EqualExpr.");
		return false;
	}

	LexItem t = Parser::GetNextToken(in, line);
	if (t == AND)
	{
		status = LogANDExpr(in, line);
	}
	else if (t == ERR)
	{
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << t.GetLexeme() << ")" << endl;
		return false;
	}
	else
	{
		Parser::PushBackToken(t);
		return true;
	}

	return status;
} // End of LogANDExpr

// EqualExpr ::= RelExpr [== RelExpr ]
bool EqualExpr(istream &in, int &line)
{
	cout << "HIT EQUALEXPR" << line << endl;
	bool status = false;
	status = RelExpr(in, line);
	if (!status)
	{
		ParseError(line, "Missing RelExpr.");
		return false;
	}

	LexItem t = Parser::GetNextToken(in, line);
	if (t == EQUAL)
	{
		status = RelExpr(in, line);
	}
	else if (t == ERR)
	{
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << t.GetLexeme() << ")" << endl;
		return false;
	}
	else
	{
		Parser::PushBackToken(t);
		return true;
	}

	return status;
} // End of EqualExpr

// RelExpr ::= AddExpr [ ( < | > ) AddExpr ]
bool RelExpr(istream &in, int &line)
{
	cout << "HIT RELEXPR" << line << endl;
	bool status = false;
	status = AddExpr(in, line);
	if (!status)
	{
		ParseError(line, "Missing AddExpr.");
		return false;
	}

	LexItem t = Parser::GetNextToken(in, line);
	cout << "REL" << endl;
	cout << "TOKEN: " << t << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;
	if (t == GTHAN || t == LTHAN)
	{
		status = AddExpr(in, line);
	}
	else
	{
		Parser::PushBackToken(t);
		return true;
	}

	return status;
} // End of RelExpr

// AddExpr :: MultExpr { ( + | - ) MultExpr }
bool AddExpr(istream &in, int &line)
{
	cout << "HIT ADDEXPR" << line << endl;
	bool status = false;
	status = MultExpr(in, line);

	if (!status)
	{
		ParseError(line, "Missing MultExpr.");
		return false;
	}

	LexItem t = Parser::GetNextToken(in, line);
	cout << "ADD" << endl;
	cout << "TOKEN: " << t << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;
	if (t == PLUS || t == MINUS)
	{
		status = AddExpr(in, line);
	}
	else
	{
		Parser::PushBackToken(t);
		return true;
	}

	return status;
} // End of AddExpr

// MultExpr ::= UnaryExpr { ( * | / ) UnaryExpr }
bool MultExpr(istream &in, int &line)
{
	cout << "HIT MULTEXPR" << line << endl;
	bool status = false;
	status = UnaryExpr(in, line);

	if (!status)
	{
		ParseError(line, "Missing UnaryExpr.");
		return false;
	}

	LexItem t = Parser::GetNextToken(in, line);
	cout << "MULT" << endl;
	cout << "TOKEN: " << t << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;
	if (t == MULT || t == DIV)
	{
		status = MultExpr(in, line);
	}
	else
	{
		Parser::PushBackToken(t);
		return true;
	}
	return status;
} // End of MultExpr

// UnaryExpr ::= ( - | + | ! ) PrimaryExpr | PrimaryExpr
bool UnaryExpr(istream &in, int &line)
{
	cout << "HIT UNARY" << line << endl;
	bool status = false;
	LexItem t = Parser::GetNextToken(in, line);
	cout << "UNARY" << endl;
	cout << "TOKEN: " << t << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;
	if (t == MINUS || t == NOT)
	{
		status = PrimaryExpr(in, line, -1);
	}
	else if (t == PLUS)
	{
		status = PrimaryExpr(in, line, 1);
	}
	else
	{
		Parser::PushBackToken(t);
		status = PrimaryExpr(in, line, 1);
	}

	return status;
} // End of UnaryExpr

// PrimaryExpr ::= IDENT | ICONST | RCONST | SCONST | BCONST | ( Expr )
bool PrimaryExpr(istream &in, int &line, int sign)
{
	cout << "HIT PRIMARY" << line << endl;
	bool status = false;
	LexItem t = Parser::GetNextToken(in, line);
	cout << "TOKEN: " << t << endl;
	cout << "LEXEME: " << t.GetLexeme() << endl;

	if (t == IDENT || t == ICONST || t == RCONST || t == SCONST || t == BCONST)
	{
		if (t == IDENT)
		{
			if (!(defVar.find(t.GetLexeme())->second))
			{
				ParseError(line, "Using Undefined Variable");
				return false;
			}
		}
		return true;
	}
	else if (t == LPAREN)
	{
		status = Expr(in, line);
		if (!status)
		{
			ParseError(line, "Missing Expression in PrimaryExpr.");
			return false;
		}
		else
		{
			t = Parser::GetNextToken(in, line);
			if (t != RPAREN)
			{
				ParseError(line, "Missing right parenthesis");
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else if (t == ERR)
	{
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << t.GetLexeme() << ")" << endl;
		return false;
	}
	else
	{
		Parser::PushBackToken(t);
		return false;
	}

	return status;
} // End of Prima
