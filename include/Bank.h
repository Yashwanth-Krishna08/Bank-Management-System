#pragma once
#include<string>
#include<unordered_map>
#include<stack>
#include "Transaction.h"
#include "Account.h"
class bank
{
    private:
    int currentindex=-1;
    std::unordered_map<int,Account> accounts;
    std::stack<transaction> s;
    int isdepo;
    public:
    void create();
    float setbal();
    int acvalid();
    void display();
    void withdrawad();
    void depositead();
    void menuad();
    void menuser();
    void alldis();
    void updatename();
    void updatedetails();
    void transferad();
    void loadfromfile();
    void start();
    void loginad();
    void login();
    void deposituser();
    void withdrawuser();
    void transferuser();
    void displaymy();
    int getac();
    void rewritefile();
    int getnextid();
    void historyinput(float amount);
    void historyinput(float amount,int acno);
    void historyinput(float amount,int to,int from);
    void loadfromhistory();
    void displayhis();
    void releasestack();
    void setnextid(int id);
};