/*
Write a C++ program that reads contents from two text files that are specified as command line argu-
ments and create a file by name “merge.txt”. Read one line at a time from each input file in an alternate
manner and write to the output file till you have reached the end.
*/

/*
THIS PROGRAM DOES THE ALTERNATE FUNCTION AS LONG AS THERE'S A CORRESPONDING LINE IN THE SECOND FILE
ONCE THE NUMBER OF LINES IN ONE FILE IS LESS, THE PROGRAM WILL DO THE ALTERNATE FUNCTION UNTIL ONE FILE's
LINES SURPASS THE OTHERS AFTER WHICH THE LINES OF THE SAME FILE ARE COPIED TO THE MERGE FILE BACK TO BACK
*/

#include "iostream"
#include "fstream"
#include "cstdlib"
#include "cstdio"
#define SIZE 100

using namespace std;

int main(int argc,char* argv[]){
    if(argc!=3){
        cout<<"Usage: <output_filename> <filename1> <filename2>\n";
        exit(0);
    }
    ifstream fin1,fin2;
    ofstream fout;
    char line[SIZE];
    fin1.open(argv[1],ios::in);
    fin2.open(argv[2],ios::in);
    fout.open("merge.txt",ios::out);
    if(fin1.is_open() && fin2.is_open()){
        while(!fin1.eof() || !fin2.eof()){
            if(!fin1.eof()){
                fin1.getline(line,SIZE);
                fout<<line<<endl;
            }
            if(!fin2.eof()){
                fin2.getline(line,SIZE);
                fout<<line<<endl;
            }
        }
    }
    else{
        cout<<"The specified files do not exist\n";
        exit(0);
    }
    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}