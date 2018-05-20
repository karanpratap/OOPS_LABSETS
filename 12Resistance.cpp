/*
Write a class called ResistancePair that represents a pair of resistance connected either in series or parallel.
Implement a method too read the resistance values of the resistance pair. Provide a pure virtual function
that calculates the combined resistance of the resistance pair which will be implemented in its child
classes namely SeriesResistancePair and ParallelResistancePair. Now calculate the combined resistance
of 4 ResistancePair objects connected in parallel.
Note :
the combined resistance for two resistors connected in series is the sum of its individual resistances.
the combined resistance for two resistors connected in parallel is the reciprocal of the sum of the individual
reciprocal of the resistances.
*/

#include<iostream>
using namespace std;

class ResistancePair{
    protected:
    float r1,r2;
    public:
    void readRes(void){
        cout<<"Enter values of r1 and r2:";
        cin>>r1>>r2;
    }
    virtual float netRes(void)=0;
};

class SeriesResistancePair:public ResistancePair{
    public:
    float netRes(void){
        return (r1+r2);
    }
};

class ParallelResistancePair:public ResistancePair{
    public:
    float netRes(void){
        return (r1*r2)/(r1+r2);
    }
};

int main(){
    ResistancePair *ptr[4];
    char ch;
    for(int i=0;i<4;i++){
        cout<<"Enter type of Resistance(s or p):";
        cin>>ch;
        if(ch=='s'){
            ptr[i]=new SeriesResistancePair;
        }
        else if(ch=='p'){
            ptr[i]=new ParallelResistancePair;
        }
        else{
            cout<<"Wrong type"<<endl<<"Program will terminate now!"<<endl;
            exit(0);
        }
        ptr[i]->readRes();
    }
    float Den=0,netResistance;
    for(int i=0;i<4;i++){
        Den+=(1/ptr[i]->netRes());
    }
    netResistance=1/Den;
    cout<<"Net Resistance of the 4 resistance pairs connected in parallel:"<<netResistance<<endl;
    return 0;
}