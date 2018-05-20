#include<iostream>
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

    int operator==(MATRIX &M2){
        if(rows==M2.cols)
            return 1;
        else 
            return 0;
    }

    MATRIX operator*(MATRIX &m2){
        MATRIX temp(rows,m2.cols);
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                for(int k=0;k<m2.rows;k++)
                    temp.mat[i][j]=temp.mat[i][j]+mat[i][k]*m2.mat[k][j];
        return temp;
    }

    friend ostream& operator<<(ostream&,MATRIX&);
    friend istream& operator>>(istream&,MATRIX&);
};

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
        cout<<"Multiplication of matrices"<<endl;
        cout<<m1;
        cout<<"\nand\n";
        cout<<m2<<endl;
        cout<<"is\n";
        MATRIX m3(m1*m2);
        cout<<m3;
    }
    else{
        cout<<"Matrices not compatible for multiplication"<<endl;
        exit(0);
    }
    cout<<endl;
    return 0;
}