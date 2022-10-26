#include <iostream>
#include <cstdarg>
#include <unordered_map>
#include <deque>
#include <iterator>

using namespace std;

class cliOperationsInterface
{
public:
    virtual void cliCase()=0;
};
class miscOperationsInterface
{
public:
    virtual void printMap(unordered_map<int, int> tempmap)=0;
    virtual void printDeque(deque<int> tempdeque, deque<int>::iterator it)=0;
    virtual deque<int> eraseDequeVal(int tempkey, deque<int> tempdeque, deque<int>::iterator it)=0;
};
class memoryOperationsInterface
{
public:
    virtual int get(int key)=0;
    virtual void put(int key, int value)=0;
    virtual void buildCache(int size, unordered_map<int, int> inputmap, deque<int> inputdeq)=0;
    virtual ~memoryOperationsInterface(){}
};
class cachemisc: miscOperationsInterface
{
public:
    void printMap(unordered_map<int, int> tempmap);
    void printDeque(deque<int> tempdeque, deque<int>::iterator it);
    deque<int> eraseDequeVal(int tempkey, deque<int> tempdeque, deque<int>::iterator it);
};
class cacheCli: cliOperationsInterface
{   
    public:
    int optionselected, tempkey, tempvalue, quitflag=0, result;
    void cliCase();
};
class cache: memoryOperationsInterface
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
        void buildCache(int size, unordered_map<int, int> inputmap, deque<int> inputdeq);
        void put(int key, int value);
        int get(int key);
};
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
void cache::buildCache(int size, unordered_map<int, int> inputmap, deque<int> inputdeq){
    this->deq = inputdeq;
    this->tlb = inputmap;
    this->size = size;
}
void cache::put(int key, int value){
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
void cacheCli::cliCase(){
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
    //Define the initial cache structure manually, in the future can be a more sophisticated approach. 
    int size = 4;
    unordered_map<int, int> inputmap = 
    {
        {25,255},
        {50,500},
        {12,122},
        {15,155}
    };
    deque<int> deq = {25,50,12,15};
    //Call the cache constructor
    cache& cash = cache::getInstance();
    cash.buildCache(size, inputmap, deq);
    //Call the CLI
    cacheCli cli;
    cli.cliCase(); 
    return 0;
}
