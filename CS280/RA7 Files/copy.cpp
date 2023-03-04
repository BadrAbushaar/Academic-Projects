#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <iterator>
using namespace std;

bool BalancedDelimiters(string &inputString)
{
    stack<char> s;
    int strLength = inputString.length();

    for (int i = 0; i < strLength; i++)
    {
        if (isalpha(inputString[i]) || isspace(inputString[i]))
        {
            continue;
        }
        if (inputString[i] == '(' || inputString[i] == '[' || inputString[i] == '{')
        {
            s.push(inputString[i]);
        }

        if (s.empty())
        {
            cout << "Stack is empty and the scanning of input string is not completed." << endl;
            return false;
        }

        if (!s.empty())
        {
            if (inputString[i] == '}')
            {
                if (s.top() == '{')
                {
                    s.pop();
                    continue;
                }
                else
                {
                    //cout << "Stack is not empty and the scanning of input string is not completed." << endl;
                    return false;
                }
            }

            else if (inputString[i] == ']')
            {
                if (s.top() == '[')
                {
                    s.pop();
                    continue;
                }
                else
                {
                    //cout << "Stack is not empty and the scanning of input string is not comleted." << endl;
                    return false;
                }
            }

            else if (inputString[i] == ')')
            {
                if (s.top() == '(')
                {
                    s.pop();
                    continue;
                }
                else
                {
                    //cout << "Stack is not empty and the scanning of input string is not comleted." << endl;
                    return false;
                }
            }

            else
            {
                continue;
            }
        }
    }

    if (s.empty())
    {
        cout << "Stack is empty and the scanning of input string is completed." << endl;
        return true;
    }
    else
    {
        cout << "Stack is not empty and the scanning of input string is completed." << endl;
        return false;
    }
}