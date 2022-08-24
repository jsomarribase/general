#include <iostream>
#include <cmath>

using namespace std;

int main(){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//you get the reverse by having the sum of sum*10 + digit starting at 0. Palindrome is same as number backwards.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int n, print, result=0;
    cout<<"Enter the N you want to see its reversed digits \n";
    cin>>n;
    int m=n;

    for(int m=n; m>0;)
    {
        print=m%10;
        m=m/10;
        result=result*10+print;
    }

    cout<<"The reverse of: "<<n<<" is: "<<result<<"\n";

    if (n==result)
    {
        cout<<"The number is palindrome since N: "<<n<<" is the same as its reverse: "<<result<<"\n";
    } else {
        cout<<"The number is not palindrome since N: "<<n<<" is not the same as its reverse: "<<result<<"\n";
    }

    return 0;
}

