#include <iostream>


using namespace std;

int main(){
    int n, sum;
    cout << "Type the N your want to find the sum of natural numbers \n";
    cin >> n;
    sum = (n*(n+1))/2;
    cout << "The result is: " << sum;

    return 0;
}