#include <iostream>

using namespace std;


int ncr(int n, int r){
    if( n==r || r==0){
        return 1;

    } else {
        return ncr(n-1,r-1)+ncr(n-1,r);
    }
}




int main(){
    int x, y = 4, z = 2;
    x = ncr(y,z);
    cout<<x<<endl;
    return 0;
}