#include<stdio.h>
#include<stdlib.h>

struct element
{
	int data;
	struct element*next;
};
typedef struct element node;

int i=0;
void push(int);
int pop();
int peek();
void display();
int isfull();
int isempty();

node *top=NULL;
int n;

int main()
{
	int c,x;
	
	printf("Enter number of elements\n");
	scanf("%d",&n);
	
	do
	{
	
	if(n<=0)
		{
		printf("Invalid number\n");
		exit(1);
		}
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
				printf("\n\n");
				break;
				
		default:if(c)
				printf("Invalid option. Select again\n");
				
		}
	}while(c!=0);
}

void push(int x)
{
	if(isfull())
		printf("STACK OVERLFOW\n");
		
	else
	{
		node *temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->next=NULL;
		temp->next=top;
		top=temp;
		i++;
	}
}

int pop()
{
	if(isempty())
		{
			printf("STACK UNDERFLOW\n");
			exit(1);
		}
		
	else
	{
		int x;
		node *temp=top;
		top=top->next;
		x=temp->data;
		free(temp);
		return x;
	}
}

int peek()
{
	if(isempty())
		{
			printf("STACK UNDERFLOW\n");
			exit(1);
		}
		
	else
	return top->data;
}

void display()
{
	if(isempty())
	{
		printf("STACK UNDERFLOW\n");
			exit(1);
		}
	
	else
	{
		node *ptr=top;
		
		printf("\nThe elements in the stack are:\n");
		while(ptr!=NULL)
		{
			printf("%d	",ptr->data);
			ptr=ptr->next;
		}
	}
}

int isfull()
{
	if(i==n)
		return 1;
		
	else
		return 0;
}

int isempty()
{
	if(top==NULL)
		return 1;
		
	else 
	return 0;
}
			
	
	
