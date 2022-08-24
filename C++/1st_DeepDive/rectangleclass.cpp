#include <iostream>
#include <string>
using namespace std;


class utils
{
    string message;
    int value;
    public:
    void print(string message){
        cout<<message<<" \n";
    }
    int collect(){
        print("Insert value: ");
        cin>>this->value;
        return this->value;
    }
};
class Rectangle{
    int l;
    int h;
public:
    //Constructors
    void construct(int l, int h){
        setl(l);
        seth(h);
    }
    //Mutators
    void setl(int l){
        this->l=l;
    }
    void seth(int h){
        this->h=h;
    }
    //Accessors
    int getl(){
        return this->l;
    }
    int geth(){
        return this->h;
    }
    //Facilitators
    int area(); 
    int perimeter();
    //Inspectors
    bool insp();
    //Destructors
    void dest();

};
bool Rectangle::insp(){
    utils ut;
    if (this->l==this->h){
        ut.print("It is an square");
        return true;
    } else {
        ut.print("It is not square");
        return false;
    }
}
void Rectangle::dest()
{
    utils ut;
    ut.print("Destructor has been executed");
}
int Rectangle::area()
{
    return this->l*this->h;
}
int Rectangle::perimeter()
{
    return 2*(this->l+this->h);
}
int main(){
    Rectangle rt;
    utils ut;
    ut.print("Welcome to rectangle program ");
    ut.print("Insert height followed by the lenght ");
    rt.construct(ut.collect(), ut.collect());
    ut.print("Is it an square? ");
    rt.insp();
    ut.print("h value is: ");
    ut.print(to_string(rt.geth()));
    ut.print("l value is: ");
    ut.print(to_string(rt.getl()));
    ut.print("The area is: ");
    ut.print(to_string(rt.area()));
    ut.print("The perimeter is: ");
    ut.print(to_string(rt.perimeter()));
    ut.print("Done, aiming to destruct: ");
    rt.dest();
}
