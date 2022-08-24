#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////     CLASS FOR UTILITIES     /////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
class utils {
    /////////////     print and user data collectors variables     /////////////
    int value;
    string message, identifierval, identifiermsg, identifierprint;
    char s[50];
    bool endline;
    /////////////     vectorToFile getValuesIntoFile WriteValuesIntoFile variables     /////////////
    string toWrite, fileName, temp;
    int position; 
    vector<string> filevector;
    bool overwrite; 
    public:
    //////////////////////////      utils class methods signatures        ///////////////////////////
    void print(string message, string identifierprint, bool endline);
    //prints in stdout
    int collectval(string identifierval);
    //collects integer from user
    string collectmsg(string identifiermsg);
    //Collects message from user
    void vectorToFile(vector<string> filevector, bool overwrite);
    //Write the contents of a vector into a file, overwrites if file exists
    vector<string> fileToVector(string filename);
    //put file contents in a vector
    string readValuesFromVector(vector<string> filevector, string toRead, int position);
    //write new values in vector
    void writeValuesIntoVector(vector<string> filevector, string toWrite, int position);
    //write new values in vector
    void appendValuesIntoFile(string filename, string toWrite);
    //append new values in file
};
//////////////////////////      utils class methods bodies        ///////////////////////////
void utils::print(string message, string identifierprint="", bool endline=1)
{
    cout<<message;
    cout<<" ";
    if (endline)
    {
        cout<<identifierprint<<"\n";
    } else {
        cout<<identifierprint;
    }
}
int utils::collectval(string identifierval=""){
    print(identifierval);
    cin>>value;
    cin.ignore();
    return value;
}

string utils::collectmsg(string identifiermsg=""){
    print("Insert ", identifiermsg);
    cin.getline(s,50);
    //cin.ignore();
    return s;
}
string utils::readValuesFromVector(vector<string> filevector, string toRead, int position){
    return "yes";
}
void utils::writeValuesIntoVector(vector<string> filevector, string toWrite, int position){

}
void utils::vectorToFile(vector<string> filevector, bool overwrite){


}
vector<string> utils::fileToVector(string filename){
    ifstream infile;
    infile.open(fileName);
    if(!infile.is_open()){
        print("Sorry, could not read the database");
    } else {
        print("Reading database!");
    }
    while (getline(infile, temp)){
        if(temp.size()>0){
            filevector.push_back(temp);
        }
    }
    infile.close();
    return filevector;
}
void utils::appendValuesIntoFile(string filename, string toWrite){
    ofstream outfile(filename,ios::app);
    outfile<<toWrite<<endl;
    outfile.close();
}
/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////     CLASS FOR BANKING APP     ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
class banking
{
/////////////     Menu variables     /////////////
bool quitflag=0;
int selected;
/////////////     OpenAccount variables     /////////////
int accnumber, balance, acctracker, latestacc;
string name, lastname;
//constructors
//mutators
//accesors
//facilitators
//inspectors
//destructors
public:
//////////////////////////      banking class methods signatures        ///////////////////////////
void menu();
//case to handle menu
void openAccount();
//Same as show all accounts, never provide same account value to two people
void checkBalance();
//Displays the account given an account number
void makeDeposit();
//increases balance given an account number
void makeWithdrawal();
//increases balance given an account number
void readOneAccount();
//Used by checkBalance, makeDeposit and makeWithdrawal
void modifyOneAccount();
//Used by checkBalance, makeDeposit and makeWithdrawal
void displayOneAccount();
//Used by checkBalance, makeDeposit and makeWithdrawal
void displayAccounts();
//Display all accounts, used by menu and openAccount
friend utils;
//Need to make utils as friend otherwise cannot access attributes
};
//////////////////////////      utils class methods bodies        ///////////////////////////
void banking::openAccount(){
    // utils ut;
    // ifstream infile;
    // infile.open("db.txt");
    // if(!infile.is_open()){
    //     ut.print("Could not read the database, sorry");
    // } else {
    //     ut.print("Reading database!");
    // }
    //First row in the file is a boolean whether the db is empty or not
    // infile>>acctracker; 
    // if(acctracker==0){
    //     accnumber=1;
    // } else {
    // //Next row in the file is the latest account number
    //     infile>>latestacc;
    //     accnumber=latestacc + 1;
    // }
    // //Done with the file for now since already computed accnumber, can close it now
    // infile.close();
    // ut.print("Your given account number is: ", to_string(accnumber));
    // name = ut.collectmsg("name: ");
    // lastname = ut.collectmsg("lastname: ");
    // balance = ut.collectval("balance: ");
    // //Now need to log the values of the account into the DB. 
    // ofstream outfile("db.txt",ios::app);
    // outfile<<accnumber<<endl;
    // outfile<<name<<endl;
    // outfile<<lastname<<endl;
    // outfile<<balance<<endl;
    // outfile<<"-"<<endl;
    // //Done, can close the file now
    // outfile.close();
    // ut.print("Values recorded, Thank You");
}
void banking::menu(){
    utils ut;
    while(!quitflag){
        ut.print("//////////////////////////////////////////////////////////////////////////////////////");
        ut.print("Welcome to the banking system, please read carefully as our menu options have changed.");
        ut.print("Option 1: Open an account");
        ut.print("Option 2: Check balance");
        ut.print("Option 3: Make a deposit");
        ut.print("Option 4: Make a withdrawal");
        ut.print("Option 5: Display accounts");
        ut.print("Option 6: Quit");
        switch(ut.collectval("Insert the desired option followed by Enter")){
            case 1:
                ut.print("You have chosen to open an account!");
                openAccount();
                break;
            case 2:
                ut.print("You have chosen to check an account balance!");
                break;
            case 3:
                ut.print("You have chosen to make a deposit!");
                break;
            case 4:
                ut.print("You have chosen to make a withdrawal!");
                break;
            case 5:
                ut.print("You have chosen to display all accounts!");
                break;
            case 6:
                ut.print("You have chosen to exit the app! Good bye.");
                quitflag=1;
                break;
            default:
                ut.print("Wrong choice, select one of the options of the menu!");
        }
        
    }

}

int main(){
    banking program;
    program.menu();
}
