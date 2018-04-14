/*Write a C++ program to create a class to represent entities of type Circle, specified by its attributes
radius and coordinates of its center. Include appropriate Constructors and display methods. Also write
a friend function that determines whether two circles intersect one another or they touch each other or
they are disjoint.*/


#include "iostream"
#include "cmath"

using namespace std;

class Point{
    int x,y;
    public:
    void setPoint(int a,int b){
        x=a;
        y=b;
    }
    Point(void){
        x=y=0;
    }
    void showPoint(void){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    int get_x_coord(void){
        return x;
    }
    int get_y_coord(void){
        return y;
    }
    float get_distance_from(Point p2);
};

float Point::get_distance_from(Point p2){
    float distance;
    distance=sqrt(pow((x-p2.x),2)+pow((y-p2.y),2));
    return distance;
}

class Circle{
    Point center;
    int iRadius;
    public:
    Circle(int a,int b,int c){
        center.setPoint(a,b);
        iRadius=c;
    }
    Circle(void){
        center.setPoint(0,0);
        iRadius=0;
    }
    void setCircle(int a,int b,int c){
        center.setPoint(a,b);
        iRadius=c;
    }
    int get_radius(void){
        return iRadius;
    }
    friend int compare_circles(Circle,Circle);
};

int compare_circles(Circle cir1,Circle cir2){
    int iFlag;
    float fDist,fRadSum;
    fDist=cir1.center.get_distance_from(cir2.center);
    fRadSum=cir1.iRadius+cir2.iRadius;
    if(fDist){
        if(fDist==fRadSum){
            iFlag=1;
        }
        else if(fDist>fRadSum){
            iFlag=0;
        }
        else if(fDist<fRadSum){
            iFlag=-1;
        }
    }
    else{
        if(cir1.iRadius==cir2.iRadius){
            iFlag=2;
        }
        else if(cir1.iRadius<cir2.iRadius){
            iFlag=3;
        }
        else{
            iFlag=4;
        }
        
    }
    return iFlag;
}

int main(){
    int a,b,c;
    Circle cir1,cir2;
    cout<<"Enter center coordinates for circle 1:";
    cin>>a>>b;
    cout<<"Enter radius of circle 1:";
    cin>>c;
    cir1.setCircle(a,b,c);
    cout<<"Circle 1 set!"<<endl;
    cout<<"Enter center coordinates for circle 2:";
    cin>>a>>b;
    cout<<"Enter radius of circle 2:";
    cin>>c;
    cir2.setCircle(a,b,c);
    cout<<"Circle 2 set!"<<endl;
    switch(compare_circles(cir1,cir2)){
        case -1:cout<<"Circles intersect each other";
                break;
        case 0: cout<<"Circles are disjoint";
                break;
        case 1: cout<<"Circles touch each other";
                break;
        case 2: cout<<"Circles are concentric and identical";
                break;
        case 3: cout<<"Circles are concentric and circle 1 is contained within circle 2";
                break;
        case 4: cout<<"Circles are concentric and circle 2 is contained within circle 1";
    }           
    cout<<endl;
    return 0;
}