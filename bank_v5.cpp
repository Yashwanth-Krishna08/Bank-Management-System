#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
class Account 
{
    friend class Bank;
    private:
    int ac_no;
    std::string name,pass;
    float balance;
    public:
    Account()
    {

    }
    Account(int ac,std::string name,float bal,std::string pass)
        :ac_no(ac),name(name),balance(bal),pass(pass)
    {
    }
};
class transaction
{
    friend class Bank;
    private:
    float amount;
    std::string type; 
    public:
    transaction(std::string type,float amount)
    :type(type),amount(amount)
    {   
    }
    transaction()
    {}        
};
class Bank
{
    private:
    int currentindex=-1;
    std::unordered_map<int,Account> accounts;
    std::stack<transaction> s;
    int isdepo;
    public:
    void create()
    {
        int ac;
        std::string pass,name;
        float balance;
        std::ofstream fout("ac.txt",std::ios::app);
        ac=acvalid();
        std::cin.ignore();
        std::cout<<"Enter your name : "<<std::endl;
        getline(std::cin,name);
        balance=validamountfordepo();
        std::cout<<"Enter your security pin (you can change later):"<<std::endl;
        std::cin>>pass;
        Account a(ac,name,balance,pass);
        accounts[ac]=a;
        fout<<a.name<<"  "<<a.ac_no<<"  "<<a.balance<<"  "<<a.pass<<std::endl;
        fout.close();
    }
    int acvalid()
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
    void display()
    {
        std::cout<<"-------------------------YK--Bank--------------------------"<<std::endl;
        int ac =getac();
        std::cout<<"Name : "<<accounts[ac].name<<std::endl
        <<"Account number : "<<accounts[ac].ac_no<<std::endl
        <<"balance : "<<accounts[ac].balance<<std::endl
        <<"------------------------------------"<<std::endl;
    }
    void depositead()
    {
        float depo=validamountfordepo();
        int i =getac();
        accounts[i].balance=accounts[i].balance+depo;
        std::cout<<depo<<" has been credited successfully"<<std::endl;
    }
    void withdrawad()
    {
        int i =getac();
        float with=validamountadmin(i);
        accounts[i].balance=accounts[i].balance-with;
        std::cout<<with<<"has been debited successfully"<<std::endl;
    }
    void menuad()
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
    void alldis()
    {
        
        std::cout<<"-------------------------YK--Bank--------------------------"<<std::endl;
        for(const auto x:accounts)
        {
            std::cout<<"Name : "<<x.second.name<<std::endl
            <<"Account number : "<<x.first<<std::endl
            <<"Balance : "<<x.second.balance<<std::endl
            <<"_________________________________________________________________"<<std::endl;

        }
    }
    void updatename()
    {
        int ac_no=getac();
        std::cin.ignore();
        std::cout<<"Enter the new name : "<<std::endl;
        std::string name;
        getline(std::cin,name);
        accounts[ac_no].name=name;
        std::cout<<"-------------------YK---Bank-------------------------"<<std::endl;
        std::cout<<"Name : "<<accounts[ac_no].name<<std::endl;
        std::cout<<"Account number : "<<accounts[ac_no].ac_no<<std::endl;
        std::cout<<"Balance : "<<accounts[ac_no].balance<<std::endl;
        std::cout<<"______________________________________________________________________"<<std::endl;
    }
    void updatedetails()       //Future updation
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
    void transferad()
    {
        std::cout<<"------Transfer---From--------"<<std::endl;
        int transfr=getac();
        std::cout<<"------Transfer---To----------"<<std::endl;
        int transto=getac();
        float amount=validamountadmin(transfr);
        if(transfr!=transto)
        {
            if(accounts[transfr].ac_no==transfr)
            {
                accounts[transfr].balance=accounts[transfr].balance-amount;
            }
            if(accounts[transto].ac_no==transto)
            {
                accounts[transto].balance=accounts[transto].balance+amount;
                std::cout<<"Transaction Done !"<<std::endl;
            }             
        }
        else
        {
            std::cout<<"Invalid input !"<<std::endl;
            menuad();
        }

    }
    void loadfromfile()
    {
        Account a;
        accounts.clear();
        std::ifstream fin("acc.txt");
        while(fin>>a.name>>a.ac_no>>a.balance>>a.pass)
        {
            accounts[a.ac_no]=a;
        }
    }
    void rewritefile()
    {
        std::ofstream fout("acc.txt");
        for(const auto& x:accounts)
        {
            fout<<x.second.name<<"  "<<x.second.ac_no<<"  "<<x.second.balance<<"  "<<x.second.pass<<std::endl;
        }
        fout.close();
    }
    void start()
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
    void loginad()
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
    void login()
    {
        std::cout<<"---------------------User--Login---------------"<<std::endl;
        int ac=getac();
        std::string password;
        std::cout<<"Enter your security pin : "<<std::endl;
        std::cin>>password;
        if(accounts[ac].pass==password)
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
    void menuser()
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
    void deposituser()
    {
        if(accounts.find(currentindex)!=accounts.end())
        {
            isdepo=1;
            float amount=validamountfordepo();
            accounts[currentindex].balance+=amount;
            historyinput(amount);
            std::cout<<amount<<"  has been credited successfully"<<std::endl;
            std::cout<<"Your account balance is : "<<accounts[currentindex].balance<<std::endl;
        }
        else
        {
            std::cout<<"Account not found"<<std::endl;
            login();
        }
        
    }
    void withdrawuser()
    {
        if(accounts.find(currentindex)!=accounts.end())
        {
            isdepo=2;
            float amount=validamountuser();
            accounts[currentindex].balance-=amount;
            historyinput(amount);
            std::cout<<amount<<" has been debited successfully"<<std::endl;
            std::cout<<"Your account balance is : "<<accounts[currentindex].balance<<std::endl;
            
        }
        else
        {
            std::cout<<"Account not fount "<<std::endl;
            login(); 
        }
    }
    void transferuser()
    {
        int tranto=getac();
        float amount=validamountuser();
        if(accounts[currentindex].ac_no!=tranto)
        {
            accounts[currentindex].balance-=amount;
            accounts[tranto].balance+=amount;
            isdepo=3;
            historyinput(amount);
            std::cout<<amount<<" has been transfered successfully"<<std::endl;
            std::cout<<"Your account balance is : "<<accounts[currentindex].balance;
       
        }
        else
        {
            std::cout<<"Invalid input !"<<std::endl;
        }
    }
    void displaymy()
    {
        std::cout<<"-------------------------YK--Bank--------------------------"<<std::endl;
        std::cout<<"Name : "<<accounts[currentindex].name<<std::endl
        <<"Account number : "<<accounts[currentindex].ac_no<<std::endl
        <<"balance : "<<accounts[currentindex].balance<<std::endl
        <<"------------------------------------"<<std::endl;
    }
    float validamountuser()
    {
        float amount;
        do{
            std::cout<<"Enter the amount : "<<std::endl;
            std::cin>>amount;
            if(amount<=0)
            {
                std::cout<<"Invalid amount !"<<std::endl;
            }
            else if(accounts[currentindex].balance<amount)
            {
                std::cout<<"Insufficient balance ! "<<std::endl;
            }
        }while(amount<=0||accounts[currentindex].balance<amount);
        return amount;
    }
    float validamountfordepo()
    {
        float amount;
        do{
            std::cout<<"Enter the amount to be deposited : "<<std::endl;
            std::cin>>amount;
            if(amount<=0)
            {
                std::cout<<"Invalid input !"<<std::endl;
            } 
        }while(amount<=0);
        return amount;
    }
    float validamountadmin(int n)
    {
        float amount;
        int pos=n;
        do{
            std::cout<<"Enter the amount :"<<std::endl;
            std::cin>>amount;
            if(amount<=0)
            {
                std::cout<<"Invalid input !"<<std::endl;
            }
            else if(accounts[pos].balance<amount)
            {
                std::cout<<"Insufficient balance !"<<std::endl;
            }
        }while(amount<=0||accounts[pos].balance<amount);
        return amount;
    }
    int getac()
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
    void historyinput(int amount)
    {
        transaction t;
        std::string filename=std::to_string(accounts[currentindex].ac_no);
        filename.append(".txt");
        std::ofstream fout(filename,std::ios::app);
        switch (isdepo)
        {
        case 1:
            t.type="Deposite";
            t.amount=+amount;
            s.push(t);
            break;
        case 2:
            t.type="Withdraw";
            t.amount=-amount;
            s.push(t);
            break;
        case 3:
            t.type="Transfer";
            t.amount=-amount;
            s.push(t);
            break;
        
        }
        fout<<s.top().type<<"  "<<s.top().amount<<std::endl;
        fout.close();
    }
    void loadfromhistory()
    {
        std::string filename=std::to_string(accounts[currentindex].ac_no);
        filename.append(".txt");
        std::ifstream fin(filename);
        std::string type;
        float am;
        while(fin>>type>>am)
        {
            transaction t(type,am);
            s.push(t);
        }
    }
    void displayhis()
    {
        std::stack<transaction> temp=s;
        std::cout<<"-----------------Transaction--History----------------------"<<std::endl;
        while(!temp.empty())
        {
            std::cout<<temp.top().type<<"  "<<temp.top().amount<<std::endl;
            temp.pop();
        }
        std::cout<<"------------------------------------------------------------"<<std::endl;
    }
    void releasestack()
    {
        while(!s.empty())
        {
            s.pop();
        }
    }
};
int main()
{
    Bank b;
    b.start();
    return 0;
}
