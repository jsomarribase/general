#include <iostream>

using namespace std;


int basicpow(int m, int n){
    //O(n) space complexity
    if(n==0){
        return 1;
    } else {
        return basicpow(m, n-1)*m;
    }

}

int efficientpow(int m, int n){
    //O(n/2) space complexity
    if(n==0){
        return 1;
    } 
    if(n%2==0){
        return efficientpow(m*m,n/2);
    } else {
        return m*efficientpow(m*m,(n-1)/2);
    }
}


int main(){
    int x, y = 2, z = 9; 
    x = basicpow(y,z);
    cout<<x<<endl;
    return 0;
}