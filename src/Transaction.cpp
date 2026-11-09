#include "../include/Transaction.h"
transaction::transaction(int transactionid,std::string type,int sendac,int reac,float amount)
:transactionid(transactionid),type(type),sendac(sendac),reac(reac),amount(amount)
{   
}
transaction::transaction(int transactionid,std::string type,float amount):
transactionid(transactionid),type(type),amount(amount)
{}
transaction::transaction()
{}
 