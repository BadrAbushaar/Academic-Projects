#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int BinToDec(string binNum)
{ 
    int binLength = binNum.size();
    int result = 0;

    // Binary number is 1 digit
    if (binLength == 1)
    {
        if (binNum[0] == '1')
            return result + 1;
        else
            return result;
    }
    // Binary number is more than 1 digit
    else
    {
        if (binNum[0] == '1')
        {
            result += 1 * pow(2, binLength - 1);
            return result + BinToDec(binNum.substr(1, binLength));
        }
        else
        {
            return result + BinToDec(binNum.substr(1, binLength));
        }
    }
}