#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    int numLines = 0, nonBlank = 0, numWords = 0, numInts = 0, numNames = 0;
    string filename = "";
    string flag = "";
    string line;
    ifstream inFile;

    if (argc >= 2)
    {
        inFile.open(argv[1]);
        if (!inFile.is_open())
        {
            cerr << "CANNOT OPEN THE FILE " << argv[1] << endl;
            exit(1);
        }
    }
    else
    {
        cerr << "NO SPECIFIED INPUT FILE NAME." << endl;
        exit(1);
    }

    for (int i = 2; i < argc; ++i)
    {
        flag = argv[i];
    }

    string word;
    bool isName = true;
    bool isDigit = true;

    while (getline(inFile, line))
    {
        numLines++;
        istringstream iss(line);

        int lineWords = 0;

        while (iss >> word)
        {
            numWords++;
            lineWords++;
            // Check if valid name
            if (isalpha(word[0]) || word[0] == '_')
            {
                isName = true;
                for (char character : word)
                {

                    if (!isalpha(character) && !isdigit(character) && character != '_' && character != '@')
                    {
                        isName = false;
                    }
                }
                if (isName)
                {
                    numNames++;
                }
            }

            // Check if valid int
            if (isdigit(word[0]))
            {
                isDigit = true;
                for (int i = 0; i < word.length(); i++)
                {
                    if (!isdigit(word[i]))
                    {
                        // cout << "Invalid: " << word << endl;
                        isDigit = false;
                    }
                }
                if (isDigit)
                {
                    numInts++;
                }
            }

            if (word[0] == '+' || word[0] == '-')
            {
                isDigit = true;
                if (word.length() == 1)
                {
                    isDigit = false;
                }
                else
                {
                    for (int i = 1; i < word.length(); i++)
                    {
                        if (!isdigit(word[i]))
                        {
                            isDigit = false;
                        }
                    }
                    if (isDigit)
                    {
                        numInts++;
                    }
                }
            }
        }
        if (lineWords != 0)
        {
            nonBlank++;
        }
    }

    if (numLines == 0)
    {
        cout << "File is empty." << endl;
        exit(1);
    }

    // Print out results
    if (flag == "-all")
    {
        cout << "Total Number of Lines: " << numLines << endl;
        cout << "Number of non-blank lines: " << nonBlank << endl;
        cout << "Number of Words: " << numWords << endl;
        cout << "Number of Integers: " << numInts << endl;
        cout << "Number of Names: " << numNames << endl;
    }
    else if (flag == "-ints")
    {
        cout << "Total Number of Lines: " << numLines << endl;
        cout << "Number of non-blank lines: " << nonBlank << endl;
        cout << "Number of Words: " << numWords << endl;
        cout << "Number of Integers: " << numInts << endl;
    }
    else if (flag == "-names")
    {
        cout << "Total Number of Lines: " << numLines << endl;
        cout << "Number of non-blank lines: " << nonBlank << endl;
        cout << "Number of Words: " << numWords << endl;
        cout << "Number of Names: " << numNames << endl;
    }
    else if (flag == "")
    {
        cout << "Total Number of Lines: " << numLines << endl;
        cout << "Number of non-blank lines: " << nonBlank << endl;
        cout << "Number of Words: " << numWords << endl;
    }
    else //((flag != "-all") || (flag != "-ints") || (flag != "-names"))
    {
        cout << "UNRECOGNIZED FLAG " << flag << endl;
    }
    return 0;
}