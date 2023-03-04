#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
    int lines = 0;
    int comments = 0;
    int validCom = 0;
    int invalidCom = 0;
    int runCom = 0;
    int printCom = 0;
    int copyCom = 0;
    int delCom = 0;
    string line;
    ifstream inFile;
    string fileName;

    cout << "Enter the name of a file to read from:" << endl
         << endl;
    cin >> fileName;

    inFile.open(fileName.c_str());
    if (!inFile)
    {
        cerr << "File cannot be opened"
             << " " << fileName << endl;
        exit(1);
    }

    while (!inFile.eof())
    {
        getline(inFile, line);
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        lines += 1;
        if (line[0] == '%')
        {
            comments += 1;
        }
        else if (line.substr(0, 3) == "run")
        {
            validCom += 1;
            runCom += 1;
        }
        else if (line.substr(0, 5) == "print")
        {
            validCom += 1;
            printCom += 1;
        }
        else if (line.substr(0, 4) == "copy")
        {
            validCom += 1;
            copyCom += 1;
        }
        else if (line.substr(0, 6) == "delete")
        {
            validCom += 1;
            delCom += 1;
        }
        else if (line[0] == '\t')
        {
            continue;
        }
        else
        {
            if (line.substr(0, 6) != "delete" || line.substr(0, 4) != "copy" || line.substr(0, 5) != "print" || line.substr(0, 3) != "run")
            {
                if (line.empty())
                {
                    continue;
                }
                cout << "Error: Unrecognizable command in line " << lines << endl
                     << endl;
                invalidCom += 1;
            }
        }
    }

    cout << "Total lines: " << lines - 1 << endl;
    cout << "Commented lines: " << comments << endl;
    cout << "Valid Command lines: " << validCom << endl;
    cout << "Invalid Command lines: " << invalidCom << endl;
    cout << "Run commands: " << runCom << endl;
    cout << "Print commands: " << printCom << endl;
    cout << "Copy commands: " << copyCom << endl;
    cout << "Delete commands: " << delCom << endl;
}