#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <regex>
using namespace std;

int main(int argc, char *argv[])
{
    int numLines = 0, numWords = 0, noVowel = 0, oneVowel = 0, twoVowel = 0, manyVowel = 0;
    ifstream inFile;
    string word;
    string line;
    bool emptyFile = false;

    // File cannot open
    if (argc >= 2)
    {
        inFile.open(argv[1]);
        if (!inFile.is_open())
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

    map<string, map<string, int>> vowelMap;
    map<string, int>::iterator it;
    regex rx("[aeiouAEIOU]");

    while (getline(inFile, line))
    {
        numLines++;
        istringstream iss(line);
        while (iss >> word)
        {
            numWords++;
            int wordVowels = 0;
            auto wordBegin = sregex_iterator(word.begin(), word.end(), rx);
            auto wordEnd = sregex_iterator();
            wordVowels = distance(wordBegin, wordEnd);

            if (wordVowels == 0)
            {
                vowelMap["noVowel"][word]++;
                noVowel++;
            }
            else if (wordVowels == 1)
            {
                vowelMap["oneVowel"][word]++;
                oneVowel++;
            }
            else if (wordVowels == 2)
            {
                vowelMap["twoVowel"][word]++;
                twoVowel++;
            }
            else if (wordVowels >= 3)
            {
                vowelMap["manyVowel"][word]++;
                manyVowel++;
            }
        }
    }

    // File is empty
    if (numLines == 0)
    {
        emptyFile = true;
        cout << "File is empty." << endl;
        exit(1);
    }

    if (!emptyFile)
    {
        cout << "Number of words in the file: " << numWords << endl;
        cout << "Number of words with no vowels in the file: " << noVowel << endl;
        cout << "Number of words with one vowel in the file: " << oneVowel << endl;
        cout << "Number of words with two vowels in the file: " << twoVowel << endl;
        cout << "Number of words with three or more vowels in the file: " << manyVowel << endl;
    }

    if (noVowel != 0)
    {
        cout << endl;
        cout << "List of Words with no vowels and their number of occurrences:" << endl;
        for (it = vowelMap["noVowel"].begin(); it != vowelMap["noVowel"].end(); it++)
        {
            cout << it->first << ": " << it->second << endl;
        }
    }

    if (oneVowel != 0)
    {
        cout << endl;
        cout << "List of Words with one vowel and their number of occurrences:" << endl;
        for (it = vowelMap["oneVowel"].begin(); it != vowelMap["oneVowel"].end(); it++)
        {
            cout << it->first << ": " << it->second << endl;
        }
    }

    if (twoVowel != 0)
    {
        cout << endl;
        cout << "List of Words with two vowels and their number of occurrences:" << endl;
        for (it = vowelMap["twoVowel"].begin(); it != vowelMap["twoVowel"].end(); it++)
        {
            cout << it->first << ": " << it->second << endl;
        }
    }

    if (manyVowel != 0)
    {
        cout << endl;
        cout << "List of Words with three or more vowels and their number of occurrences:" << endl;
        for (it = vowelMap["manyVowel"].begin(); it != vowelMap["manyVowel"].end(); it++)
        {
            cout << it->first << ": " << it->second << endl;
        }
    }
}