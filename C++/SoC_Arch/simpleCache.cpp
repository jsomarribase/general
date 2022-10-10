#include <iostream>
#include <unordered_map>
#include <deque>
#include <iterator>

using namespace std;

//Should have:
//-LRU policy
//-A structure TLB like. Unordered Map works.  
//-A structure physical cache like. Need to be deque cause need erase elements. 

//Should follow SOLID principles 
//-Single purpose only
//-Open Closed 
//-Liskov substitution principe
//-Interface Segregation 
//-Dependencies Inversion

//Based on https://leetcode.com/problems/lru-cache/discuss/355310/lru-cache-simple-c-code-with-clear-comments

//<<USAGE>>: Just compile, run, select get or put operations on the CLI interface,//
//when finished select option 3 to exit. No persistent storage ATM,               //
//initual structure is already predefined in main although user can change it.    //

///////////////////////////////////
/////////...INTERFACES...//////////
///////////////////////////////////

//Interface for cli 
class cliOperations{
public:
    virtual void cliCase()=0;
};

//Interface for miscellaneous
class miscOperations{
public:
    virtual void printMap(unordered_map<int, int> tempmap)=0;
    virtual void printDeque(deque<int> tempdeque, deque<int>::iterator it)=0;
    virtual deque<int> eraseDequeVal(int tempkey, deque<int> tempdeque, deque<int>::iterator it)=0;
};

//Interface for re-usable memory Ops
class memoryOperations{
public:
    virtual int get(int key)=0;
    virtual void put(int key, int value)=0;
    virtual ~memoryOperations(){}
};

/////////////////////////////////////////////////////////////
/////////...CLASSES AND THEIR METHODS SIGNATURES...//////////
/////////////////////////////////////////////////////////////

//micellaneous class and signatures
class cachemisc: miscOperations{
public:
    void printMap(unordered_map<int, int> tempmap);
    void printDeque(deque<int> tempdeque, deque<int>::iterator it);
    deque<int> eraseDequeVal(int tempkey, deque<int> tempdeque, deque<int>::iterator it);
};
//CacheCli Class and signatures
class cacheCli: cliOperations
{   
    public:
    int optionselected, tempkey, tempvalue, quitflag=0, result;
    void cliCase();
};
//Cache class and signatures
class cache: memoryOperations
{
    private:
        cache(){};
    public:
        static cache& getInstance(){
            static cache theInstance;
            return theInstance;
        }
        unordered_map<int, int> tlb;
        deque<int> deq, tempdeq;
        deque<int>::iterator it;
        int size, data; 
        void put(int key, int value);
        int get(int key);
};

////////////////////////////////////////////////
/////////...METHODS IMPLEMENTATIONS...//////////
////////////////////////////////////////////////

//miscellaneout methods implementations
void cachemisc::printMap(unordered_map<int, int> tempmap){
    cout<<"The current map structure is: "<<endl;
    for (auto x : tempmap){
        cout<<x.first<<"  "<<x.second<<endl;
    }
}
void cachemisc::printDeque(deque<int> tempdeque, deque<int>::iterator it){
    cout<<"The current deque structure is: ";
    for(it=tempdeque.begin(); it!=tempdeque.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
deque<int> cachemisc::eraseDequeVal(int key, deque<int> tempdeque, deque<int>::iterator it){
    for(it=tempdeque.begin(); it!=tempdeque.end(); it++){
        if(*it==key){
            tempdeque.erase(it);
            break;
        }
    }
    return tempdeque;
}
//Cache class and methods implementations
void cache::put(int key, int value){
    ////////////////Defines logic for writing in cache//////////////////
    cachemisc misc;
    //Check if key is already in TLB and delete it if so since later will push it anyways
    if(tlb.find(key)==tlb.end()){
        cout<<"The given Key is not in the record, let me add it."<<endl;
    } else {
        cout<<"The given Key is already in the record, will refresh policy."<<endl;
        //Erase record from tlb and cache
        tlb.erase(key);
        tempdeq = misc.eraseDequeVal(key, deq, it);
        deq = tempdeq;
    }
    //Check if deque is full and act accordingly
    if(deq.size()==size){
        cout<<"The cache is full, following replacement policy"<<endl;
        //Need to make sure the element im popping is also deleted from tlb
        if (tlb.find(deq.back())==tlb.end()){
            cout<<"Clering the following key in TLB: "<<deq.back()<<endl;
        } else {
            tlb.erase(deq.back());
        }
        deq.pop_back();
    } else {
        cout<<"There is plenty of space in the cache, your value has been stored"<<endl;
    }
    //Add the desired value to both deque and tlb 
    deq.push_front(key);
    tlb[key] = value;
    cout<<"Success!"<<endl;
    misc.printDeque(deq, it);
    misc.printMap(tlb);
}

int cache::get(int key){
    ////////////////Defines logic for reading from cache//////////////////
    cachemisc misc;
    //Check if record exists
    if(tlb.find(key)==tlb.end()){
        cout<<"The record does not exists try again"<<endl;
        data = -1; 
    } else {
        //Get data and refresh policy
        cout<<"The record do exist, getting your record"<<endl;
        data = tlb[key];
        tempdeq = misc.eraseDequeVal(key, deq, it);
        deq = tempdeq;
        deq.push_front(key);
    }
    cout<<"Success!"<<endl;
    misc.printDeque(deq, it);
    misc.printMap(tlb);
    return data;
}

//Implementation of cliCase
void cacheCli::cliCase(){
    ////////////////Defines logic of the CLI//////////////////
    cache& cash = cache::getInstance();
    while(quitflag==0){
        cout<<"---------------------------------------------"<<endl;
        cout<<"S i m p l e    L R U    c a c h e"<<endl;
        cout<<"Option 1: Put()"<<endl;
        cout<<"Option 2: Get()"<<endl;
        cout<<"Option 3: Quit"<<endl;
        cout<<"Insert the desired option"<<endl;
        cin>>optionselected;
        cin.ignore();
        switch(optionselected){
            case 1:
                cout<<"Insert key "<<endl;
                cin>>tempkey;
                cin.ignore();
                cout<<"Insert value "<<endl;
                cin>>tempvalue;
                cin.ignore();
                cash.put(tempkey, tempvalue);
                break;
            case 2:
                cout<<"Insert key "<<endl;
                cin>>tempkey;
                cin.ignore();
                result = cash.get(tempkey);
                cout<<"The value requested is: "<<result<<endl;
                break;
            case 3:
                quitflag=1;
                break;
            default:
                cout<<"wrong selection"<<endl;
        }
    }
}
int main(){
    //Need to use Static Magic/Singleton design pattern, otherwise values of instance of cache class set in main are not visible by the CLI.  
    cache& cash = cache::getInstance();
    //Define the initial structure manually. ToDo: Just by having the map can populate the deque and get the size, map can be read from a file or input by the user, etc. 
    cash.size = 4;
    cash.tlb[25] = 255;
    cash.tlb[50] = 500;
    cash.tlb[12] = 122;
    cash.tlb[15] = 155;
    cash.deq.push_front(25);
    cash.deq.push_front(50);
    cash.deq.push_front(12);
    cash.deq.push_front(15);
    //Call the CLI
    cacheCli cli;
    cli.cliCase(); 

    return 0;
}