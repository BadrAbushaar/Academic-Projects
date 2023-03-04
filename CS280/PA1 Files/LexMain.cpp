#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "lex.h"
using namespace std;

map<string, int> identMap;
map<int, int> iconstMap;
map<string, int> rconstMap;
map<string, int> sconstMap;
map<string, int> bconstMap;

int main(int argc, char *argv[])
{
    int lineNumber = 0;
    int tokenNumber = 0;
    bool vflag = false;
    bool iconstflag = false;
    bool rconstflag = false;
    bool sconstflag = false;
    bool bconstflag = false;
    bool identflag = false;
    LexItem tok;
    ifstream file;

    // File cannot open
    if (argc >= 2)
    {
        file.open(argv[1]);
        if (!file.is_open())
        {
            cerr << "CANNOT OPEN THE FILE " << argv[1] << endl;
            exit(1);
        }
    }
    // No filename provided
    else
    {
        cerr << "NO SPECIFIED INPUT FILE NAME." << endl;
        exit(1);
    }

    for (int i = 2; i < argc; i++)
    {
        string arg(argv[i]);
        if (arg[0] != '-')
        {
            cerr << "ONLY ONE FILE NAME ALLOWED." << endl;
            exit(1);
        }
        else if (arg == "-v")
        {
            vflag = true;
        }
        else if (arg == "-iconst")
        {
            iconstflag = true;
        }
        else if (arg == "-rconst")
        {
            rconstflag = true;
        }
        else if (arg == "-bconst")
        {
            bconstflag = true;
        }
        else if (arg == "-sconst")
        {
            sconstflag = true;
        }
        else if (arg == "-ident")
        {
            identflag = true;
        }
        else if (arg[0] == '-')
        {
            cerr << "UNRECOGNIZED FLAG " << arg << endl;
            exit(1);
        }
    }

    while ((tok = getNextToken(file, lineNumber)) != DONE && tok != ERR)
    {
        tokenNumber++;
        if (tok.GetToken() == ICONST)
        {
            iconstMap[stoi(tok.GetLexeme())]++;
        }
        if (tok.GetToken() == RCONST)
        {
            rconstMap[tok.GetLexeme()]++;
        }
        if (tok.GetToken() == SCONST)
        {
            sconstMap[tok.GetLexeme()]++;
        }
        if (tok.GetToken() == BCONST)
        {
            bconstMap[tok.GetLexeme()]++;
        }
        if (tok.GetToken() == IDENT)
        {
            identMap[tok.GetLexeme()]++;
        }

        if (vflag)
        {
            cout << tok;
        }
    }

    if (lineNumber == 0 && tok.GetToken() != ERR)
    {
        cout << "Lines: " << lineNumber << endl;
        exit(1);
    }

    if (tok.GetToken() == ERR)
    {
        cout << "Error in line " << lineNumber + 1 << " (" << tok.GetLexeme() << ")";
        cout << endl;
    }

    if (tok.GetToken() == DONE)
    {
        if (tok.GetLexeme() != "DONE")
        {
            cout << endl
                 << tok.GetLexeme() << tok.GetLinenum() << endl;
        }

        cout << "Lines: " << tok.GetLinenum() << endl;
        if (lineNumber != 0)
        {
            cout << "Tokens: " << tokenNumber << endl;
        }

        if (sconstflag)
        {
            // if present, prints out all the unique string constants in alphabetical order
            map<string, int>::iterator it;
            cout << "STRINGS:" << endl;
            for (it = sconstMap.begin(); it != sconstMap.end(); it++)
            {
                cout << '"' << it->first << '"' << endl;
            }
        }

        if (iconstflag)
        {
            // if present, prints out all the unique integer constants in numeric order.
            map<int, int>::iterator it;
            cout << "INTEGERS:" << endl;
            for (it = iconstMap.begin(); it != iconstMap.end(); it++)
            {
                cout << it->first << endl;
            }
        }

        if (rconstflag)
        {
            // if present, prints out all the unique real constants in numeric order
            map<string, int>::iterator it;
            cout << "REALS:" << endl;
            for (it = rconstMap.begin(); it != rconstMap.end(); it++)
            {
                cout << it->first << endl;
            }
        }

        if (bconstflag)
        {
            // if present, prints out all of the Boolean constants in order.
            map<string, int>::iterator it;
            if (!bconstMap.empty())
            {
                cout << "Booleans:" << endl;
                for (it = bconstMap.begin(); it != bconstMap.end(); it++)
                {
                    cout << it->first << endl;
                }
            }
        }

        if (identflag)
        {
            // if present, prints out all of the unique identifiers in alphabetical order.
            map<string, int>::iterator it;
            cout << "IDENTIFIERS:" << endl;
            for (it = identMap.begin(); it != identMap.end(); it++)
            {
                if (it != identMap.begin())
                {
                    cout << ", " << it->first;
                }
                else
                {
                    cout << it->first;
                }
            }
            cout << endl;
        }
    }

    return 0;
}