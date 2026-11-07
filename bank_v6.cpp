#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
class Account 
{
    //friend class Bank;
    private:
    int ac_no;
    std::string name,pass;
    float balance;
    public:
    Account() : ac_no(0), balance(0) {}
    Account(int ac,std::string name,float bal,std::string pass)
        :ac_no(ac),name(name),balance(bal),pass(pass)
    {
    }
    std::string getname() const
    {
        return name;
    }
    int getacno() const
    {
        return ac_no;
    }
    float getbal() const
    {
        return balance;
    }
    std::string getpass() const
    {
        return pass;
    }
    void setname(std::string newname)
    {
        name=newname;
    }
    bool adbal(float amount)
    {
        if(amount<=0)
        {
            return false;
        }
        balance+=amount;
        return true;
    }
    bool subal(float amount)
    {
        if(balance>=amount && amount>0)
        {
            balance-=amount;
            return true;
        }
        return false;
    }
};
class transaction
{
    friend class Bank;
    private:
    int transactionid,reac,sendac;
    float amount;
    std::string type; 
    public:
   /* transaction(std::string type,int sendac,int reac,float amount)
    :transactionid(transactionid),type(type),sendac(sendac),reac(reac),amount(amount)
    {   
    }*/
    transaction(std::string type,float amount):
    transactionid(transactionid),type(type),amount(amount)
    {}
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
    float setbal()
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
        std::cout<<"Name : "<<accounts[ac].getname()<<std::endl
        <<"Account number : "<<accounts[ac].getacno()<<std::endl
        <<"balance : "<<accounts[ac].getbal()<<std::endl
        <<"------------------------------------"<<std::endl;
    }
    void depositead()
    {
        int i =getac();
        float depo;
        while(true)
        {
            std::cout<<"Enter amount to be deposited : ";
            std::cin>>depo;
            if(accounts[i].adbal(depo))
            {
                std::cout<<depo<<" has been credited successfully"<<std::endl;
                break;
            }
            else
            {
                std::cout<<"Invalid amount !"<<std::endl;
            }
        }
    }
    void withdrawad()
    {
        int i =getac();
        float with;
        while (true)
        {
            std::cout<<"Enter the amount to be withdrawn : ";
            std::cin>>with;
            if(accounts[i].subal(with))
            {
                std::cout<<with<<"has been debited successfully"<<std::endl;
                break;
            }
            else
            {
                std::cout<<"Insufficient balance ! OR Invalid amount"<<std::endl;
            }
        }   
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
        for(const auto& x:accounts)
        {
            std::cout<<"Name : "<<x.second.getname()<<std::endl
            <<"Account number : "<<x.first<<std::endl
            <<"Balance : "<<x.second.getbal()<<std::endl
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
        accounts[ac_no].setname(name);
        std::cout<<"-------------------YK---Bank-------------------------"<<std::endl;
        std::cout<<"Name : "<<accounts[ac_no].getname()<<std::endl;
        std::cout<<"Account number : "<<accounts[ac_no].getacno()<<std::endl;
        std::cout<<"Balance : "<<accounts[ac_no].getbal()<<std::endl;
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
        float amount;
        if(transfr!=transto)
        {
            std::cout<<"Enter the amount to be transfered : ";
            std::cin>>amount;
            if(accounts[transfr].subal(amount)&&accounts[transto].adbal(amount))
            {
                std::cout<<"Transaction Done ! "<<std::endl;
            }
            /*if(accounts[transfr].getacno()==transfr)
            {
                accounts[transfr].balance=accounts[transfr].balance-amount;
            }
            if(accounts[transto].getacno()==transto)
            {
                accounts[transto].balance=accounts[transto].balance+amount;
                std::cout<<"Transaction Done !"<<std::endl;
            }*/             
        }
        else
        {
            std::cout<<"Invalid input !"<<std::endl;
            menuad();
        }

    }
    void loadfromfile()
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
    void rewritefile()
    {
        std::ofstream fout("acc.txt");
        for(const auto& x:accounts)
        {
            fout<<x.second.getname()<<"  "<<x.second.getacno()<<"  "<<x.second.getbal()<<"  "<<x.second.getpass()<<std::endl;
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
    void withdrawuser()
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
    void transferuser()
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
                        historyinput(amount);
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
    void displaymy()
    {
        std::cout<<"-------------------------YK--Bank--------------------------"<<std::endl;
        std::cout<<"Name : "<<accounts[currentindex].getname()<<std::endl
        <<"Account number : "<<accounts[currentindex].getacno()<<std::endl
        <<"balance : "<<accounts[currentindex].getbal()<<std::endl
        <<"------------------------------------"<<std::endl;
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
    void historyinput(float amount)
    {
        transaction t;
        std::string filename=std::to_string(accounts[currentindex].getacno());
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
        std::string filename=std::to_string(accounts[currentindex].getacno());
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
