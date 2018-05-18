/*
Write a C++ program to create a template functions for Insertion sort and Selection Sort. Demonstrate
sorting of integers and double data types for both sorting algorithms.
*/

#include "iostream"
const int SIZE=5;

using namespace std;

template<class T>
void selection_sort(T arr[],const int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++)
          if(arr[j]<arr[min])
            min=j;
        T temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

template<class T>
void insertion_sort(T arr[],const int n){
   T key;
   int i,j;
   for(i=1;i<n;i++){
       key=arr[i];
       j=i-1;
       while(j>=0 && arr[j]>key){
           arr[j+1]=arr[j];
           j=j-1;
       }
       arr[j+1]=key;
   }
}

int main(){
    int intarray[SIZE];
    double dbarray[SIZE];
    cout<<"Enter elements for integer array:"<<endl;
    for(int i=0;i<SIZE;i++){
        cin>>intarray[i];
    }
    cout<<"Enter elements for double array:"<<endl;
    for(int i=0;i<SIZE;i++){
        cin>>dbarray[i];
    }
    cout<<endl<<endl<<"Before sorting,status of arrays:"<<endl<<endl;
    cout<<"INTEGER ARRAY:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<intarray[i]<<" ";
    }
    cout<<endl<<endl<<"DOUBLE ARRAY:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<dbarray[i]<<" ";
    }
    cout<<endl<<endl;
    selection_sort(intarray,SIZE);
    insertion_sort(dbarray,SIZE);
    cout<<"After Sorting:"<<endl;
    cout<<"INTEGER ARRAY:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<intarray[i]<<" ";
    }
    cout<<endl<<endl<<"DOUBLE ARRAY:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<dbarray[i]<<" ";
    }
    cout<<endl;
    return 0;
}