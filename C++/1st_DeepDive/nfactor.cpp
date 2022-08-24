#include <iostream>

using namespace std;

int main(){

    int n, result=1;

    cout<<"Enter the N you want to compute its factors \n";
    cin>>n;

    for(int x=1; x<=n; x++)
    {
        if(n%x==0)
        {
            cout<<x<<" is a factor of N: "<<n<<endl;
        }
        else
        {    
            cout<<x<<" is not a factor of N: "<<n<<endl;
        }
    }


    return 0;


}

