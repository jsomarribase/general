#include <iostream>

using namespace std;

int nestedrecur(int n){

    if(n>100)
        return n-10;
    return nestedrecur(nestedrecur(n+11));

}

int main(){
    int x, y = 95;
    x = nestedrecur(y);
    cout<<x<<endl;  
    return 0;

}