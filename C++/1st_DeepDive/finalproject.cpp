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
    string toWrite, fileName, temp, result, keyword;
    int position, desiredindex, startingindex; 
    vector<string> filevector;
    bool overwrite;
    /////////////     printvectorsegment variables     /////////////
    int beginindex, endingindex; 
    public:
    //////////////////////////      utils class methods signatures        ///////////////////////////
    void print(string message, string identifierprint, bool endline);
    //prints in stdout
    int collectval(string identifierval);
    //collects integer from user
    string collectmsg(string identifiermsg);
    //Collects message from user
    void printvector(vector<string> filevector);
    //prints a vector
    void printvectorsegment(vector<string> filevector, int startingindex, int endingindex);
    //prints vector values giving a starting and ending point
    int getValueIndexInVector(vector<string> filevector, string keyword, int startingindex);
    //Need this to look at where in the vector is an specific account located
    void vectorToFile(string filename, vector<string> filevector, bool overwrite);
    //Write the contents of a vector into a file, overwrites if file exists
    vector<string> fileToVector(string filename);
    //put file contents in a vector
    string readValuesFromVector(vector<string> filevector, int position);
    //write new values in vector
    vector<string> writeValuesIntoVector(vector<string> filevector, string toWrite, int position);
    //write new values in vector, return modified vector
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
    cin.ignore(); //need to flush cin buffer
    return value;
}

string utils::collectmsg(string identifiermsg=""){
    print("Insert ", identifiermsg);
    cin.getline(s,50); //cin.ignore() is not needed after this line since getline includes it, if you add it, will require user to input something and then will flush the buffer
    return s;
}
void utils::printvectorsegment(vector<string> filevector, int beginindex, int endingindex){
    int index = 0;
    for(string i: filevector){
        if(index>=beginindex&&index<=endingindex){
            print(i);
        }
        index+=1;
    }
}
void utils::printvector(vector<string> filevector){
    for(string i: filevector){
        print(i);
    }
}
int utils::getValueIndexInVector(vector<string> filevector, string keyword, int startingindex){
    //TO DO: What if keyword is not there. 
    int index = 0;
    for(string i: filevector)
    {
        if(index>=startingindex){
            if(i==keyword){
            desiredindex = index;
            break;
            }
        }
        index = index + 1;
    }
    return desiredindex;
}
string utils::readValuesFromVector(vector<string> filevector, int position){
    result = filevector.at(position);
    return result;
}

vector<string> utils::writeValuesIntoVector(vector<string> filevector, string toWrite, int position){
    filevector.at(position) = toWrite;
    return filevector;
}

void utils::vectorToFile(string filename, vector<string> filevector, bool overwrite=1){
    if (overwrite) 
    {
        //If user needs to overwrite content can open and close the file to clear it
        ofstream outfile(filename);
        outfile.close(); 
    }
    for(string i: filevector)
        appendValuesIntoFile(filename, i);
}
vector<string> utils::fileToVector(string filename){
    ifstream infile;
    infile.open(filename);
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
const string file="db.txt";
int accnumber, balance, acctracker, latestacc;
string name, lastname, firstrow;
vector<string> currentfilevector;
/////////////     checkbalance variables     /////////////
int foundindex, startingindex, foundaccmatch;
string cbBalance, cbBalanceindex, acctocheck, valuefromindextotry, givenacc;
/////////////     changebalance variables     /////////////
int balanceindex, amount, currentbalance, futurebalance;
string changebalanceaction, tempcurrentbalance;
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
int checkBalance(string givenacc);
//Displays the account given an account number
void changeBalance();
//used for deposits and withdrawals
void displayOneAccount();
//Used by checkBalance, makeDeposit and makeWithdrawal
void displayAccounts();
//Display all accounts, used by menu and openAccount
friend utils;
//Need to make utils as friend otherwise cannot access attributes
};
//////////////////////////      banking class methods bodies        ///////////////////////////
void banking::displayOneAccount(){
    utils ut;
    currentfilevector = ut.fileToVector(file);
    acctocheck = ut.collectmsg("the account number you want to visualize");
    ut.print("Checking the account balance...");
    balanceindex = checkBalance(acctocheck);
    ut.print(to_string(balanceindex));
    ut.print("Checking the rest of account data...");
    ut.printvectorsegment(currentfilevector, balanceindex-4, balanceindex+1);
    ut.print("Done displaying the single account information, thanks!");
}

void banking::displayAccounts(){
    utils ut;
    currentfilevector = ut.fileToVector(file);
    ut.printvector(currentfilevector);
    ut.print("Done displaying all accounts, thank you!");
}
void banking::changeBalance(){
    utils ut;
    //get neccesary info from user
    acctocheck = ut.collectmsg("the account number which balance you need to modify.");
    changebalanceaction = ut.collectmsg("1 for deposit and 2 for withdrawal");
    amount = ut.collectval("the amount to deposit or withdraw");
    //get index of file in memory of the balance that need to change
    balanceindex = checkBalance(acctocheck);
    //load file in memory
    currentfilevector = ut.fileToVector(file);
    //read current balance value
    tempcurrentbalance = ut.readValuesFromVector(currentfilevector, balanceindex);
    currentbalance = stoi(tempcurrentbalance);
    //compute new balance
    if (changebalanceaction=="1"){
        futurebalance = currentbalance + amount;
    } else {
        futurebalance = currentbalance - amount;
    }
    //Write new balance in vector
    currentfilevector = ut.writeValuesIntoVector(currentfilevector, to_string(futurebalance) , balanceindex);
    //create the new file with the modified values
    ut.vectorToFile(file, currentfilevector);
    //display new balance
    checkBalance(acctocheck);
    ut.print("All done with the change balance operation! Thank you.");
}

int banking::checkBalance(string givenacc="0"){
    startingindex=1; //if starts from 0 can conflict with first row of file which is not the real account info
    foundaccmatch=1;
    utils ut;
    //Gather account number desired to check balance from
    if(givenacc=="0"){
        acctocheck = ut.collectmsg("the account number you want to check.");
    } else {
        acctocheck = givenacc;
    }
    
    //Load db in memory
    currentfilevector = ut.fileToVector(file);
    while(foundaccmatch){
        foundindex = ut.getValueIndexInVector(currentfilevector, "-", startingindex);
        valuefromindextotry = currentfilevector.at(foundindex+1); 
        if (valuefromindextotry == acctocheck){
            cbBalance = currentfilevector.at(foundindex+4);
            ut.print("The balance from account ","",0);
            ut.print(acctocheck, "",0);
            ut.print(" is ","",0);
            ut.print(cbBalance);
            foundaccmatch = 0;
        } else {
            startingindex = startingindex + 5;
        }
    }
    return foundindex+4;
}
void banking::openAccount(){
    utils ut;
    //Load file in memory
    currentfilevector = ut.fileToVector(file);
    //Read first row of file to see if 0 there are no users, else will contain last account number
    firstrow = ut.readValuesFromVector(currentfilevector, 0);
    //If it is assing account 1 to the first client
    if(firstrow=="0"){
        ut.print("Nice, this is our first client!");
        accnumber = 1;
    } else {
    //if not then the last client account is in the second row so just increase that number
        ut.print("Big thanks to the client for opening an account with us, great choice!");
        accnumber = stoi(firstrow) + 1;
    }
    //Assign account number to new future file first row
    firstrow = to_string(accnumber);
    //Gather from user the other values
    ut.print("Your given account number is: ", to_string(accnumber));
    name = ut.collectmsg("the client name: ");
    lastname = ut.collectmsg("the client lastname: ");
    balance = ut.collectval("the client balance: ");
    //modify file contents in memory (vector) so all values are now updated
    currentfilevector = ut.writeValuesIntoVector(currentfilevector, firstrow, 0); //Populates first row of file with latest account
    ut.vectorToFile(file, currentfilevector); //In memory modified vector is used to create a file
    //Append to the newly created file the recently gathered values
    ut.appendValuesIntoFile(file, to_string(accnumber));
    ut.appendValuesIntoFile(file, name);
    ut.appendValuesIntoFile(file, lastname);
    ut.appendValuesIntoFile(file, to_string(balance));
    ut.appendValuesIntoFile(file, "-");
    ut.print("Database modified succesfully, new account values recorded.");
    ut.print("Returning to main menu.");
}
void banking::menu(){
    utils ut;
    while(!quitflag){
        ut.print("//////////////////////////////////////////////////////////////////////////////////////");
        ut.print("Welcome to the banking system, please read carefully as our menu options have changed.");
        ut.print("Option 1: Open an account");
        ut.print("Option 2: Check balance");
        ut.print("Option 3: Make a deposit or withdrawal");
        ut.print("Option 4: Display a single account");
        ut.print("Option 5: Display accounts");
        ut.print("Option 6: Quit");
        switch(ut.collectval("Insert the desired option followed by Enter")){
            case 1:
                ut.print("You have chosen to open an account!");
                openAccount();
                break;
            case 2:
                ut.print("You have chosen to check an account balance!");
                checkBalance();
                break;
            case 3:
                ut.print("You have chosen to make a deposit or withdrawal!");
                changeBalance();
                break;
            case 4:
                ut.print("You have chosen to display a single account!");
                displayOneAccount();
                break;
            case 5:
                ut.print("You have chosen to display all accounts!");
                displayAccounts();
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
