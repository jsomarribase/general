#include <iostream>

using namespace std;

int main(){
//////////////////////////////////////////////////////////////////
//Mod 10 will give last digit and divided by 10 will remove the last digit 
////////////////////////////////////////////////////////////////////

    int n, print, result=1, sum_factors=0;
    cout<<"Enter the N you want to print its digits backwards \n";
    cin>>n;

    for(int m=n; m>0;)
    {
        print=m%10;
        cout<<print<<"\n";
        m=m/10;
    }           


    return 0;
}

