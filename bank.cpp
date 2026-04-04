#include<iostream>
#include<string>
using namespace std;
class Account
{
    private:
    float Balance;
    string Name;
     public:
    Account()
    {
        Name="Unknown";
        Balance=0;
    }
    Account(string Name)
    {
        this->Name=Name;
        Balance=0;
    }
    Account(string Name,float Balance)
    {
        this->Name=Name;
        this->Balance=Balance;
        cout<<"Account created"<<endl;
    }
    void display()
    {
        cout<<"Name: "<<Name<<endl;
        cout<<"Balance: "<<Balance<<endl;
        cout<<"-------------------------"<<endl;
    }
     void depo(float deposit)
    {
        if(deposit>=0)
        {
        this->Balance=Balance+deposit;
        }
        else
        {
            cout<<"Not Valid"<<endl;
        }
    }
    void withdraw(float withdraw)
    {
        if(withdraw>0)
        {
            if(Balance>=withdraw)
            {
                this->Balance=Balance-withdraw;
            }
            else
            {
                cout<<"Insufficient balance"<<endl;
            }
        }
    }
   
    ~Account()
    {
    }
};

int main()
{
    Account a;
    string Name;
    char Y,E;
    float Balance=0,deposite,withdraw;
    cout<<"Enter the Name of Account holder:"<<endl;
    getline(cin,Name);
    Account a1(Name);
    cout<<"Enter the amount to be deposited to your new account:"<<endl;
    cin>>Balance;
    Account a2(Name,Balance);
    a.display();
    a1.display();
    a2.display();
    do{
          cout<<"Enter D for deposite and W for withdraw:"<<endl;
    cin>>Y;
    if(Y=='D'||Y=='d')
    {
        cout<<"Enter amount deposited:" <<endl;
        cin>>deposite;
       a2.depo(deposite);
    }
    else if(Y=='W'||Y=='w')
    {
        cout<<"Enter amount to be withdrawn:"<<endl;
        cin>>withdraw;
        a2.withdraw(withdraw);
    }
    cout<<"Do you want to do more transaction[Y/N]:"<<endl;
    cin>>E;
    }while (E=='Y');  
    a2.display();
    cout<<"Thank you!!"<<endl;
    return 0;
}