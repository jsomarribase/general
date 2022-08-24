#include <iostream>

using namespace std;

int main ()
{
    int base,height,area;

    cout << "Enter the base \n";
    cin >> base;
    cout << "Enter the height \n";
    cin >> height;
    area = (base * height)/2;
    cout << "The area is: " << area;
    return 0;
}