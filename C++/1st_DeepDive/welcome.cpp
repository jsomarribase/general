#include <iostream>

using namespace std;

int main()
{
    string name;
    cout << "Hi bro whats your name? \n";
    // cin >> name;
    getline(cin,name);
    cout << "Welcome! " << name;
    return 0;

}