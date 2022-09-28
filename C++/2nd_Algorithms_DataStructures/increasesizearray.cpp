#include <iostream>

using namespace std;

int main(){
    //Initial array of size 5
    int A[]={1,2,3,4,5};
    //Create the pointer to the initial array
    int *p = A;
    //Create new array in heap using pointer q with double the size of initial array
    int *q = new int[10];
    //assign the values of the small array into the new large array
    for(int i=0;i<5;i++){
        //cout<<p[i]<<endl;
        q[i]=p[i];
    }
    //Delete the original pointer
    destroy_at(p);  //https://stackoverflow.com/questions/71601234/warning-void-operator-deletevoid-stdsize-t-called-on-unallocated-object
    //Assign the original pointer the address of the new larger array
    p=q;
    //Set the secondary array as null since we dont need it anymore
    q = nullptr;
    //p now has double the size it originally had
    for(int i=0;i<10;i++){
        cout<<p[i]<<endl;
        
    }

    return 0;
}