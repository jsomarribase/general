#include <iostream>

using namespace std;

int fact(int n){
    if(n==0 || n==1){
        return 1;
    } else {
        return fact(n-1)*n;
    }
}


int main(){
    int x, y = 0;
    x = fact(y);
    cout<<x<<endl;
    return 0;
}