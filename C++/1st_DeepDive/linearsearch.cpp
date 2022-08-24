#include <iostream>

using namespace std;

int main(){
    int light=0, key, lenght, A[5]={6,2,8,4,5};
    lenght=sizeof(A)/sizeof(A[0]);

    cout<<"insert key: \n";
    cin>>key;
    for(int x=0;x<lenght;x++){
        if (A[x]==key)
        {
            cout<<"The key is in the position: "<<x<<" of the array. \n";
            light=1;
        }
    }
    if(light==0)
        cout<<"The key value is not in the array, sorry.";

    return 0;
}