#include <iostream>

using namespace std;

int main(){
    int A[]={1,2,3,4,5};

    for(auto x:A){
        cout<<"The array contains: "<<x<<"\n";
    }

    return 0;
}