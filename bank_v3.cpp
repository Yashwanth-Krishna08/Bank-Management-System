#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
class Account 
{
    friend class Bank;
    private:
    int ac_no;
    std::string name,pass;
    float balance;
};
class Bank
{
    private:
    int currentindex;
    std::vector<Account> acc;
    public:
    void create()
    {
        Account a;
        std::ofstream fout("ac.txt",std::ios::app);
        std::cout<<"Enter your account number : "<<std::endl;
        std::cin>>a.ac_no;
        for(int i =0 ;i<acc.size();i++)
        {
            if(acc[i].ac_no==a.ac_no)
            {
                std::cout<<"Account already exists !"<<std::endl;
                create();
            }
        }
        std::cin.ignore();
        std::cout<<"Enter your name : "<<std::endl;
        getline(std::cin,a.name);
        std::cout<<"Enter amount to be deposited to new account:"<<std::endl;
        std::cin>>a.balance;
        std::cout<<"Enter your security pin (you can change later):"<<std::endl;
        std::cin>>a.pass;
        acc.push_back(a);
        fout<<a.name<<"  "<<a.ac_no<<"  "<<a.balance<<"  "<<a.pass<<std::endl;
        fout.close();
    }
    void display()
    {
        int n;
        std::cout<<"Enter account number : "<<std::endl;
        std::cin>>n;
        std::cout<<"-------------------------YK--Bank--------------------------"<<std::endl;
        for(int i =0;i<acc.size();i++)
        {
            if(acc[i].ac_no==n)
            {
                std::cout<<"Name : "<<acc[i].name<<std::endl<<"Account number : "<<acc[i].ac_no<<std::endl<<"balance : "<<acc[i].balance<<std::endl<<"------------------------------------"<<std::endl;
            }
        }
    }
    void depositead()
    {
        float depo;
        int n;
        std::cout<<"Enter account number : "<<std::endl;
        std::cin>>n;
        std::cout<<"Enter the amount to be deposited : "<<std::endl;
        std::cin>>depo;
        for(int i =0;i<acc.size();i++)
        {
            if(acc[i].ac_no==n)
            {
                if(depo>0)
                {
                     acc[i].balance=acc[i].balance+depo;
                    std::cout<<depo<<" has been credited successfully"<<std::endl;
                }
                else
                {
                    std::cout<<"Invalid input ?"<<std::endl;
                    depositead();
                }
                
            }
        }
        
    }
    void withdrawad()
    {
        float with;
         int n;
        std::cout<<"Enter account number : "<<std::endl;
        std::cin>>n;
        std::cout<<"Enter the amount : "<<std::endl;
        std::cin>>with;
        for(int i=0;i<acc.size();i++)
        {
            if(acc[i].ac_no==n)
            {
                if(with>0)
                {
                    if(acc[i].balance>=with)
                    {
                        acc[i].balance=acc[i].balance-with;
                        std::cout<<with<<"has been debited successfully"<<std::endl;
                    }
                    else
                    {
                        std::cout<<"Insufficient balance"<<std::endl;
                        withdrawad();
                    }
                }
                else
                {
                    std::cout<<"Invalid input"<<std::endl;
                    withdrawad();
                }
            }
        }

    }
    void menuad()
    {
        
        int choice;
        do{
            std::cout<<"1.Create account "<<std::endl;
            std::cout<<"2.Deposit"<<std::endl;
            std::cout<<"3.Withdraw"<<std::endl;
            std::cout<<"4.Display a account with account number"<<std::endl;
            std::cout<<"5.Show All accounts"<<std::endl;
            std::cout<<"6.Transfer to other account"<<std::endl;
            std::cout<<"7.Exit"<<std::endl;
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
            }
        }while(choice!=7);
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
    void updatedetails()       //Future updation
    {
        int n;
        std::cout<<"Enter the account number : "<<std::endl;
        std::cin>>n;
        for(int i =0;i<acc.size();i++)
        {
            if(acc[i].ac_no==n)
            {
                int p;
                
                std::cout<<"1.To update name"<<std::endl<<"2.To update pin"<<std::endl;
                std::cin>>p;
                switch (p)
                {
                case 1:
                    /* code */
                    break;
                case 2:
                    break;
                default:
                    break;
                }
            }
        }
    }
    void transferad()

    {
        int transfr,transto;
        float amount;
        std::cout<<"Enter the account number of transfer from : "<<std::endl;
        std::cin>>transfr;
        std::cout<<"Enter account number of transfer to : "<<std::endl;
        std::cin>>transto;
        std::cout<<"Amount to be transfered : "<<std::endl;
        std::cin>>amount;
        if(transfr!=transto)
        {
            if(amount>0)
            {
                 for(int i = 0;i<acc.size();i++)
                {
                    if(acc[i].ac_no==transfr)
                    {
                        acc[i].balance=acc[i].balance-amount;
                    }
                    else if(acc[i].ac_no==transto)
                    {
                        acc[i].balance=acc[i].balance+amount;
                        std::cout<<"Transaction Done !"<<std::endl;
                    }
                
                }

            } 
            else
            {
                std::cout<<"Invalid amount !"<<std::endl;
                transferad();
            }
        }
        else
        {
            std::cout<<"invalid input !"<<std::endl;
            transferad();
        }
    }
    void loadtofile()
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
        loadtofile();
        int n;
        std::cout<<"1.User Sign Up"<<std::endl;
        std::cout<<"2.User Sign In"<<std::endl;
        std::cout<<"3.Admin Sign Up"<<std::endl;
        std::cin>>n;
        switch (n)
        {
        case 1:
            create();
            break;
        case 2:
            login();
            break;
        case 3:
            loginad();
            break;
        default:
            std::cout<<"Invalid input"<<std::endl;
            start();
            break;
        } 
    }
    void loginad()
    {
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
        int ac;
        std::string password;
        std::cout<<"Enter your account number : "<<std::endl;
        std::cin>>ac;
        std::cout<<"Enter your security pin : "<<std::endl;
        std::cin>>password;
        for(int i = 0;i<acc.size();i++)
        {
            if(acc[i].ac_no==ac)
            {
                if(acc[i].pass==password)
                {
                    currentindex=i;
                    menuser();
                }
                else
                {
                    std::cout<<"Wrong Password !"<<std::endl;
                    login();
                }
            }

        }
    }
    void menuser()
    {
        int choice;
        do{
            std::cout<<"1.Deposit"<<std::endl;
            std::cout<<"2.Withdraw"<<std::endl;
            std::cout<<"3.Transfer to other account"<<std::endl;
            std::cout<<"4.Display account details"<<std::endl;
            std::cout<<"5.Exit"<<std::endl;
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
            }
        }while(choice!=5);
        rewritefile();
        std::cout<<"----------Thank--You---------------"<<std::endl;
    }
    void deposituser()
    {
        float amount;
        if(currentindex==-1)
        {
            std::cout<<"Account not found"<<std::endl;
            login();
        }
        else
        {
            std::cout<<"Enter the amount to be deposited : "<<std::endl;
            std::cin>>amount;
            if(amount>0)
            {
                acc[currentindex].balance+=amount;
                std::cout<<amount<<"  has been credited successfully"<<std::endl;
                std::cout<<"Your account balance is : "<<acc[currentindex].balance;
            }
            else
            {
                std::cout<<"Invalid input !"<<std::endl;
                deposituser();
            }

        }
        
    }
    void withdrawuser()
    {
        float amount;
        if(currentindex==-1)
        {
            std::cout<<"Account not fount "<<std::endl;
            login();
        }
        else
        {
            std::cout<<"Enter the amount for withdrawal : "<<std::endl;
            std::cin>>amount;
            if(amount>0)
            {
                if(acc[currentindex].balance>=amount)
                {
                    acc[currentindex].balance-=amount;
                    std::cout<<amount<<" has been debited successfully"<<std::endl;
                    std::cout<<"Your account balance is : "<<acc[currentindex].balance;
                }
                else
                {
                    std::cout<<"Insufficient balance"<<std::endl;
                    withdrawuser();
                }
            }
            else
            {
                std::cout<<"Invalid input !"<<std::endl;
                withdrawuser();
            }
        }
    }
    void transferuser()
    {
        float amount;
        int tranto;
        std::cout<<"Enter the account number of amount to be transfered : "<<std::endl;
        std::cin>>tranto;
        std::cout<<"Enter the amount : "<<std::endl;
        std::cin>>amount;
        if(amount>0)
        {
            if(acc[currentindex].balance>=amount)
            {
                for(int i =0;i<acc.size();i++)
                {
                    if(acc[i].ac_no==tranto)
                    {
                        acc[currentindex].balance-=amount;
                        acc[i].balance+=amount;
                        std::cout<<amount<<" has been transfered successfully"<<std::endl;
                        std::cout<<"Your account balance is : "<<acc[currentindex].balance;
                    }
                }
            }
            else
            {
                std::cout<<"Insufficient balance"<<std::endl;
                transferuser();
            }
        }
        else
        {
            std::cout<<"Invalid input !"<<std::endl;
            transferuser();
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

};
int main()
{
    Bank b;
    b.start();
    return 0;
}
