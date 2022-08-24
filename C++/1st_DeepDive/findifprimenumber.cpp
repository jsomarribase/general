#include <iostream>

using namespace std;

int main(){
//////////////////////////////////////////////////////////////////
// N is a prime number if divisible only by 1 and itself. CAREFULL THIS IS WRONG PRIME IS A NUMBER THAT HAS ONLY 2 DIFFERENT POSITIVE FACTORS
////////////////////////////////////////////////////////////////////

    int n, result=1, sum_factors=0;
    cout<<"Enter the N you want to find out if it is prime number or not \n";
    cin>>n;
    for(int x=1; x<=n; x++)
    {
        if(n%x==0)
        {
            if(x!=1 && x!=n)
            {
                cout<<n<<" is not a primer number since "<<x<<" is one of its factors.";
                return 0;
            }
        }
    }
    cout<<n<<" is  a primer number since its only factors are 1 and himself.";

    return 0;
}

