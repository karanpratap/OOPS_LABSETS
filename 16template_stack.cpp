/*
Write a C++ program to create a template class STACK, with push and pop and display member
functions. Write a menu based program to illustrate the working for stack of doubles and stack of integers.
Use exception handling to handle the special conditions underflow and overflow of the stack.
*/

#include "iostream"
#define SIZE 5

using namespace std;

template<class T>
class STACK{
    T * list;
    int size;
    int top;
    public:
    STACK(){
        size=SIZE;
        top=-1;
        list=new T[size];
    }
    STACK(int s){
        size=s;
        top=-1;
        list=new T[size];
    }
    void push(T data){
        list[++top]=data;
    }
    T pop(void){
        return (list[top--]);
    }
    void display(void){
        cout<<"STACK contents:"<<endl;
        for(int i=0;i<top;i++){
            cout<<list[i]<<"->";
        }
        cout<<list[top]<<endl;
    }
    int is_empty(void){
        if(top==-1)
            return 1;
        return 0;
    }
    int is_full(void){
        if(top==size-1){
            return 1;
        }
        return 0;
    }
};

int main(){
    int ch=0,size;
    double dbdata;
    int intdata;
    cout<<"1. STACK of doubles"<<endl;
    cout<<"Enter size for double stack:";
    cin>>size;
    STACK<double> dblist(size);
    while(ch!=4){
        cout<<"1.PUSH 2.POP 3.DISPLAY 4.MOVE TO INT STACK"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:try{
                    if(dblist.is_full()){
                        throw 1;
                    }
                    cout<<"Enter data to push:";
                    cin>>dbdata;
                    dblist.push(dbdata); 
                   }
                   catch(int a){
                       cout<<"Stack overflow!"<<endl;
                   }
                   break;
            case 2:try{
                    if(dblist.is_empty())
                        throw 1;
                    cout<<dblist.pop()<<" popped."<<endl;
                   }
                   catch(int i){
                       cout<<"Stack Underflow!"<<endl;
                   }
                   break;
            case 3:try{
                    if(dblist.is_empty())
                        throw 1;
                    dblist.display();
                   }
                   catch(int i){
                       cout<<"Stack empty!"<<endl;
                   }
                   break;
            case 4:break;
            default:cout<<"Wrong choice!"<<endl;
                    break;
        }
    }

    cout<<"\n\nSTACK of Integers:"<<endl;
    cout<<"Enter the size of integer stack:";
    cin>>size;

    STACK<int> intlist(size);

    while(1){
        cout<<"1.PUSH 2.POP 3.DISPLAY 4.EXIT"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:try{
                    if(intlist.is_full()){
                        throw 1;
                    }
                    cout<<"Enter data to push:";
                    cin>>intdata;
                    intlist.push(intdata); 
                   }
                   catch(int a){
                       cout<<"Stack overflow!"<<endl;
                   }
                   break;
            case 2:try{
                    if(intlist.is_empty())
                        throw 1;
                    cout<<intlist.pop()<<" popped."<<endl;
                   }
                   catch(int i){
                       cout<<"Stack Underflow!"<<endl;
                   }
                   break;
            case 3:try{
                    if(intlist.is_empty())
                        throw 1;
                    intlist.display();
                   }
                   catch(int i){
                       cout<<"Stack empty!"<<endl;
                   }
                   break;
            case 4:exit(0);
            default:cout<<"Wrong choice!"<<endl;
                    break;
        }
    }
    
    return 0;
}