//05EXPRESSION.CPP

#include<iostream>
#include<stack>
#include<cctype>
using namespace std;


class ExpressionType{
	string infix, postfix;
	stack< char > st;
	public:
		void readExp();
		void toPostFix();
		void display();
		int preced( char );

};




int main(){

	ExpressionType exp;
	exp.readExp();
	exp.display();
	exp.toPostFix();
	exp.display();

}



void ExpressionType :: readExp(){
	cout<<"Enter an valid infix expression:";
	cin>>infix;
}

int ExpressionType :: preced( char ch){

	switch( ch )
	{
		case '#':
          case '(': return 0;

          case '+':
          case '-': return 1;

          case '*':
          case '/':
          case '%': return 2;

          case '$':
          case '^': return 3;


	}

}

void ExpressionType :: display(){
	cout<<"\nInfix expression : "<<infix<<"\nPostfix expression : "<<postfix;
}

void ExpressionType :: toPostFix(){

	int j=0;
	char ch;
	st.push('#');
	for(int i=0; i < infix.size(); i++)
	{
		char symb = infix[i];
		if( isalnum(symb) )
			postfix+= symb;
		else{
			switch( symb ){
				case '(' : st.push( '(' ); break;

				case ')' : while( st.top() != '(')
					 	 {
							postfix+=st.top();
							st.pop();
						 }
						 st.pop();
						break;
				default : while( preced(symb) <= preced(st.top()) )
						{
							postfix += st.top();
							st.pop();
						}
						st.push(symb);
			}

		}
		
	}

	while(st.top()!='#')
	{
		postfix +=st.top();
		st.pop();
	}
}