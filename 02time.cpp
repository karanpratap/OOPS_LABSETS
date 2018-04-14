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
};

int main(){
    
}