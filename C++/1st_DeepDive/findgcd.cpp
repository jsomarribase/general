#include <iostream>

using namespace std;

int main(){
//////////////////////////////////////////////////////////////////
//Greatest common divisor or highest common factor between 2 numbers is found by substracting greater from lower until both numbers are equal
////////////////////////////////////////////////////////////////////

    int x1, x2, y1, y2;
    cout<<"Enter the first number: \n";
    cin>>x1;
    cout<<"Enter the second number: \n";
    cin>>x2;
    y1=x1;
    y2=x2;

    if(x1==x2)
    {
        cout<<"The greatest common factor of both "<<x1<<" and "<<x2<<" numbers is themselves: "<<x1<<" \n";
    } else {
        while(y1!=y2)
        {
            if(y1>y2)
                y1 = y1-y2;
            else 
                y2 = y2-y1;
        }
        cout<<"The greatest common factor of both "<<x1<<" and "<<x2<<" numbers is : "<<y1<<" \n";  
    }

    return 0;
}

