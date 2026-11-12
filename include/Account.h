#pragma once
#include<string>
class Account
{
    private:
    int ac_no;
    std::string name,pass;
    float balance;
    public:
    Account();
    Account(int ac_no,std::string name,float balance,std::string pass);
    std::string getname() const;
    int getacno() const;
    float getbal() const;
    std::string getpass() const;
    void setname(std::string newname);
    bool adbal(float amount);
    bool subal(float amount);
    std::string setpass();
};
