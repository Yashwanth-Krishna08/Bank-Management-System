#include<iostream>
#include<string>
#include<fstream>
#include<vector>
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
    std::stack<transaction> s;
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
    std::vector<Account> acc;
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
        acc.push_back(a);
        fout<<a.name<<"  "<<a.ac_no<<"  "<<a.balance<<"  "<<a.pass<<std::endl;
        fout.close();
    }
    int acvalid()
    {
        int ac_no,pos=-1;
        do{
            pos=-1;
            std::cout<<"Enter your account number : "<<std::endl;
            std::cin>>ac_no;
            for(int i =0 ;i<acc.size();i++)
            {
                if(acc[i].ac_no==ac_no)
                {
                    pos=i;
                    std::cout<<"Invalid input !"<<std::endl;
                    break;
                }
            }
        }while(pos!=-1);
        return ac_no;
    }
    void display()
    {
        int n;
        std::cout<<"Enter account number : "<<std::endl;
        std::cin>>n;
        std::cout<<"-------------------------YK--Bank--------------------------"<<std::endl;
        int i =searchac(n);
        std::cout<<"Name : "<<acc[i].name<<std::endl
        <<"Account number : "<<acc[i].ac_no<<std::endl
        <<"balance : "<<acc[i].balance<<std::endl
        <<"------------------------------------"<<std::endl;
    }
    void depositead()
    {
        int n;
        std::cout<<"Enter account number : "<<std::endl;
        std::cin>>n;
        float depo=validamountfordepo();
        int i =searchac(n);
        acc[i].balance=acc[i].balance+depo;
        std::cout<<depo<<" has been credited successfully"<<std::endl;
    }
    void withdrawad()
    {
       
        int n;
        std::cout<<"Enter account number : "<<std::endl;
        std::cin>>n;
        float with=validamountadmin(n);
        int i =searchac(n);
        acc[i].balance=acc[i].balance-with;
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
        for(int i = 0;i<acc.size();i++)
        {
            std::cout<<"Name : "<<acc[i].name<<std::endl
            <<"Account number : "<<acc[i].ac_no<<std::endl
            <<"Balance : "<<acc[i].balance<<std::endl
            <<"_________________________________________________________________"<<std::endl;

        }
    }
    int isac()
    {
        int ac_no,pos=-1;
        do
        {
            pos=-1;
            std::cout<<"Enter account number : "<<std::endl;
            std::cin>>ac_no;
            for(int i =0;i<acc.size();i++)
            {
                if(acc[i].ac_no==ac_no)
                {
                    pos=i;
                }
            }
            if(pos==-1)
            {
                std::cout<<"Account not found !"<<std::endl;
            }
        } while (pos==-1);
        return ac_no;
    }
    void updatename()
    {
        int ac_no=isac();
        int pos =searchac(ac_no);
        std::cin.ignore();
        std::cout<<"Enter the new name : "<<std::endl;
        std::string name;
        getline(std::cin,name);
        acc[pos].name=name;
        std::cout<<"-------------------YK---Bank-------------------------"<<std::endl;
        std::cout<<"Name : "<<acc[pos].name<<std::endl;
        std::cout<<"Account number : "<<acc[pos].ac_no<<std::endl;
        std::cout<<"Balance : "<<acc[pos].balance<<std::endl;
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
        int transfr=isac();
        std::cout<<"------Transfer---To----------"<<std::endl;
        int transto=isac();
        float amount=validamountadmin(transfr);
        if(transfr!=transto)
        {
            for(int i = 0;i<acc.size();i++)
            {
                if(acc[i].ac_no==transfr)
                {
                    acc[i].balance=acc[i].balance-amount;
                }
                if(acc[i].ac_no==transto)
                {
                    acc[i].balance=acc[i].balance+amount;
                    std::cout<<"Transaction Done !"<<std::endl;
                }

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
        acc.clear();
        std::ifstream fin("ac.txt");
        while(fin>>a.name>>a.ac_no>>a.balance>>a.pass)
        {
            acc.push_back(a);
        }
    }
    void rewritefile()
    {
        std::ofstream fout("ac.txt");
        for(int i=0;i<acc.size();i++)
        {
            fout<<acc[i].name<<"  "<<acc[i].ac_no<<"  "<<acc[i].balance<<"  "<<acc[i].pass<<std::endl;
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
        int ac=isac();
        std::string password;
        std::cout<<"Enter your security pin : "<<std::endl;
        std::cin>>password;
        int i =searchac(ac);
        if(acc[i].pass==password)
        {
            currentindex=i;
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
        if(currentindex==-1)
        {
            std::cout<<"Account not found"<<std::endl;
            login();
        }
        else
        {
            isdepo=1;
            float amount=validamountfordepo();
            acc[currentindex].balance+=amount;
            historyinput(amount);
            std::cout<<amount<<"  has been credited successfully"<<std::endl;
            std::cout<<"Your account balance is : "<<acc[currentindex].balance<<std::endl;

        }
        
    }
    void withdrawuser()
    {
        if(currentindex==-1)
        {
            std::cout<<"Account not fount "<<std::endl;
            login();
        }
        else
        {
            isdepo=2;
            float amount=validamountuser();
            acc[currentindex].balance-=amount;
            historyinput(amount);
            std::cout<<amount<<" has been debited successfully"<<std::endl;
            std::cout<<"Your account balance is : "<<acc[currentindex].balance<<std::endl;
        }
    }
    void transferuser()
    {
        int tranto=isac();
        float amount=validamountuser();
        if(acc[currentindex].ac_no!=tranto)
        {
            int i =searchac(tranto);
            acc[currentindex].balance-=amount;
            acc[i].balance+=amount;
            isdepo=3;
            historyinput(amount);
            std::cout<<amount<<" has been transfered successfully"<<std::endl;
            std::cout<<"Your account balance is : "<<acc[currentindex].balance;
       
        }
        else
        {
            std::cout<<"Invalid input !"<<std::endl;
        }
    }
    void displaymy()
    {
        std::cout<<"-------------------------YK--Bank--------------------------"<<std::endl;
        std::cout<<"Name : "<<acc[currentindex].name<<std::endl
        <<"Account number : "<<acc[currentindex].ac_no<<std::endl
        <<"balance : "<<acc[currentindex].balance<<std::endl
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
            else if(acc[currentindex].balance<amount)
            {
                std::cout<<"Insufficient balance ! "<<std::endl;
            }
        }while(amount<=0||acc[currentindex].balance<amount);
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
        int pos=searchac(n);
        do{
            std::cout<<"Enter the amount :"<<std::endl;
            std::cin>>amount;
            if(amount<=0)
            {
                std::cout<<"Invalid input !"<<std::endl;
            }
            else if(acc[pos].balance<amount)
            {
                std::cout<<"Insufficient balance !"<<std::endl;
            }
        }while(amount<=0||acc[pos].balance<amount);
        return amount;
    }
    int searchac(int ac)
    {
       for(int i =0;i<acc.size();i++)
       {
            if(acc[i].ac_no==ac)
            {
                return i;
            }
            else if(i==acc.size()-1)
            {
                std::cout<<"Account not found !"<<std::endl;
            }
       } 
    }
    void historyinput(int amount)
    {
        transaction t;
        std::string filename=std::to_string(acc[currentindex].ac_no);
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
        std::string filename=std::to_string(acc[currentindex].ac_no);
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
