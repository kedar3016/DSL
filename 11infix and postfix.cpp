/* 
Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions 

i.	Operands and operator, both must be single character. 
ii.	Input Postfix expression must be in a desired format. 
iii.	Only '+', '-', '*' and '/ ' operators are expected

*/

#include<iostream>
#include<stdlib.h>
#include<math.h>
#define SIZE 20

using namespace std;

template <class T>
class mystack
{
	private :
		T ST[SIZE];
		int top;
	public : 
		mystack();
		void push(T X);
		T pop();
		int isEmpty();
		int isFull();
		T get_stacktop();
};

template <class T>
mystack <T> :: mystack()
{
 	top = -1;
}

template <class T>
T mystack <T> :: get_stacktop()
{
	return ST[top];
}

template <class T>
void mystack <T> :: push(T X)
{
	if(!isFull())
	{
		top++;
		ST[top] = X;
	}
	else
		cout<<"\nStack Overflow !! Error!!";
}

template <class T>
T mystack <T> :: pop()
{
	T X;
	X = ST[top];
	top--;
	return X;		
}

template <class T>
int mystack <T> :: isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}

template <class T>
int mystack <T> :: isFull()
{
	if(top == SIZE-1)
		return 1;
	else
		return 0;
}

int ICP(char ch)
{
  switch(ch)
  {
    case '+' : return(1);
    case '-' : return(1);
    case '*' : return(2);
    case '/' : return(2);
    case '%' : return(2);
    case '^' : return(4);
    case '(' : return(5);
    default : return(-1);
  }
}

int ISP(char ch)
{
  switch(ch)
  {
    case '+' : return(1);
    case '-' : return(1);
    case '*' : return(2);
    case '/' : return(2);
    case '%' : return(2);
    case '^' : return(3);
    case '(' : return(0);
    default : return(-1);
  }
}

void convert_infix_to_postfix(char inf[],char pos[])
{
	mystack <char>S;
  	int i,k=0;
  	for(i=0;inf[i] != '\0';i++)
  	{
    	if(inf[i] >= 'a' && inf[i] <= 'z')
    	{
    		pos[k++] = inf[i];
    	}
    	else
    	{
      		if(inf[i] == ')')
      		{
				do
				{
	  				pos[k++] = S.pop(); 
				}while(S.get_stacktop() != '(');
				S.pop();  // pop the opening bracket
      		}
      		else
      		{
				if(inf[i] == '(')
					S.push(inf[i]);
				else
				{
	 				while( !S.isEmpty() && ( ICP( inf[i]) <= ISP(S.get_stacktop() ) ))
	 				{
	    				pos[k++] = S.pop();  // pop
	 				}
	 				S.push(inf[i]);
      			}
    		}
  		}
	}
  	while(!S.isEmpty())
  	{
    	pos[k++] = S.pop();  // pop
  	}
  	pos[k] = '\0';
}

int getvalue(char Operand[],int Value[],int n,char ch)
{
	int j;
	for(j=0;j<n;j++)
		if(Operand[j] == ch)
	    	return(Value[j]);
    return(-1);
}

int evaluate_postfix_expression(char postfix[])
{
	int n,i,V[10],j,op1,op2,r;
	mystack <int>S;
   	char OP[10],oper;
   	cout<<"\nEnter the no of operands : ";
   	cin>>n;

   	for(i=0;i<n;i++)
	{
		cout<<"Enter "<<i+1<<"operand & its value : ";
		cin>>OP[i]>>V[i];
	}
   	for(i=0;postfix[i] != '\0';i++)
   	{
	 	if(postfix[i] >= 'a' && postfix[i] <= 'z') //checking for operand
	 	{
	    	S.push(getvalue(OP,V,n,postfix[i]));  // pushing the operand value on the stack
	 	}
	 	else
	 	{
	    	op2 = S.pop();  // pop the second operand
	    	op1 = S.pop(); // pop the first operand
	    	oper = postfix[i];
	    	switch(oper)
	    	{
		 		case '+' : 	r = op1 + op2;
				  			break;
		 		case '-' : 	r = op1 - op2;
				  			break;
		 		case '*' : 	r = op1 * op2;
				  			break;
		 		case '/' : 	r = op1 / op2;
				  			break;
		 		case '%' : 	r = op1 % op2;
				  			break;
		 		case '^' : 	r = (int)pow(op1,op2);
				  			break;
	    	}
	    	S.push(r);
	 	}
   	}
   	return(S.pop());
}

int main()
{
	int ch,r;
	char infix[30],postfix[30];
	system("clear");
	do
	{
		cout<<"\n\t\t\t1 : Infix to postfix conversion";
		cout<<"\n\t\t\t2 : Postfix evaluation";
		cout<<"\n\t\t\t3 : Exit";
		cout<<"\n\nEnter ur choice : ";
		cin>>ch;
		switch(ch)
		{

			case 1 : cout<<"\nEnter the infix expression : ";
  					 cin>>infix;
					 cout<<"\nThe infix expression is : "<<infix;
  					 convert_infix_to_postfix(infix,postfix);
					 cout<<"\nThe postfix expression is : "<<postfix;
					 break;
			case 2 : cout<<"\nThe postfix expression is : "<<postfix;
					 r = evaluate_postfix_expression(postfix);
					 cout<<"\nThe postfix evaluation result is : "<<r;
					 break;
			case 3 : cout<<"\nEnd of Program\n";
					 break;
			default: cout<<"\nInvalid choice !! Try again\n\n";
		}
	}while(ch != 3);
	return 0;
}
