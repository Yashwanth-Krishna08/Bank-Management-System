#include "../include/Bank.h"
#include "../include/Account.h"
#include "../include/Transaction.h"
#include<iostream>
#include<string>
#include<fstream>
void bank::create()
{
    int ac;
    std::string pass,name;
    float balance;
    std::ofstream fout("acc.txt",std::ios::app);
    ac=acvalid();
    std::cin.ignore();
    std::cout<<"Enter your name : "<<std::endl;
    getline(std::cin,name);
    balance=setbal();
    std::cout<<"Enter your security pin (you can change later):"<<std::endl;
    std::cin>>pass;
    Account a(ac,name,balance,pass);
    accounts[ac]=a;
    fout<<a.getname()<<"  "<<a.getacno()<<"  "<<a.getbal()<<"  "<<a.getpass()<<std::endl;
    fout.close();
}
float bank::setbal()
{
    float amount;
    do
    {
       std::cout<<"Enter the amount to be deposited : ";
       std::cin>>amount;
       if(amount<0)
        {
            std::cout<<"Invalid amount !"<<std::endl;
        }
        else
        {
            return amount;
        }
    } while (amount<0);
}
int bank::acvalid()
{
    int ac_no;
    bool found;
    do{
        std::cout<<"Enter your account number : "<<std::endl;
        std::cin>>ac_no;
        if(accounts.find(ac_no)!=accounts.end())
        {
            found=true;
            std::cout<<"Invalid input !"<<std::endl;
        }
        else
        {
            found=false;
        }
    }while(found);
    return ac_no;
}
void bank::display()
{
    std::cout<<"-------------------------YK--Bank--------------------------"<<std::endl;
    int ac =getac();
    std::cout<<"Name : "<<accounts[ac].getname()<<std::endl
    <<"Account number : "<<accounts[ac].getacno()<<std::endl
    <<"balance : "<<accounts[ac].getbal()<<std::endl
    <<"------------------------------------"<<std::endl;
}
void bank::depositead()
{
    int i =getac();
    float depo;
    isdepo=1;
    while(true)
    {
        std::cout<<"Enter amount to be deposited : ";
        std::cin>>depo;
        if(accounts[i].adbal(depo))
        {
            std::cout<<depo<<" has been credited successfully"<<std::endl;
            historyinput(depo,i);
            break;
        }
        else
        {
            std::cout<<"Invalid amount !"<<std::endl;
        }
    }    
}
void bank::withdrawad()
{        
    int i =getac();
    float with;
    isdepo=2;
    while (true)
    {
        std::cout<<"Enter the amount to be withdrawn : ";
        std::cin>>with;
        if(accounts[i].subal(with))
        {
            historyinput(with,i);
            std::cout<<with<<"has been debited successfully"<<std::endl;
            break;
        }
        else
        {
            std::cout<<"Insufficient balance ! OR Invalid amount"<<std::endl;
        }
    } 
}
void bank::menuad()
{
        
    int choice;
    std::cout<<"-------------------Menu--Admin---------------------"<<std::endl;
    do{
        std::cout<<"1.Create account "<<std::endl;
        std::cout<<"2.Deposit"<<std::endl;
        std::cout<<"3.Withdraw"<<std::endl;
        std::cout<<"4.Display a account with account number"<<std::endl;
        std::cout<<"5.Show All accounts"<<std::endl;
        std::cout<<"6.Transfer to other account"<<std::endl;
        std::cout<<"7.Update details "<<std::endl;
        std::cout<<"8.Exit"<<std::endl;
        std::cout<<"Your choice : ";
        std::cin>>choice;
        switch (choice)
        {
            case 1:
                create();
                break;
            case 2:
                depositead();
                break;
            case 3:
                withdrawad();
                break;
            case 4:
                display();
                break;
            case 5:
                alldis();
                break;  
            case 6:
                transferad();
                break;  
            case 7:
                updatedetails();
                break;       
            }
        }while(choice!=8);
    rewritefile();
    std::cout<<"----------Thank--You---------------"<<std::endl;
}
void bank::alldis()
{
        
    std::cout<<"-------------------------YK--Bank--------------------------"<<std::endl;
    for(const auto& x:accounts)
    {
        std::cout<<"Name : "<<x.second.getname()<<std::endl
        <<"Account number : "<<x.first<<std::endl
        <<"Balance : "<<x.second.getbal()<<std::endl
        <<"_________________________________________________________________"<<std::endl;

    }
}
void bank::updatename()
{
    int ac_no=getac();
    std::cin.ignore();
    std::cout<<"Enter the new name : "<<std::endl;
    std::string name;
    getline(std::cin,name);
    accounts[ac_no].setname(name);
    std::cout<<"-------------------YK---Bank-------------------------"<<std::endl;
    std::cout<<"Name : "<<accounts[ac_no].getname()<<std::endl;
    std::cout<<"Account number : "<<accounts[ac_no].getacno()<<std::endl;
    std::cout<<"Balance : "<<accounts[ac_no].getbal()<<std::endl;
    std::cout<<"______________________________________________________________________"<<std::endl;
}
void bank::updatedetails()
{
    
    int p;
            
    std::cout<<"1.To update name"<<std::endl<<"2.To update pin"<<std::endl;
    std::cin>>p;
    switch (p)
    {
    case 1:
    updatename();
    break;
    case 2:
    break;
    default:
    break;
    }
        
    
}
void bank::transferad()
{
    std::cout<<"------Transfer---From--------"<<std::endl;
    int transfr=getac();
    std::cout<<"------Transfer---To----------"<<std::endl;
    int transto=getac();
    float amount;
    if(transfr!=transto)
    {
        std::cout<<"Enter the amount to be transfered : ";
        std::cin>>amount;
        if(accounts[transfr].subal(amount))
        {
        if(accounts[transto].adbal(amount))
        {
                std::cout<<"Transaction Done ! "<<std::endl;
                historyinput(amount,transto,transfr);
        }
        else
        {
            accounts[transfr].adbal(amount);
        }    
        }
        else
        {
            std::cout<<"Insufficient balance ! OR Invalid amount"<<std::endl;
        }            
    }
    else
    {
        std::cout<<"Invalid input !"<<std::endl;
        menuad();
    }

}
void bank::loadfromfile()
{
    std::string name , pass;
    int acno;
    float bal;
    std::ifstream fin("acc.txt");
    while(fin>>name>>acno>>bal>>pass)
    {
        Account a(acno,name,bal,pass);
        accounts[acno]=a;
    }
    fin.close();
}
void bank::rewritefile()
{
    std::ofstream fout("acc.txt");
    for(const auto& x:accounts)
    {
        fout<<x.second.getname()<<"  "<<x.second.getacno()<<"  "<<x.second.getbal()<<"  "<<x.second.getpass()<<std::endl;
    }
    fout.close();
}
void bank::start()
{
    loadfromfile();
    int n;
    do
    {
        std::cout<<"1.User Sign Up"<<std::endl;
        std::cout<<"2.User Sign In"<<std::endl;
        std::cout<<"3.Admin Sign Up"<<std::endl;
        std::cout<<"Your choice : ";
        std::cin>>n;
        switch (n)
        {
        case 1:
            std::cout<<"----------------------Sign--Up-------------------"<<std::endl;
            create();
            login();
            break;
        case 2:
            login();
            break;
        case 3:
            loginad();
            break;
        default:
            std::cout<<"Invalid input"<<std::endl;
            break;
        } 
    } while (n<1||n>3);
    
}
void bank::loginad()
{
    std::cout<<"---------------Admin--Login------------------"<<std::endl;
    std::string passadmin;
    std::cout<<"Enter the password : "<<std::endl;
    std::cin>>passadmin;
    if(passadmin=="Admin@223")
    {
        menuad();
    }
    else 
    {
        std::cout<<"Wrong Password !"<<std::endl;
        loginad();
    }
}
void bank::login()
{
    std::cout<<"---------------------User--Login---------------"<<std::endl;
    int ac=getac();
    std::string password;
    std::cout<<"Enter your security pin : "<<std::endl;
    std::cin>>password;
    if(accounts[ac].getpass()==password)
    {
        currentindex=ac;
        menuser();
    }
    else
    {
        std::cout<<"Wrong Password !"<<std::endl;
        start();
    }
}
void bank::menuser()
{
    loadfromhistory();
    int choice;
    std::cout<<"-----------Menu--User----------------"<<std::endl;
    do{
        std::cout<<"1.Deposit"<<std::endl;
        std::cout<<"2.Withdraw"<<std::endl;
        std::cout<<"3.Transfer to other account"<<std::endl;
        std::cout<<"4.Display account details"<<std::endl;
        std::cout<<"5.Display Transaction History"<<std::endl;
        std::cout<<"6.Exit"<<std::endl;
        std::cout<<"Your choice : ";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            deposituser();
            break;
        case 2:
            withdrawuser();
            break; 
        case 3:
            transferuser();
            break;  
        case 4:
            displaymy();
            break;
        case 5:
            displayhis();
            break;           
        }
    }while(choice!=6);
    rewritefile();
    releasestack();
    std::cout<<"----------Thank--You---------------"<<std::endl;
}
void bank::deposituser()
{
    if(accounts.find(currentindex)!=accounts.end())
    {
        isdepo=1;
        float amount;
        while(true)
        {
            std::cout<<"Enter the amount : "<<std::endl;
            std::cin>>amount;
            if(accounts[currentindex].adbal(amount))
            {
                historyinput(amount);
                std::cout<<amount<<"  has been credited successfully"<<std::endl;
                std::cout<<"Your account balance is : "<<accounts[currentindex].getbal()<<std::endl;
                break;
            }
            else
            {
                std::cout<<"Invalid amount"<<std::endl;
            }
        }
    }
    else
    {
        std::cout<<"Account not found"<<std::endl;
        login();
    }
    
}
void bank::withdrawuser()
{
    if(accounts.find(currentindex)!=accounts.end())
    {
        isdepo=2;
        float amount;
        while(true)
        {
            std::cout<<"Enter the amount : "<<std::endl;
            std::cin>>amount;
            if(accounts[currentindex].subal(amount))
            {
                historyinput(amount);
                std::cout<<amount<<" has been debited successfully"<<std::endl;
                std::cout<<"Your account balance is : "<<accounts[currentindex].getbal()<<std::endl;
                break;
            }
            else
            {
                std::cout<<"Insufficient balance ! OR Invalid amount"<<std::endl;
            }
        }
    }
    else
    {
        std::cout<<"Account not fount "<<std::endl;
        login(); 
    }
}
void bank::transferuser()
{
    int tranto=getac();
    if(accounts[currentindex].getacno()!=tranto)
    {
        isdepo=3;
        float amount;
        while(true)
        {
            std::cout<<"Enter the amount : "<<std::endl;
            std::cin>>amount;
            if(accounts[currentindex].subal(amount))
            {
                
                if(accounts[tranto].adbal(amount))
                {
                    historyinput(amount,tranto,accounts[currentindex].getacno());
                    std::cout<<amount<<" has been transfered successfully"<<std::endl;
                    std::cout<<"Your account balance is : "<<accounts[currentindex].getbal();
                    break;
                }
                else
                {
                    accounts[currentindex].adbal(amount);
                }
            }
            else
            {

                std::cout<<"Insufficient balance ! OR Invalid amount"<<std::endl;
            }
        }
    }
    else
    {
        std::cout<<"Invalid input !"<<std::endl;
    }
}
void bank::displaymy()
{
    std::cout<<"-------------------------YK--Bank--------------------------"<<std::endl;
    std::cout<<"Name : "<<accounts[currentindex].getname()<<std::endl
    <<"Account number : "<<accounts[currentindex].getacno()<<std::endl
    <<"balance : "<<accounts[currentindex].getbal()<<std::endl
    <<"------------------------------------"<<std::endl;
}

int bank::getac()
{
    bool found;
    int ac;
    do{
        std::cout<<"Enter account number : "<<std::endl;
        std::cin>>ac;
        if(accounts.find(ac)!=accounts.end())
        {
            found=true;
        }
        else
        {
            std::cout<<"Not Found !!"<<std::endl;
            found=false;
        }
    }while(!found);
    return ac;
}
int bank::getnextid()
{
    std::ifstream fin("nextid.txt");
    int id;
    fin >> id;
    fin.close();
    return id;
}
void bank::setnextid(int id)
{
    std::ofstream fout("nextid.txt");
    fout<<id;
    fout.close();
}
void bank::historyinput(float amount)
{
    transaction t;
    int id=getnextid()+1;
    std::string filename=std::to_string(accounts[currentindex].getacno());
    filename.append(".txt");
    std::ofstream fout(filename,std::ios::app);
    switch (isdepo)
    {
    case 1:
        t.transactionid=id;
        t.type="Deposite";
        t.amount=+amount;
        s.push(t);
        break;
    case 2:
        t.transactionid=id;
        t.type="Withdraw";
        t.amount=-amount;
        s.push(t);
        break;
    }
    setnextid(id);
    fout<<s.top().transactionid<<" "<<s.top().type<<"  "<<s.top().amount<<std::endl;
    fout.close();
}
void bank::historyinput(float amount,int acno)
{
    transaction t;
    int id=getnextid()+1;
    std::string filename=std::to_string(acno);
    filename.append(".txt");
    std::ofstream fout(filename,std::ios::app);
    switch (isdepo)
    {
    case 1:
        t.transactionid=id;
        t.type="Deposite";
        t.amount=+amount;
        s.push(t);
        break;
    case 2:
        t.transactionid=id;
        t.type="Withdraw";
        t.amount=-amount;
        s.push(t);
        break;
    }
    setnextid(id);
    fout<<s.top().transactionid<<" "<<s.top().type<<"  "<<s.top().amount<<std::endl;
    fout.close();
}
void bank::historyinput(float amount,int to,int from)
{
    transaction t;
    int id=getnextid()+1;
    std::string filename=std::to_string(from);
    filename.append(".txt");
    std::ofstream fout(filename,std::ios::app);
    t.transactionid=id;
    t.type="Transfer";
    t.sendac=from;
    t.reac=to;
    t.amount=-amount;
    s.push(t);
    setnextid(id);
    fout<<s.top().transactionid<<" "<<s.top().type<<"  "<<s.top().sendac<<" "<<s.top().reac<<" "<<s.top().amount<<std::endl;
    fout.close();
    std::string filename1=std::to_string(to);
    filename1.append(".txt");
    std::ofstream out(filename1,std::ios::app);
    t.amount=amount;
    out<<t.transactionid<<" "<<t.type<<"  "<<t.sendac<<" "<<t.reac<<" "<<t.amount<<std::endl;
    out.close();
}
void bank::loadfromhistory()
{
    std::string filename=std::to_string(accounts[currentindex].getacno());
    filename.append(".txt");
    std::ifstream fin(filename);
    int id;
    std::string type;
    float am;
    while(fin>>id>>type>>am)
    {
        transaction t(id,type,am);
        s.push(t);
    }
}
void bank::displayhis()
{
    std::stack<transaction> temp=s;
    std::cout<<"-----------------Transaction--History----------------------"<<std::endl;
    while(!temp.empty())
    {
        std::cout<<temp.top().transactionid<<" "<<temp.top().type<<"  "<<temp.top().amount<<std::endl;
        temp.pop();
    }
    std::cout<<"------------------------------------------------------------"<<std::endl;
}
void bank::releasestack()
{
    while(!s.empty())
    {
        s.pop();
    }
}
