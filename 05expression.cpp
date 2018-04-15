/*
Write a C++ program to create a class called EXPRESSION which can store an arithmetic expression
in both infix and postfix representations. Implement the following methods in the class.
i. Read and store an infix expression (input expression assumed to be valid)
ii. convert to postfix representation
iii. display the expressions in both infix and postfix representations
The expression is supposed to contain the operators + - *,/ only, along with the open and close parentheses.
*/

#include "iostream"
#define MAX 30

using namespace std;

class stack{
    char st[MAX];
    int top;
    public:
    stack(void){
        top=-1;
    }
    void push(char data){
        if(top<MAX){
            st[++top]=data;
        }
        else
            cout<<"Overflow"<<endl;
        return;
    }
    char pop(void){
        if(top==-1){
            cout<<"Underflow"<<endl;
            return 0;
        }
        return st[top--]; 
    }
    void display(void){
        for(int i=0;i<top;i++){
            cout<<st[i];
        }
        cout<<st[top]<<endl;  
    }
    int peek(void){
        return st[top];
    }
    int is_alive(void){
        return(top!=-1);
    }
};
stack s;

int preced(char cToken){
    if(cToken=='(')
        return 0;
    else if(cToken=='+' || cToken=='-')
        return 1;
    else if(cToken=='*' || cToken=='/')
        return 2;
    else
        return 3;
}

class EXPRESSION{
    string infix,postfix;
    public:
    void get_infix(void);
    void convert_to_postfix(void);
    string display_postfix(void);
};

void EXPRESSION::get_infix(void){
    cout<<"Enter a valid infix expression: ";
    cin>>infix;
    cout<<"got the exp!"<<endl;
}

void EXPRESSION::convert_to_postfix(void){
    cout<<"Entered conversion";
    char cToken,ch;
    int i=0,j=0;
    cout<<"Now converting...";
    while((cToken=infix[i])!='\0'){
        if(isalnum(cToken))
            postfix[j++]=cToken;
        else if(cToken=='(')
            s.push(cToken);
        else if(cToken==')'){
            while((ch=s.pop()!='('))
                postfix[j++]=ch;
        }
        else{
            while(s.is_alive() && preced(s.peek()>=preced(cToken))){
                ch=s.pop();
                postfix[j++]=ch;
            }
            s.push(cToken);
        }
    }
    while(s.is_alive()){
        postfix[j++]=s.pop();
    }
}

string EXPRESSION::display_postfix(void){
    return postfix;
}

int main(){
    EXPRESSION e;
    string a;
    e.get_infix();
    cout<<"BACK IN MAIN"<<endl;
    e.convert_to_postfix();
    a=e.display_postfix();
    cout<<"Postfix expression is : "<<a<<endl;
    return 0;
}