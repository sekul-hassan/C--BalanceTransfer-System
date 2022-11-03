#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
#include <unistd.h>
#include <conio.h>
#include <Windows.h>
//////
///////*
//////                         /|    __|
//////                        /     |       |  |   |  |
//////                        \     |__|    |/ |   |  |
//////                      \-/     |__|    |\ |___|  |___
//////                                 |
//////*/

using namespace std;

/// Global function define here
void intro();
void creat_account(char type);/// Rocket or Bikash name
void updata_account(char type,int pin,int phone);/// Account update here
void show_account(char type,int pin,int phone);/// Account details showing here
void delete_account(char type,int pin,int phone);/// Delete a specific account here
void show_balance(char type,int pin,int phone);///
void deposite_balance(char type,int pin,int phone);////
void payment_balance(char type,int pin,int phone);////
void transper_balance(char type,int pin,int phone,int tphone);

bool account_is_found(char c,int phone);

/// User Class here

class User
{
protected:
    char name[80];
    char email[40];
    int age;
    char gender;
    char nationality[80];
    public:
        User()
        {       }
        void showData();
        friend char* retName();
        virtual void getData();
};
void User::getData()
{
    cout<<"Enter the name of user : ";
    cin.getline(name,40);
    cout<<"Enter User e-mail : ";
    cin.getline(email,40);
    cout<<"Enter the age : ";
    cin>>age;
    cout<<"Enter your gender (F/M) : ";
    cin>>gender;
    gender = toupper(gender);
    cout<<"Enter Your nationality : ";
    cin>>nationality;
}
void User::showData()
{
    cout<<"Your name is : "<<name<<endl;
    cout<<"Your e-mail is : "<<email<<endl;
    cout<<"Your age is : "<<age<<endl;
    cout<<"Your gender is : "<<gender<<endl;
    cout<<"Your Nationality is : "<<nationality<<endl;
}

/// Account Class here

class Account:public User
{
private:
    int pin;
    int phone;
    double balance=0;
public:
    char ac_type;
    void getAccount();
    void showAccount();
    void deposite(double x);
    double withdraw(double x);
    double ret_balance() const ;
    int ret_pin() const ;
    int ret_phone() const ;
};

/// Return Phone Number
int Account::ret_phone() const
{
    return phone;
}
/// Return Pin here
int Account::ret_pin() const
{
    return pin;
}
double Account::ret_balance() const
{
    return balance;
}
/// Deposit Here
void Account::deposite(double x)
{
    balance = balance + x;
}
/// Balance Withdraw here
double Account::withdraw(double x)
{
    balance = balance - x ;
    return balance;
}

/// Write account here

void Account::getAccount(){
    User::getData();
    cout<<"Enter your Account type (S/C) : ";
    cin>>ac_type;
    ac_type = toupper(ac_type);
    cout<<"Enter Your Password : ";
    cin>>pin;
    cout<<"Enter your Phone number : ";
    cin>>phone;
    cout<<"Add new Balance : ";
    cin>>balance;

}
/// Account Show here
void Account::showAccount()
{
    User::showData();
    cout<<"Account type is : "<<ac_type<<endl;
    cout<<"Account Password is : "<<pin<<endl;
    cout<<"Account Phone number is : "<<phone<<endl;
    cout<<"Account Balance is : "<<balance<<endl;
}
/*.S.........................E.......................... Main Function.........K.................U.................L...*/
int main()
{
    SetConsoleTitleA("Bikash & Rocket Payment and Balance Transfer system.");
    Account ac;
    int chioce,phone,pin,tphone;
    char ch;
    intro();
    system("cls");
    do
    {
        cout<<"1. For Create New Account (Bikash)"<<endl;
        cout<<"2. For Create New Account (Rocket)"<<endl;
        cout<<"3. For Payment by Bikash Account "<<endl;
        cout<<"4. For Payment by Rocket Account "<<endl;
        cout<<"5. For Send-Money Bikash to Bikash"<<endl;
        cout<<"6. For Send-Money Rocket to Rocket"<<endl;
        cout<<"7. For Deposit Money"<<endl;
        cout<<"8. See Account Balance"<<endl;
        cout<<"9. Update your Account status"<<endl;
        cout<<"10. Delete your Account"<<endl;
        cout<<"11. Show your Account Details"<<endl;
        cout<<"0. Exit the program "<<endl;
        cin>>chioce;
        cin.ignore('\n',10);
        switch(chioce)
        {
        case 1:
            system("cls");
            cout<<setw(50);
            cout<<"For creating Bikash New account "<<endl;
            creat_account('b');
            break;
        case 2:
            system("cls");
            creat_account('r');
            break;
        case 3:
            system("cls");
            cout<<"\nEnter the Phone(B) Number (MUST USE INTEGER) : ";
            cin>>phone;
            cout<<"Enter the PIN(B) (MUST USE INTGER) : ";
            cin>>pin;
            cin.ignore('\n',10);
            payment_balance('b',pin,phone);
            break;
        case 4:
            cout<<"\nEnter the Phone(R) Number (MUST USE INTEGER) : ";
            cin>>phone;
            cout<<"Enter the PIN(R) (MUST USE INTGER) : ";
            cin>>pin;
            cin.ignore('\n',10);
            payment_balance('r',pin,phone);
            break;
        case 5:
            system("cls");
            cout<<"Enter the Phone Number(T) where you sent : ";
            cin>>tphone;
            if(account_is_found('b',tphone)==true){
                cout<<"Enter your Phone(B) (MUST USE INTEGER) : ";
                cin>>phone;
                cout<<"Enter your PIN(B) (MUST USE INTEGER) : ";
                cin>>pin;
                cin.ignore('\n',10);
                if(account_is_found('b',phone)==true){
                    transper_balance('b',pin,phone,tphone);
                    break;
                }
                else{
                    cout<<phone<<" "<<"This number has not created Bikash Account "<<endl;
                    break;
                }
            }
            else{
                cout<<"This Phone Number has not created Bikash Account |"<<endl<<endl;
                break;
            }
        case 6:
            system("cls");
            cout<<"Enter the Phone(T) Number where you sent : ";
            cin>>tphone;
            if(account_is_found('r',tphone)==true){
                cout<<"Enter your Phone(R) (MUST USE INTEGER) : ";
                cin>>phone;
                cout<<"Enter your PIN(R) (MUST USE INTEGER) : ";
                cin>>pin;
                cin.ignore('\n',10);
                if(account_is_found('r',phone)==true){
                    transper_balance('r',pin,phone,tphone);
                    break;
                }
                else{
                    cout<<phone<<" "<<"This number has not created Rocket Account "<<endl;
                    break;
                }
            }
            else{
                cout<<"This Phone Number has not created Rocket Account |"<<endl<<endl;
                break;
            }
        case 7:
            system("cls");
            cout<<"Enter your phone(B/R) : ";
            cin>>phone;
            cout<<"Enter PIN(B/R) : " ;
            cin>>pin;
            cout<<"Bikash Deposit Press (b) / Rocket Press (r) : ";
            cin>>ch;
            deposite_balance(ch,pin,phone);
            break;
        case 8:
            system("cls");
            cout<<"Enter your phone(B/R) : ";
            cin>>phone;
            cout<<"Enter PIN(B/R) : " ;
            cin>>pin;
            cout<<"Bikash Press (b) / Rocket Press (r) : ";
            cin>>ch;
            cin.ignore('\n',10);
            show_balance(ch,pin,phone);
            break;
        case 9:
            system("cls");
            cout<<"Enter your phone(B/R) : ";
            cin>>phone;
            cout<<"Enter PIN(B/R) : " ;
            cin>>pin;
            cout<<"Bikash Press (b) / Rocket Press (r) : ";
            cin>>ch;
            cin.ignore('\n',10);
            updata_account(ch,pin,phone);
            break;
        case 10:
            system("cls");
            cout<<"Enter your phone(B/R) : ";
            cin>>phone;
            cout<<"Enter PIN(B/R) : " ;
            cin>>pin;
            cout<<"Bikash Press (b) / Rocket Press (r) : ";
            cin>>ch;
            cin.ignore('\n',10);
            delete_account(ch,pin,phone);
            break;
        case 11:
            system("cls");
            cout<<"For showing your Account "<<endl;
            cout<<"Enter your phone(B/R) : ";
            cin>>phone;
            cout<<"Enter PIN(B/R) : " ;
            cin>>pin;
            cout<<"Bikash Press (b) / Rocket Press (r) : ";
            cin>>ch;
            cin.ignore('\n',10);
            show_account(ch,pin,phone);
            break;
        case 0:
            break;
        default:
            system("cls");
        }
    }while(chioce!=0);

    return 0;
}

/// End of main function


/// Global function create account
void creat_account(char type){
    Account ac;
    ofstream outFile;
    type = toupper(type);
    if(type == 'B'){
        outFile.open("bikash.dat",ios::binary | ios::app);
        ac.getAccount();
        outFile.write(reinterpret_cast<char*>(&ac),sizeof(Account));
        outFile.close();
    }
    else if(type=='R'){
        outFile.open("rocket.dat",ios::binary | ios::app);
        ac.getAccount();
        outFile.write(reinterpret_cast<char*>(&ac),sizeof(Account));
        outFile.close();
    }
    else{
        cout<<"Enter currect key : ";
        cin>>type;
        creat_account(type);
    }
    cout<<"Account is creating..";
    for(int i=0;i<2;i++){
        cout<<"..";
        sleep(1);
    }
    cout<<"\n\nAccount creating successfully done."<<endl<<endl;
}
/// Global function show a specific account
void show_account(char type,int pin,int phone)
{
    bool flag = false;
    Account ac;
    ifstream inFile;
    type = toupper(type);
    if(type == 'B'){
        inFile.open("bikash.dat",ios::binary);
        if(!inFile){
            cout<<"File could not to be open"<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                cout<<"YOUR ACCOUNT DETAILS IS READY..";
                for(int i=0;i<5;i++){
                    cout<<"..";
                    sleep(1);
                }
                cout<<endl;
                ac.showAccount();
                cout<<endl;
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else if(type=='R'){
        inFile.open("rocket.dat",ios::binary);
        if(!inFile){
            cout<<"File could not to be open"<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                cout<<"YOUR ACCOUNT DETAILS IS READY..";
                for(int i=0;i<5;i++){
                    cout<<"..";
                    sleep(1);
                }
                cout<<endl;
                ac.showAccount();
                cout<<endl;
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else{
        cout<<"Enter currect key : "<<endl;
        getch();
        return ;
    }
    if(flag==false){
        cout<<"Your record not found "<<endl;
        cout<<"Try again "<<endl;
        return ;
    }

}
/// Global function update here
void updata_account(char type, int pin,int phone)
{
    bool flag = false;
    Account ac;
    fstream inFile;
    type = toupper(type);
    if(type == 'B'){
        inFile.open("bikash.dat",ios::binary | ios::in | ios::out | ios::app);
        if(!inFile){
            cout<<"File could not to be open"<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                cout<<"YOUR OLD DETAILS "<<endl;
                cout<<endl;
                ac.showAccount();
                cout<<endl;
                cout<<"Enter now details of Account : "<<endl<<endl;
                ac.getAccount();
                int pos = (-1)*static_cast<int>(sizeof(Account));
                inFile.seekp(pos,ios::cur);
                inFile.write(reinterpret_cast<char*>(&ac),sizeof(Account));
                cout<<"YOUR ACCOUNT DETAILS IS UPDATING..";
                for(int i=0;i<5;i++){
                    cout<<"..";
                    sleep(1);
                }
                cout<<endl;
                cout<<"Record has been updated.."<<endl;
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else if(type=='R'){
        inFile.open("rocket.dat",ios::binary | ios::in | ios::out | ios::app);
        if(!inFile){
            cout<<"File could not to be open"<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                ac.showAccount();
                cout<<"\nEnter now details of Account : "<<endl;
                ac.getAccount();
                int pos = (-1)*static_cast<int>(sizeof(Account));
                inFile.seekp(pos,ios::cur);
                inFile.write(reinterpret_cast<char*>(&ac),sizeof(Account));
                cout<<"YOUR ACCOUNT DETAILS IS UPDATING..";
                for(int i=0;i<5;i++){
                    cout<<"..";
                    sleep(1);
                }
                cout<<endl;
                cout<<"Record has been updated.."<<endl;
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else{
        cout<<"Enter currect key : ";
        return ;
    }
    if(flag==false){
        cout<<"Your record not found "<<endl;
        cout<<"Try again "<<endl;
        return ;
    }
}
/// Global function account delete here
void delete_account(char type,int pin,int phone)
{
    bool flag = false;
    Account ac;
    ifstream inFile;
    ofstream outFile;
    outFile.open("Temp.dat",ios::binary | ios::app);
    type = toupper(type);
    if(type == 'B'){
        inFile.open("bikash.dat",ios::binary);
        if(!inFile){
            cout<<"File could not to be open"<<endl;
            return ;
        }
        inFile.seekg(0,ios::beg);
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()!=pin && ac.ret_phone()!=phone){
                outFile.write(reinterpret_cast<char*>(&ac),sizeof(Account));
            }

        }
        inFile.close();
        outFile.close();
        cout<<"YOUR ACCOUNT DETAILS IS DELETING..";
                for(int i=0;i<5;i++){
                    cout<<"..";
                    sleep(1);
                }
                cout<<endl;
        remove("bikash.dat");
        rename("Temp.dat","bikash.dat");
        cout<<"Record Deleted..."<<endl;
    }
    else if(type=='R'){
        inFile.open("rocket.dat",ios::binary);
        if(!inFile){
            cout<<"File could not to be open"<<endl;
            return ;
        }
        inFile.seekg(0,ios::beg);
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()!=pin && ac.ret_phone()!=phone){
                outFile.write(reinterpret_cast<char*>(&ac),sizeof(Account));
            }

        }
        inFile.close();
        outFile.close();
        cout<<"YOUR ACCOUNT DETAILS IS DELETING..";
                for(int i=0;i<5;i++){
                    cout<<"..";
                    sleep(1);
                }
                cout<<endl;
        remove("bikash.dat");
        rename("Temp.dat","bikash.dat");
        cout<<"Record Deleted..."<<endl;
    }
    else{
        cout<<"Enter currect key (b or r) : ";
        return ;
    }
}
/// Global function show account balance
void show_balance(char type,int pin,int phone)
{
    bool flag = false;
    Account ac;
    ifstream inFile;
    type = toupper(type);
    if(type == 'B'){
        inFile.open("bikash.dat",ios::binary);
        if(!inFile){
            cout<<"File could not to be open"<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                cout<<endl;
                cout<<"YOUR CURRENT BALANCE IS : ";
                cout<<ac.ret_balance()<<"$"<<endl;
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else if(type=='R'){
        inFile.open("rocket.dat",ios::binary);
        if(!inFile){
            cout<<"File could not to be open"<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                cout<<endl;
                cout<<"YOUR CURRENT BALANCE IS : ";
                cout<<ac.ret_balance()<<"$"<<endl;
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else{
        cout<<"Enter currect key : ";
        return ;
    }
    if(flag==false){
        cout<<"Your record not found "<<endl;
        cout<<"Try again "<<endl;
        return ;
    }

}
/// Global function deposit balance
void deposite_balance(char type,int pin,int phone)
{
    bool flag = false;
    Account ac;
    ifstream inFile;
    double amt;
    type = toupper(type);
    if(type == 'B'){
        inFile.open("bikash.dat",ios::binary | ios::in | ios::out);
        if(!inFile){
            cout<<"File could not to be open | Press any key....."<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                system("cls");
                cout<<"________________Deposit Money_____________"<<endl;
                cout<<"********* Enter the amount of Money ******"<<endl;
                cin>>amt;
                ac.deposite(amt);
                cout<<"_____________Deposit success______________"<<endl;
                cout<<"YOUR CURRENT BALANCE IS : "<<ac.ret_balance()<<"$"<<endl;
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else if(type=='R'){
        inFile.open("rocket.dat",ios::binary | ios::in | ios::out);
        if(!inFile){
            cout<<"File could not to be open | Press any key....."<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                cout<<"________________Deposit Money_____________"<<endl;
                cout<<"********* Enter the amount of Money ******"<<endl;
                cin>>amt;
                ac.deposite(amt);
                cout<<"_____________Deposit success______________"<<endl;
                cout<<"YOUR CURRENT BALANCE IS : "<<ac.ret_balance()<<"$"<<endl;
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else{
        cout<<"Enter currect key : ";
        return ;
    }
    if(flag==false){
        cout<<"Your record not found "<<endl;
        cout<<"Try again "<<endl;
        return ;
    }
}
/// Global function withdraw balance
void payment_balance(char type,int pin,int phone)
{
    bool flag = false;
    Account ac;
    fstream inFile;
    double amt;
    type = toupper(type);
    if(type == 'B'){
        inFile.open("bikash.dat",ios::binary | ios::in | ios::out | ios::app);
        if(!inFile){
            cout<<"File could not to be open | Press any key....."<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                cout<<"__________Your current balance is : "<<ac.ret_balance()<<"$"<<endl;
                cout<<"_____________________Withdraw money_________________"<<endl;
                cout<<"*************Enter the amount of money for Withdraw**********"<<endl;

                cin>>amt;
                double pbal = ac.ret_balance();
                if(pbal>=amt){
                ac.withdraw(amt);
                cout<<"______________Withdraw successfull_____________"<<endl;
                cout<<"\nAftet Payment Your current balance is : "<<ac.ret_balance()<<"$"<<endl;
                }
                else{
                    cout<<"____________________INSUFFUCIENT BALANCE_________________ "<<endl;
                }
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else if(type=='R'){
        inFile.open("rocket.dat",ios::binary | ios::in | ios::out | ios::app);
        if(!inFile){
            cout<<"File could not to be open | Press any key....."<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                cout<<"________________Your current balance is : "<<ac.ret_balance()<<"$"<<endl;
                cout<<"_____________________Withdraw money_________________"<<endl;
                cout<<"**************Enter the money for Withdraw**********"<<endl;

                cin>>amt;
                double pbal = ac.ret_balance();
                if(pbal>=amt){
                ac.withdraw(amt);
                cout<<"______________Withdraw successfull_____________"<<endl;
                cout<<"\nAftet Payment Your current balance is : "<<ac.ret_balance()<<"$"<<endl;
                }
                else{
                    cout<<"____________________INSUFFUCIENT BALANCE_________________ "<<endl;
                }
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else{
        cout<<"Enter currect key : ";
        return ;
    }
    if(flag==false){
        cout<<"Your record not found "<<endl;
        cout<<"Try again "<<endl;
        return ;
    }
}

/// Transfer balance here
void transper_balance(char type,int pin,int phone,int tphone)
{
    /// At first deposit here
    bool flag = false;
    bool taka = false;
    Account ac;
    fstream inFile;
    double amt;
    type = toupper(type);
    if(type == 'B'){
        inFile.open("bikash.dat",ios::binary | ios::in | ios::out | ios::app);
        if(!inFile){
            cout<<"File could not to be open | Press any key....."<<endl;
            return ;
        }
       while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                cout<<"__________Your current balance is : "<<ac.ret_balance()<<"$"<<endl;
                cout<<"\n************Enter the money for Send-money**********"<<endl;

                cin>>amt;
                double pbal = ac.ret_balance();
                if(pbal>=amt){
                taka = true;
                /// Withdraw Here
                ac.withdraw(amt);
                while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
                    if(ac.ret_phone()==tphone){
                        ac.deposite(amt);
                    }
                }
                cout<<"\nConnecting to the server..";
                for(int i=0;i<5;i++){
                    cout<<"..";
                    sleep(1);
                }
                cout<<"\n\n______________Your Tranjection is successfull_____________"<<endl;
                cout<<"Aftet Send Your current balance is : "<<ac.ret_balance()<<"$"<<endl;
                }
                else{
                    cout<<"____________________INSUFFUCIENT BALANCE_________________ "<<endl;
                }
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else if(type=='R'){
        inFile.open("rocket.dat",ios::binary | ios::in | ios::out | ios::app);
        if(!inFile){
            cout<<"File could not to be open | Press any key....."<<endl;
            return ;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_pin()==pin && ac.ret_phone()==phone){
                cout<<"__________Your current balance is : "<<ac.ret_balance()<<" ______"<<endl;
                cout<<"\n************Enter the money for Send-money**********"<<endl;

                cin>>amt;
                double pbal = ac.ret_balance();
                if(pbal>=amt){
                taka = true;
                ac.withdraw(amt);
                cout<<"\nConnecting to the server..";
                for(int i=0;i<5;i++){
                    cout<<"..";
                    sleep(1);
                }
                cout<<"\n\n______________Your Tranjection is successfull_____________"<<endl;
                cout<<"_______Aftet Send Your current balance is : "<<ac.ret_balance()<<"$"<<endl;
                }
                else{
                    cout<<"____________________INSUFFUCIENT BALANCE_________________ "<<endl;
                }
                flag = true;
                break;
            }

        }
        inFile.close();
    }
    else{
        cout<<"Enter currect key : ";
        return ;
    }
    if(flag==false){
        cout<<"Your record not found "<<endl;
        cout<<"Try again "<<endl;
        return ;
    }
    if(taka==true){
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_phone()==tphone){
                ac.deposite(amt);
            }
        }
    }
}
/// Check If account has Exist
bool account_is_found(char type,int phone)
{
    Account ac;
    ifstream inFile;
    type = toupper(type);
    if(type == 'B'){
        inFile.open("bikash.dat",ios::binary);
        if(!inFile){
            cout<<"File could not to be open | Press any key....."<<endl;
            return false;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_phone()==phone){
                return true;
                break;
            }

        }
        inFile.close();
    }
    else if(type=='R'){
        inFile.open("rocket.dat",ios::binary);
        if(!inFile){
            cout<<"File could not to be open | Press any key....."<<endl;
            return false;
        }
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
            if(ac.ret_phone()==phone){
                return true;
                break;
            }

        }
        inFile.close();
    }
    return false;

}
/// Intro Function
void intro()
{
    cout<<"\n\n\n___________Project : Bikash & Rocket Payment and Send-Money System__________"<<endl;
    cout<<"________________________________Name: Sakul Mia_____________________________"<<endl;
    cout<<"_______________Department of Computer Science & Engineering_________________"<<endl;
    cout<<"*********************************JU*****************************************"<<endl;
    cout<<"\n                 Presss  Enter key to go to main menu                       "<<endl;
    getch();
}

