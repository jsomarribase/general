#include <iostream>

using namespace std;

int main(){
//////////////////////////////////////////////////////////////////
// N is a perfect number  when the sum of its factors equals to 2N
////////////////////////////////////////////////////////////////////

    int n, result=1, sum_factors=0;
    cout<<"Enter the N you want to find out if it is perfect or not \n";
    cin>>n;
    for(int x=1; x<=n; x++)
    {
        if(n%x==0)
        {
            sum_factors+=x;
        }
    }
    if(sum_factors==2*n)
    {
        cout<<n<<" is a perfect number since the sum of its factors: "<<sum_factors<<" equals to 2N: "<<2*n<<endl;
    } else {
        cout<<n<<" is not a perfect number since the sum of its factors: "<<sum_factors<<" is different than 2N: "<<2*n<<endl;
    }
    return 0;
}

