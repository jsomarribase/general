#include <iostream>
#include <cmath>

using namespace std;

int main(){
//////////////////////////////////////////////////////////////////
//if the sum of the cubes of the digits of N is equal to N that is an amstrong number
////////////////////////////////////////////////////////////////////

    int n, print, cube, sum_cubes=0;
    cout<<"Enter the N you want to find if it is Amstrong number or not \n";
    cin>>n;

    for(int m=n; m>0;)
    {
        print=m%10;
        m=m/10;
        //cube=print*print*print;
        cube=pow(print, 3); //DOES WORK BUT IS LESS EFFICIENT THAN MULTIPLY 3 TIMES 
        sum_cubes+=cube;
    }
    if(sum_cubes==n)
    {
        cout<<n<<" is an amstrong number since its equal to the sum of its digits cubes: "<<sum_cubes<<"\n";
    } else {
        cout<<n<<" is not an amstrong number since it is not equal to the sum of its digits cubes: "<<sum_cubes<<"\n";
    }       


    return 0;
}

