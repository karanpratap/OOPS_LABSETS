/* Write a class to represent entities of type Fraction with appropriate data members. Include a method
simplify that simpfies a given fraction ( for eg: 6/8 to 3/4).
Overload the following operators
>> to read a fraction object
<< to display a fraction object
== to check if two fractions are the same
+ to add two fractions
Illustrate these operations in main function.
*/

#include "iostream"

using namespace std;

int gcd(int a,int b);

class Fraction{
    friend int gcd(int,int);
    friend ostream& operator<<(ostream&,const Fraction&);
    friend istream& operator>>(istream&,Fraction&);

    int iNum,iDen;
    
    public:
    Fraction simplify(void);
    int operator==(const Fraction&) const;
    Fraction operator+(const Fraction&) const;
};

istream& operator>>(istream& in,Fraction& f){
        in>>f.iNum>>f.iDen;
        return in;
}

ostream& operator<<(ostream& out,const Fraction& f){
        out<<"("<<f.iNum<<"/"<<f.iDen<<")"<<endl;
        return out;
}

Fraction Fraction::simplify(void){
    int iFact=gcd(iNum,iDen);
    iNum/=iFact;
    iDen/=iFact;
    return *this;
}

Fraction Fraction::operator+(const Fraction& f2) const{
    Fraction temp;
    temp.iNum=iNum*f2.iDen+f2.iNum*iDen;
    temp.iDen=iDen*f2.iDen;
    return temp;
}

int Fraction::operator==(const Fraction& f2) const{
    if(iNum*f2.iDen==iDen*f2.iNum){
        return 1;
    }
    return 0;
}

int gcd(int a,int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int main(){
    Fraction f1,f2;
    cout<<"Enter fraction 1:";
    cin>>f1;
    cout<<"Enter fraction 2:";
    cin>>f2;
    cout<<"Fractions entered are:"<<f1<<" and "<<f2<<endl;
    f2.simplify();
    f1.simplify();
    cout<<"Simplified Fractions are:"<<f1<<" and "<<f2<<endl;
    cout<<"Comparing f1 and f2";
    if(f1==f2)
        cout<<"f1 is equal to f2"<<endl;
    else
        cout<<"f1 is not equal to f2"<<endl;
    Fraction f3;
    cout<<"Creating new fraction as sum of f1 and f2"<<endl;
    f3=f1+f2;
    cout<<"f3:"<<f3<<endl;
    f3.simplify();
    cout<<"f3 simplified:"<<f3<<endl;
    return 0;
}