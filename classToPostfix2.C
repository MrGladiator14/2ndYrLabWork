#include <bits/stdc++.h>
#include <iostream>
#define size 100
using namespace std;
class EXPRESSION{
    char stack[100];
    int top;
    void push(char);
    char pop();
    bool isOperator(char);
    int precedence(char);
    public: EXPRESSION(){
        top=-1;
    }
    void infixToPostfix(char[],char[]);
    int j;
};
void EXPRESSION :: push(char item)
{
	if(top >= size-1)
	{
		cout<<"\nStack Overflow.";
	}
	else
	{
        top++;
		stack[top] = item;
	}
}
char EXPRESSION :: pop()
{
	char item ;

	if(top <0)
	{
		cout<<"stack under flow: invalid infix expression";
		return 'f';
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
bool EXPRESSION :: isOperator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return true;
	}
	else
	{
    	return false;
	}
}
int EXPRESSION :: precedence(char symbol)
{
	if(symbol == '^')
	{
		return(4);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-'){
		return(1);
	}
	else
	{
		return(0);
	}
}
void EXPRESSION :: infixToPostfix(char infixExp[], char postfixExp[])
{
	int i;
	char item;
	char x;

	push('(');
	strcat(infixExp,")");
	i=0;
	j=0;
	item=infixExp[i];

	while(item != '\0')
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfixExp[j] = item;
			j++;
		}
		else if(isOperator(item))
		{
			x=pop();
			if((isOperator(x)) && (precedence(x) >= precedence(item)))
			{
				postfixExp[j] = x;
                j++;
				x = pop();
			}
            push(x);
            push(item);
		}
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfixExp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			cout<<"\nInvalid infix Expression.\n"<<"bracket!\n";
			return;
		}
		i++;
		item = infixExp[i];
	}
	if(top>0)
	{
		cout<<"\nInvalid infix Expression.\n"<<"top!\n";
		return;
	}


	postfixExp[j] = '\0';


}
int main(){
	char infix[size], postfix[size];
    EXPRESSION obj;


	cout<<"Infix expression : ";
	gets(infix);

	obj.infixToPostfix(infix,postfix);
	cout<<"Postfix Expression: ";
	for(int i=0;i<obj.j;i++)
    cout<<postfix[i]<<", ";
    cout<<endl;

	return 0;
}