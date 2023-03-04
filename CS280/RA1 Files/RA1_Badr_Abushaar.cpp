#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string firstName;
    string lastName;

    cout << "Welcome to CS 280 in Fall 2022\n";
    cout << "Please enter your last name followed by your first name.\n";

    cin >> lastName >> firstName;
    cout << "Hello " << firstName << " " << lastName << " in CS 280" << endl;

    return 0;
}
