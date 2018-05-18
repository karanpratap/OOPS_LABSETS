/*
Write a C++ program to create class called MATRIX using a two dimensional array of integers. Implement
the following operations by overloading the operator == which checks the compatibility of two matrices
m1 and m2 to be added and subtracted. Perform the addition and subtraction by overloading the operator
+ and – respectively. Display the results (sum matrix m3 and difference matrix m4) by overloading the
operator <<.
*/

#include "iostream"
using namespace std;

class MATRIX{
    int rows,cols;
    int **mat;
    public:
    MATRIX(int x,int y){
        rows=x;
        cols=y;
        mat=new int*[rows];
        for(int i=0;i<rows;i++){
            mat[i]=new int[cols];
        }
    }
    
    MATRIX(const MATRIX & m){
        rows=m.rows;
        cols=m.cols;
        mat=new int*[rows];
        for(int i=0;i<rows;i++){
            mat[i]=new int[cols];
        }
        for(int i=0;i<m.rows;i++)
            for(int j=0;j<m.cols;j++)
                mat[i][j]=m.mat[i][j];
    }

    int operator==(MATRIX &M2){
        if(rows==M2.rows && cols==M2.cols)
            return 1;
        else 
            return 0;
    }
    MATRIX operator+(MATRIX &);
    MATRIX operator-(MATRIX &);
    friend ostream& operator<<(ostream&,MATRIX&);
    friend istream& operator>>(istream&,MATRIX&);
};

MATRIX MATRIX::operator+(MATRIX &M2){
    MATRIX temp(rows,cols);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            temp.mat[i][j]=mat[i][j]+M2.mat[i][j];
    return temp;
}

MATRIX MATRIX::operator-(MATRIX &M2){
    MATRIX temp(rows,cols);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            temp.mat[i][j]=mat[i][j]-M2.mat[i][j];
    return temp;
}

ostream& operator<<(ostream& out,MATRIX &m){
    cout<<endl;
    for(int i=0;i<m.rows;i++){
        for(int j=0;j<m.cols;j++)
            out<<m.mat[i][j]<<"\t";
        out<<endl;
    }
    return out;
}

istream& operator>>(istream& in,MATRIX &m){
     for(int i=0;i<m.rows;i++)
        for(int j=0;j<m.cols;j++)
            in>>m.mat[i][j];
    return in;
}

int main(){
    int cols,rows;
    cout<<"Enter the rows and columns of matrix 1:";
    cin>>rows>>cols;
    MATRIX m1(rows,cols);
    cout<<"Enter elements for matrix 1:\n";
    cin>>m1;
    cout<<"Enter the rows and columns of matrix 2:";
    cin>>rows>>cols;
    MATRIX m2(rows,cols);
    cout<<"Enter elements for matrix 2:\n";
    cin>>m2;
    if(m1==m2){
        cout<<"Addition of matrices"<<endl;
        cout<<m1;
        cout<<"\nand\n";
        cout<<m2<<endl;
        cout<<"is\n";
        MATRIX m3(m1+m2);
        cout<<m3;
        cout<<"\nAnd Subtraction is\n";
        MATRIX m4(m1-m2);
        cout<<m4;
    }
    else{
        cout<<"Matrices not compatible for addition and subtraction"<<endl;
        exit(0);
    }
    cout<<endl;
    return 0;
}