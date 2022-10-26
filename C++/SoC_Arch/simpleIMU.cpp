#include <iostream>
#include <bitset>
#include <vector>
#define S 4 //Size of address bitset 4bit 
#define rw 2 //Size of row and column bitset 2bit each
//Usage: Compile and run, CLI will guide you through.//  
using namespace std;
class memoryOperationsInterface
{
public:
    virtual int read(bool channelsel, int row, int column)=0;
    virtual void write(bool channelsel, int row, int column, bool towrite)=0;
    virtual void refresh(bool channelsel, int row, int column)=0;
    virtual void buildMemory(vector<vector<bool>> channel1, vector<vector<bool>> channel2)=0;
};
class miscOperationsInterface
{
public:
    virtual void printVectorm(vector<vector<bool>> toprint)=0;
    virtual int getRow(bitset<S> address)=0;
    virtual int getColumn(bitset<S> address)=0;
};
class cliOperationsInterface
{
public:
    virtual void cliCase()=0;
};
class imuOperations: memoryOperationsInterface
{
private:
    imuOperations(){};
    bool channelsel;
    vector<vector<bool>> channel1mem;
    vector<vector<bool>> channel2mem;
    int row, column, result;
    bool towrite;
public:
    static imuOperations& getInstance(){
        static imuOperations theInstance;
        return theInstance;
    }
    void buildMemory(vector<vector<bool>> channel1, vector<vector<bool>> channel2);
    int read(bool channelsel, int row, int column);
    void write(bool channelsel, int row, int column, bool towrite);
    void refresh(bool channelsel, int row, int column);
};
class imuMisc: miscOperationsInterface
{
private:
    vector<vector<bool>> toprint;
    bitset<rw> temprow, tempcolumn;
    int temprowint, tempcolumnint;
public:
    void printVectorm(vector<vector<bool>> toprint);
    int getRow(bitset<S> address);
    int getColumn(bitset<S> address);
};
class imuCLI: cliOperationsInterface
{   
private:
    int optionselected, temprow, tempcolumn, channelselection, quitflag=0, result;
    bitset<S> address;
    bool temptowrite;
public:
    void cliCase();
};
void imuOperations::buildMemory(vector<vector<bool>> channel1, vector<vector<bool>> channel2){
    this->channel1mem = channel1;
    this->channel2mem = channel2;
}
int imuOperations::read(bool channelsel, int row, int column){
    imuMisc misc;
    return channelsel?this->channel2mem[row][column]:channel1mem[row][column];
}
void imuOperations::write(bool channelsel, int row, int column, bool towrite){
    imuMisc misc;
    if(channelsel){
        this->channel2mem[row][column] = towrite;
        misc.printVectorm(this->channel2mem);
    } else {
        this->channel1mem[row][column] = towrite;
        misc.printVectorm(this->channel1mem);
    }
    cout<<"row is: "<<row<<endl;
    cout<<"column is: "<<column<<endl;
    cout<<"towrite is: "<<towrite<<endl;
}
void imuOperations::refresh(bool channelsel, int row, int column){
    imuMisc misc;
    if(channelsel){
        this->channel2mem[row][column] = towrite;
        misc.printVectorm(this->channel2mem);
    } else {
        this->channel1mem[row][column] = towrite;
        misc.printVectorm(this->channel1mem);
    }
    cout<<"You desired cell value has been refreshed"<<endl;
}
void imuMisc::printVectorm(vector<vector<bool>> toprint){
    for (vector<bool> temp: toprint)
    {
        for (int x: temp)
        {
            cout<<x<<" ";
        }    
        cout<<endl;
    }  
}
int imuMisc::getColumn(bitset<S> address){
    tempcolumn[0] = address[2];
    tempcolumn[1] = address[3];
    tempcolumnint = tempcolumn.to_ulong();
    return tempcolumnint;
}
int imuMisc::getRow(bitset<S> address){
    temprow[0] = address[0];
    temprow[1] = address[1];
    temprowint = temprow.to_ulong();
    return temprowint;
}
void imuCLI::cliCase(){
    imuOperations& imuops = imuOperations::getInstance();
    imuMisc misc;
    while(quitflag==0){
        cout<<"---------------------------------------------"<<endl;
        cout<<"S i m p l e    I M U"<<endl;
        cout<<"Option 1: Read()"<<endl;
        cout<<"Option 2: Write()"<<endl;
        cout<<"Option 3: Refresh()"<<endl;
        cout<<"Option 4: Quit"<<endl;
        cout<<"Insert the desired option"<<endl;
        cin>>optionselected;
        cin.ignore();
        switch(optionselected){
            case 1:
                cout<<"Insert 4 bit address to read (2 first bits represent the row and 2 last bits the column) "<<endl;
                cin>>address;
                cin.ignore();
                cout<<"Insert channel 0 or 1 "<<endl;
                cin>>channelselection;
                cin.ignore();
                cout<<"The reading is: "<<imuops.read(channelselection, misc.getRow(address), misc.getColumn(address))<<endl;
                break;
            case 2:
                cout<<"Insert 4 bit address to write (2 first bits represent the row and 2 last bits the column) "<<endl;
                cin>>address;
                cin.ignore();
                cout<<"Insert channel 0 or 1 "<<endl;
                cin>>channelselection;
                cin.ignore();
                cout<<"Insert value to write 0 or 1 "<<endl;    
                cin>>temptowrite;
                cin.ignore();
                imuops.write(channelselection, misc.getRow(address), misc.getColumn(address), temptowrite);
                break;
            case 3:
                cout<<"Insert 4 bit address to refresh (2 first bits represent the row and 2 last bits the column) "<<endl;
                cin>>address;
                cin.ignore();
                cout<<"Insert channel 0 or 1 "<<endl;
                cin>>channelselection;
                cin.ignore();
                imuops.refresh(channelselection, misc.getRow(address), misc.getColumn(address));
                break;
            case 4:
                quitflag=1;
                break;
            default:
                cout<<"wrong selection"<<endl;
        }
    }
}
int main(){
    imuOperations& imuops = imuOperations::getInstance();
    imuCLI cli;
    int row, column, result;
    vector<vector<bool>> channel1{
        {1,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    }; 
    vector<vector<bool>> channel2{
        {1,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    }; 
    imuops.buildMemory(channel1, channel2);
    cli.cliCase();
    return 0;
}