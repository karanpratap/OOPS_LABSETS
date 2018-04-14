/* 
Create a RainGauge class that store rainfallincm information and city name. Include a zero parameter
constructor. Implement the following methods
fnReadMeasurement that generates a random decimal value in the range 0-20cms and reads the name
of the city
fnDispReading that display city name and rainfall received
Write a friend function that takes an array of RainGauge objects and the number of cities as parameters
and calculates the average rainfall received
Create an array of RainGauge objects in main and display the results
*/

#include "iostream"
#include "string"
#include "cstdlib"

using namespace std;

class RainGauge{
    string cityName;
    float rainfallincm;
    public:
    RainGauge(void){
        cityName="noname";
        rainfallincm=0.0;
    }
    void fnReadMeasurement(string);
    void fnDispReading(void);
    friend float avg_rain(RainGauge[],int);
};

void RainGauge::fnReadMeasurement(string name){
    int iRand;
    cityName=name;
    iRand=rand()%20;
    rainfallincm=drand48()+iRand;
}

void RainGauge::fnDispReading(void){
    cout<<cityName<<":"<<rainfallincm<<endl;
}

float avg_rain(RainGauge rg[],int n){
    float avg=0.0;
    for(int i=0;i<n;i++){
        avg+=rg[i].rainfallincm;
    }
    return (avg/n);
}

int main(){
    int MAXSIZE;
    string name;
    srand(time(NULL));
    cout<<"Enter number of cities:";
    cin>>MAXSIZE;
    RainGauge rg[MAXSIZE];
    for(int i=0;i<MAXSIZE;i++){
        cout<<"Enter name of city "<<i+1<<": ";
        cin>>name;
        rg[i].fnReadMeasurement(name);
    }
    cout<<endl;
    cout<<"DATA of cities and their rainfall:"<<endl;
    for(int i=0;i<MAXSIZE;i++){
        rg[i].fnDispReading();
    }
    float avg=avg_rain(rg,MAXSIZE);
    cout<<"Average Rainfall:"<<avg<<endl;
    return 0;
}