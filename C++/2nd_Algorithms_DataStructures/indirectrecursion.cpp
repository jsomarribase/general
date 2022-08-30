#include <iostream>

using namespace std;

void FB(int n);

void FA(int n){
    if(n>0){
        cout<<n<<endl;
        FB(n-1);
    }

}

void FB(int n){
    if(n>1){
        cout<<n<<endl;
        FA(n/2);
    }

}

int main(){
    int x = 20;
    FA(x);
    return 0;
}