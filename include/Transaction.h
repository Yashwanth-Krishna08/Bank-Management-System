#pragma once
#include<string>
class transaction
{
    friend class bank;
    private:
    int transactionid,reac,sendac;
    float amount;
    std::string type; 
    public:
    transaction(int transactionid,std::string type,int sendac,int reac,float amount);
    transaction(int transactionid,std::string type,float amount);
    transaction(); 
};