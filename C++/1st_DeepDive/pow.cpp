#include <iostream>
using namespace std;
int pow(int power, int number)
{
    //////////////////////////
    //Computes the power
    //////////////////////////
    int result=1;
    if(power==1)
    {
        result=number;
    } else if(power!=0){   
        for(int i=1;i<=power;i++)
        {
            result*=number;
        }
    }
    return result;
}
void print_result(int result)
{
    //////////////////////////
    //Prints result
    //////////////////////////
    cout<<"The result is: "<<result<<"\n";
}
int get_input()
{
    //////////////////////////////
    //Gets an input from the user
    //////////////////////////////
    int x;
    cout<<"Insert input: \n";
    cin>>x;
    return x;
}
void welcome_message()
{
    /////////////////////////
    //Prints welcome message
    /////////////////////////
    cout<<"Welcome to the pow computer \n";
    cout<<"In the folling input promts input the power and then the number \n";
    cout<<"Thanks \n";
}
int main()
{
    int power,number,result;
    welcome_message();
    power=get_input();
    number=get_input();
    result=pow(power,number);
    print_result(result);
}