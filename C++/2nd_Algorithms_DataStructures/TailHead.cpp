#include <iostream>

using namespace std; 


void tailhead(int n){
    if (n>0){
        cout<<n<<endl;
        tailhead(n-1); //if I move this function before previous line is head recursion
    }
}


int main(){   
    int x=3;
    tailhead(x);
    return 0;
}