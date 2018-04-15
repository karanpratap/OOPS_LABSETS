/*
Write a C++ program to perform the following string operations by using the C++ string library
i. Parameterized and copy constructor
ii. Compare two string objects
iii. Find substring in a main string
iv. Return the position of the first occurrence a given substring in the string.
v. Return the position of the last occurrence a given substring in the string
vi. Insert a given substring at the end of main string
vii. Swap content of two given strings
*/

#include "iostream"
#include "string"

using namespace std;

int main(){
    string s1("Its 2:52 am");   //Parameterized constructor
    string s2(s1);              //copy constructor
    string s3="Wake up";        //Direct assignment
    
    //comparing s2 and s3

    if(s2==s3)
        cout<<"s2 is same as s3";
    else if(s2>s3)
        cout<<"s2 is greater than s3";
    else if(s2<s3)
        cout<<"s2 is less than s3";
    else    
        cout<<"Something's fishy";
    cout<<endl;

    if(s2>=s3)
        cout<<"s2 is greater than or equal to s3";
    else if(s2<=s3)
        cout<<"s2 is less than or equal to s3";
    else
        cout<<"Fishy!";
    cout<<endl;

    string s4=s2+" "+s3; //adding and assigning to a new string
    cout<<s4<<endl;

    int x=s3.compare(s4);   //comparing using compare function
    if(x==0)
        cout<<"s3==s4";
    else if(x>0)
        cout<<"s3>s4";
    else    
        cout<<"s3<s4";
    cout<<endl;

    x=s3.compare(0,4,s4,0,4);   //comparing portions of strings using compare
    if(x==0)
        cout<<"s3==s4";
    else if(x>0)
        cout<<"s3>s4";
    else    
        cout<<"s3<s4";
    cout<<endl;
    cout<<s3.substr(4,4)<<endl;                  //displaying substrings using substr
    
    cout<<"substring am in s4 found at pos:"<<s4.find("am")<<endl;  //finding a substring in a string
    
    string s5="this is a this test for this error";
    cout<<"new string s5: "<<s5<<endl;

    //return position of first and last occurence of a substring

    cout<<"first substring this in s5 found at pos:"<<s5.find_first_of("this")<<endl;
    cout<<"last substring this in s5 found at pos:"<<s5.find_last_of("this")<<endl;

    cout<<"Before swapping,s2="<<s2<<"; s3="<<s3<<endl;
    s2.swap(s3);                //swapping contents of 2 strings
    cout<<"After swapping,s2="<<s2<<"; s3="<<s3<<endl;
    return 0;
}