/*
 Write a C++ program to create class called bank account. Include the following data member and mem-
ber functions.
Data Members
i.Name of depositor
 ii.Account holder
 iii.Type of account
 iv.Balance amount in the account
Member functions
i.Parametrized Constructor
 ii.To deposit an amount
 iii.To withdraw amount
iv.To display bank account details with balance.

*/
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class BankAcc{
    string name_of_depositor;
    string account_holder;
    string type_of_acc;
    float balance;
    public:
    BankAcc(string name,string holder,string type,float bal){
        name_of_depositor=name;
        account_holder=holder;
        type_of_acc=type;
        balance=bal;
    }
    void Deposit(void){
        float bal;
        cout<<endl<<"Enter amount to be deposited:";
        cin>>bal;
        balance+=bal;
        cout<<"Rs."<<bal<<" successfully deposited to the account of "<<account_holder<<endl;
        cout<<"Current balance:Rs."<<balance<<endl;
    }
    void Withdraw(void){
        float amt;
        cout<<"Enter amount to be withdrawn:";
        cin>>amt;
        if(amt>balance){
            cout<<"Transaction failed! Insufficient funds in Account!"<<endl;
            return;
        }
        balance-=amt;
        cout<<"Rs."<<amt<<" successfully withdrawn from bank account of "<<account_holder<<endl;
        cout<<"Remaining balance: Rs."<<balance<<endl;
    }
    void display(void){
        cout<<endl<<"BANK DETAILS FOR ACCOUNT HOLDER "<<account_holder<<endl<<endl;
        cout<<"Name of the depositor:"<<name_of_depositor<<endl;
        cout<<"Account Holder name:"<<account_holder<<endl;
        cout<<"Account Type:"<<type_of_acc<<endl;
        cout<<"Available Balance: Rs."<<balance<<endl<<endl;
    }
};

int main(void){
    int ch;
    string name,holder,type;
    float bal=0.0;
    cout<<"Enter the details for the new Bank Account:"<<endl;
    cout<<"Enter Name of the depositor:";
    cin>>name;
    cout<<"Enter Account Holder name:";
    cin>>holder;
    cout<<"Enter type of account:";
    cin>>type;
    BankAcc ba(name,holder,type,bal);
    while(1){
        cout<<endl<<"1. DEPOSIT MONEY\n2. WITHDRAW MONEY\n3. VIEW BANK ACC DETAILS\n4. EXIT"<<endl<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:ba.Deposit();
                    break;
            case 2:ba.Withdraw();
                    break;
            case 3:ba.display();
                    break;
            case 4:exit(0);
            default:cout<<"Wrong choice!"<<endl<<endl;
        }
    }
    return 0;
}