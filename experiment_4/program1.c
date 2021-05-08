#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int top=-1;
int stack[MAX];
void push(int);
int pop();
int peek();
void display();
int isfull();
int isempty();

int main()
{
	
	int c,x;
	do
	{
	printf("Select your choice:\n");
	printf("1.Push	2.Pop	3.Display top	4.Display all	0.Exit\n");
	scanf("%d",&c);
	
	switch(c)
	{
		case 1:printf("\nEnter element to be pushed\n");
				scanf("%d",&x);
				push(x);
				printf("\n");
				break;
	
		case 2:x=pop();
				printf("%d was popped\n",x);
				printf("\n");
				break;
				
		case 3:x=peek();
				printf("Element at the top is %d\n",x);
				printf("\n");
				break;
				
		case 4:display();
				printf("\n");
				break;
				
		default:if(c)
				printf("Invalid option. Select again\n");
				
		}
	}while(c!=0);
}


void push(int x)
{
	if(isfull())
		printf("STACK OVERFLOW\n");
		
	else
	stack[++top]=x;
}

int pop()
{
	if(isempty())
		{
			printf("STACK UNDERFLOW\n");
			exit(1);
		}
	else
	return stack[top--];
}

int peek()
{
	if(isempty())
		{
			printf("STACK UNDERFLOW\n");
			exit(1);
		}
		
	else
	return stack[top];
}

void display()
{
	if(isempty())
		printf("STACK UNDERFLOW\n");
		
	else
	{
		int i=top;
		
		printf("Elements in the stack\n");
		for(i=top;i>=0;i--)
			printf("%d	",stack[i]);
		
		printf("\n");
	}
}
int isempty()
{
	if(top==-1)
	return 1;
	
	else
	return 0;
}

int isfull()
{
	if(top==MAX-1)
	return 1;
	
	else
	return 0;
}
		
