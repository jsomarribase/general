#include <iostream>

using namespace std;

int main(){

    int n, result=1;

    cout<<"Enter the N you want to compute the factorial \n";
    cin>>n;

    for(int x=1; x<=n; x++)
    {
        result *= x;
    }

    cout<<"The factorial of N: "<<n<<" is: "<<result;

    return 0;


}

