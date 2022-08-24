#include <iostream>

using namespace std;

int main(){
    /////////////////////////////////
    //Binary search is O(log(n)), while linear is O(n)
    /////////////////////////////////
    int l, h, mid, key, min, lenght, A[]={6,2,8,4,5,7,12,28,94,63,88};
    cout<<"Enter the key: \n";
    cin>>key;
    /////////////////////////////////
    //Get array size
    /////////////////////////////////
    lenght=sizeof(A)/sizeof(A[0]);
    /////////////////////////////////
    //First sort 
    /////////////////////////////////
    for(int x=0;x<lenght;x++)
    {
        for(int y=0;y<lenght;y++)
        {
            if(A[x]<A[y])
            {
                min=A[x];
                A[x]=A[y];
                A[y]=min;
            }
        }
        
    }
    /////////////////////////////////
    //Then print the sorted array
    /////////////////////////////////
    cout<<"The sorted array is: \n";
    for(int z=0;z<lenght;z++)
    {
        cout<<A[z]<<"\n";
    }
    /////////////////////////////////
    //Defining low and high
    /////////////////////////////////
    l = 0;
    h = lenght-1;

    cout<<"The starting index for low is: "<<l<<"\n";
    cout<<"The starting index for high is: "<<h<<"\n";
    /////////////////////////////////
    //Then do binary search
    /////////////////////////////////

    while(l<=h)
    {
        mid = (l+h)/2;
        if(key==A[mid])
        {
            cout<<"The key was found in the index: "<<mid<<"\n";
            return 0;
        } else if(key<A[mid])
        {
            h=mid-1;
        } else
        {
            l=mid+1;
        }
    }
    cout<<"Unfortunately the key was not found in the array \n";


    return 0;
}