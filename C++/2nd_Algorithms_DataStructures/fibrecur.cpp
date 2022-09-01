#include <iostream>

using namespace std;



int fibo(int n){
    if(n<=1){
        return n;
    } else {
        return fibo(n-2) + fibo(n-1);
    }
}

int f[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; 

int fibowmemoization(int n){
    if(n<=1){
        f[n] = n;
        return n;
    } else {
        if(f[n-2]==-1){
            f[n-2]= fibo(n-2);
        }
        if(f[n-1]==-1){
            f[n-1]= fibo(n-1);
        }
        return f[n-2] + f[n-1];
    }
     

}

int main(){
    int x, y=6;
    //x = fibo(y);
    x = fibowmemoization(y);
    cout<<x<<endl;
    return 0;
}