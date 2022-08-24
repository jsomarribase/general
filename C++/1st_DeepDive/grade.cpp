#include <iostream>
#include <string>
using namespace std;
class utils
{
    string message;
    char s[50];
    int value;
    public:
    void print(string message);
    int collect();
    string collectmsg();
};
void utils::print(string message){
    cout<<message<<" \n";
}
int utils::collect(){
    print("Insert value: ");
    cin>>this->value;
    return this->value;
}
string utils::collectmsg(){
    print("Insert value: ");
    cin.getline(s,50);
    return s;
}
class grades{
    string name;
    int mrk1, mrk2, mrk3, total;
    float average;
    string grade;
    public:
    void construct(int mrk1, int mrk2, int mrk3, string name);
    void mutatename(string name);
    void mutatemark1(int mrk1);
    void mutatemark2(int mrk2);
    void mutatemark3(int mrk3);
    string accessorname();
    int accessormark1();
    int accessormark2();
    int accessormark3();
    int computetotal();
    float computeaverage();
    string computegrade();
    bool inspectorpass(string grade);
    void destructor();
};
void grades::construct(int mrk1, int mrk2, int mrk3, string name){
    mutatename(name);
    mutatemark1(mrk1);
    mutatemark2(mrk2);
    mutatemark3(mrk3);
}
void grades::mutatename(string name){
    this->name=name;
}
void grades::mutatemark1(int mrk1){
    this->mrk1=mrk1;
}
void grades::mutatemark2(int mrk2){
    this->mrk2=mrk2;
}
void grades::mutatemark3(int mrk3){
    this->mrk3=mrk3;
}
string grades::accessorname(){
    return this->name;
}
int grades::accessormark1(){
    return this->mrk1;
}
int grades::accessormark2(){
    return this->mrk2;
}
int grades::accessormark3(){
    return this->mrk3;
}
int grades::computetotal(){
    return this->mrk1+this->mrk2+this->mrk3;
}
float grades::computeaverage(){
    return computetotal()/3;
}
string grades::computegrade(){
    if (computeaverage()>60){
        return "A";
    } else if (computeaverage()<40){
        return "C";
    } else {
        return "B";
    }
}
bool grades::inspectorpass(string grade){
    utils ut;
    if (grade=="A"){
        ut.print("The student has been approved.");
        return true;
    } else {
        ut.print("The student has failed the period.");
        return false;
    }
}
void grades::destructor(){
    utils ut;
    ut.print("Destructor invoked and executed. ");
}
int main(){
    utils ut;
    grades grd;
    string name;
    int a,b,c;
    ut.print("Welcome to the grader. ");
    ut.print("Insert the name of the student followed by the 3 marks. ");
    grd.construct(ut.collect(),ut.collect(),ut.collect(),ut.collectmsg());
    ut.print("The student name is: ");
    ut.print(grd.accessorname());
    ut.print("First mark is: ");
    ut.print(to_string(grd.accessormark1()));
    ut.print("Second mark is: ");
    ut.print(to_string(grd.accessormark2()));
    ut.print("Third mark is: ");
    ut.print(to_string(grd.accessormark3()));
    ut.print("Total mark is: ");
    ut.print(to_string(grd.computetotal()));
    ut.print("Average mark is: ");
    ut.print(to_string(grd.computeaverage()));
    ut.print("General grade is: ");
    ut.print(grd.computegrade());
    ut.print("Did the student passed the curse? ");
    grd.inspectorpass(grd.computegrade());
    ut.print("Attempting to call destructor ");
    grd.destructor();
}