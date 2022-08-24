#include <iostream>

using namespace std;

int main(){
    int max, lenght, A[]={6,2,8,4,5};

    lenght=sizeof(A)/sizeof(A[0]);
    //cout<<lenght<<"\n";
    for(int x=0;x<=lenght;x++){
        if (A[x]>max)
        {
            max=A[x];
        }
    }


    cout<<"The max element of the array is: "<<max<<"\n";
    return 0;
}