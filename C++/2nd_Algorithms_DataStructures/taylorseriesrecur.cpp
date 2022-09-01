#include <iostream>

using namespace std;


double taylor(int x, int n){
    static double p=1, f=1;
    double r;

    if(n==0){
        return 1;
    } else {
        r = taylor(x,n-1);
        f=f*n;
        p=p*x;
        return r + p/f;
    }

}

double tayloroptimized(double x, double n){
    static double s=1;
    if (n==0){
        return s;
    } 
    s=1+(x/n)*s;
    return tayloroptimized(x, n-1);
    
}


int main(){
    double result;
    //result = taylor(3, 10);
    
    result = tayloroptimized(3, 10);
    cout<<result<<endl;
    return 0;
}