#include "../include/Account.h"
#include<iostream>
#include<conio.h>
Account::Account():
ac_no(0),balance(0)
{
}
Account::Account(int ac_no,std::string name,float balance,std::string pass):
ac_no(ac_no),name(name),balance(balance),pass(pass)
{
}
std::string Account::getname() const
{
    return name;
}
int Account::getacno() const
{
    return ac_no;
}
std::string Account::getpass() const
{
    return pass;
}
float Account::getbal() const
{
    return balance;
}
bool Account::adbal(float amount)
{
    if(amount>0)
    {
        balance+=amount;
        return true;
    }
    return false;
}
bool Account::subal(float amount)
{
    if(balance>=amount&&amount>0)
    {
        balance-=amount;
        return true;
    }
    return false;
}
std::string Account::setpass()
{
    std::string pass;
    char c;
    std::cout<<"Enter the password : ";
    while(true)
    {
        c=_getch();
        if(c=='\r')
        {
            break;
        }
        if(c=='\b')
        {
            if(!pass.empty())
            {
                pass.pop_back();
                std::cout<<"\b \b";
            }
            continue;
        }
        pass+=c;
        std::cout<<"*";
    }
    std::cout<<std::endl;
    return pass;
}
void Account::setname(std::string newname)
{
    name=newname;
}