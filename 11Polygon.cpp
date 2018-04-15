/*
Create a POLYGON class that has the following members
Data members : name, number of sides and area
Methods :
constructors and destructors
display method to display details of the POLYGON object
pure virtual function calcArea
Next Derive the following classes from POLYGON namely TRIANGLE and SQUARE with appropriate
data members and methods. Both these derived classes have to define the calcArea method to suit its
purpose.
*/

#include "iostream"
#include "cmath"

using namespace std;

class POLYGON{
    protected:
    string name;
    int no_of_sides;
    float area;
    public:
    POLYGON(void){
        no_of_sides=0;
        area=0.0;
    }
    void display(void){
        cout<<"Shape:"<<name<<" No of sides:"<<no_of_sides<<" Area:"<<area<<endl;
    }
    //pure virtual function
    virtual void calcArea()=0;
};

class SQUARE:public POLYGON{
    float side;
    public:
    SQUARE(void){
        name="square";
        no_of_sides=4;
        side=0.0;
        area=0.0;
    }
    SQUARE(float a){
        name="square";
        no_of_sides=4;
        side=a;
    }
    void calcArea(void){
        area=side*no_of_sides;
    }
    void get_side(float a){
        side=a;
    }
};

class TRIANGLE:public POLYGON{
    float a,b,c;
    public:
    TRIANGLE(void){
        name="triangle";
        no_of_sides=3;
        a=b=c=0.0;
        area=0.0;
    }
    TRIANGLE(float s1,float s2,float s3){
        name="triangle";
        no_of_sides=3;
        a=s1;
        b=s2;
        c=s3;
    }
    void get_side(float s1,float s2,float s3){
        a=s1;
        b=s2;
        c=s3;
    }
    void calcArea(void){
        float s;
        s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
    }
};

int main(){
    float side;
    float s1,s2,s3;
    SQUARE sq;
    TRIANGLE tri;
    cout<<"Enter side length of square:";
    cin>>side;
    sq.get_side(side);
    cout<<"Enter sides of triangle";
    cin>>s1>>s2>>s3;
    tri.get_side(s1,s2,s3);
    cout<<"Triangle and square data set!"<<endl;
    tri.calcArea();
    sq.calcArea();
    cout<<"Details of square:"<<endl;
    sq.display();
    cout<<"Details of triangle:"<<endl;
    tri.display();
    return 0;
}