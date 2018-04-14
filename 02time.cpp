/*
Write a C++ program that stores the time duration in hh:mm:ss format in a class called Duration having
the members hh, mm and ss.
Include the following constructors
zero parameter constructor that sets all data members to zero
three parameter constructor that sets values of hh, mm and ss respectively if the values are valid
Implement the following methods
getDuration method that reads and validates a time duration
showDuration method that displays the time duration
addDuration method that adds two durations
Illustrate the addition of two time durations
*/

#include "iostream"
#include "cmath"

using namespace std;

class Duration{
    int hh,mm,ss;
    public:
    Duration(void){
        hh=mm=ss=0;
    }
    Duration(int a,int b,int c){
        hh=a+b/60;
        mm=b%60+c/60;
        ss=c%60;
    }
    void getDuration(int,int,int);
    void showDuration(void);
    friend Duration addDuration(Duration d1,Duration d2);
};

void Duration::getDuration(int a,int b,int c){
    hh=a+b/60;
    mm=b%60+c/60;
    ss=c%60;
}

void Duration::showDuration(void){
    if(hh<10)
        cout<<"0";
    cout<<hh<<":";
    if(mm<10)
        cout<<"0";
    cout<<mm<<":";
    if(ss<10)
        cout<<"0";
    cout<<ss<<endl;
}

Duration addDuration(Duration d1,Duration d2){
    Duration temp;
    temp.hh=d1.hh+d2.hh+(d1.mm+d2.mm)/60;
    temp.mm=(d1.mm+d2.mm)%60+(d1.ss+d2.ss)/60;
    temp.ss=(d1.ss+d2.ss)%60;
    return temp;
}

int main(){
    Duration d1,d2,d3;
    int h,m,s;
    cout<<"Enter duration 1(hh mm ss):";
    cin>>h>>m>>s;
    d1.getDuration(h,m,s);
    cout<<"Duration 1 set!"<<endl;
    cout<<"Enter duration 2(hh mm ss):";
    cin>>h>>m>>s;
    d2.getDuration(h,m,s);
    cout<<"Duration 2 set!"<<endl;
    cout<<endl<<"Duration 1: ";
    d1.showDuration();
    cout<<endl<<"Duration 2: ";
    d2.showDuration();
    cout<<"Addind d1 and d2";
    d3=addDuration(d1,d2);
    cout<<endl<<"Duration 3: ";
    d3.showDuration();
    return 0;
}