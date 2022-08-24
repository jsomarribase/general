#include <iostream>
#include <cmath>

using namespace std;

int main(){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//You can do it by reversing twice and a switch case
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int n, r, print, print2, result=0;
    cout<<"Enter the N you want to see its digits in words \n";
    cin>>n;

    for(int m=n; m>0;)
    {
        print=m%10;
        m=m/10;
        result=result*10+print;
    }

    cout<<"The digits in words are: \n";

    for(int r=result; r>0;)
    {
        print2=r%10;
        r=r/10;
        switch(print2)
        {
            case 1:
                cout<<"One \n";
                break;
            case 2:
                cout<<"Two \n";
                break;
            case 3:
                cout<<"Three \n";
                break;
            case 4:
                cout<<"Four \n";
                break;
            case 5:
                cout<<"Five \n";
                break;
            case 6:
                cout<<"Six \n";
                break;
            case 7:
                cout<<"Seven \n";
                break;
            case 8:
                cout<<"Eight \n";
                break;
            case 9:
                cout<<"Nine \n";
                break;
            Default:
                cout<<"Zero";
        }
 
    }

    return 0;
}

