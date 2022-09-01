#include <iostream>

using namespace std; 

int firstnnumber(int n){
    if(n==0){
        return 0;
    } else {
        return firstnnumber(n-1)+n;
    }
}


int main(){
    int x = 5;
    int y = firstnnumber(x);
    cout<<y<<endl;
    return 0;
}