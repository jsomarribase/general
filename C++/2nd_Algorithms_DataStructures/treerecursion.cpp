#include <iostream>

using namespace std;

void treerecursion(int n){
    if (n>0){
        cout<<n<<endl;
        treerecursion(n-1);
        treerecursion(n-1);
    }
}

int main(){
    int x = 3;
    treerecursion(x);
    return 0;
}