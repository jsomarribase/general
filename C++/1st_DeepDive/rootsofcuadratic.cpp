#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a,b,c;
    float rpositive,rnegative;
    cout << "Enter a,b and c coefficients \n";
    cin >> a >> b >> c;
    rpositive = (- b + sqrt(b*b-4*a*c))/(2*a);
    rnegative = (- b - sqrt(b*b-4*a*c))/(2*a);
    cout << "The r1 is: " << rnegative << "\n";
    cout << "The r2 is: " << rpositive << "\n";

    return 0;
}