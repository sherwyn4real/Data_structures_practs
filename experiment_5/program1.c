#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int q[MAX];
int front=-1;
int rear=-1;

int isfull();
int isempty();
void insert(int x);
int del();
int peek();
void display();
int main()
{
	int c,x;
	
	start:
	do
	{
	printf("Select your choice:\n");
	printf("1.Insert	2.Delete	3.Display front		4.Display all	0.Exit\n");
	scanf("%d",&c);
	
	switch(c)
	{
		case 1:printf("\nEnter element to be inserted\n");
				scanf("%d",&x);
				insert(x);
				printf("\n");
				break;
	
		case 2:x=del();
				if(x!= -1)
					printf("%d was deleted\n",x);
				else
					goto start;
				break;
				
		case 3:x=peek();
				if(x!= -1)
					printf("Element at the front is %d\n",x);
				else
					goto start;
				break;
				
		case 4:display();
				printf("\n");
				break;
				
		default:if(c)
				printf("Invalid option. Select again\n");
				
		}
	}while(c!=0);
}

void insert(int x)
{
	if(isfull())
			printf("Queue overflow\n");
			
	else
		{
			q[++rear]=x;
			if(front == -1)
				front=0;
		}
}

int del()
{
	if(isempty())
	{
		printf("Queue underflow\n");
		return -1;
	}
	
	else
	{
		front++;
		return q[front-1];
	}
}

int peek()
{
	if(isempty())
	{
		printf("Queue underflow\n");
		return -1;
	}
	else
		return q[front];
}

int isempty()
{
	if(rear ==-1 || front == rear+1)
	{
		if(front == rear+1)
			front=rear=-1;
			
		return 1;
	}
		
	else
		return 0;
}

int isfull()
{
	if(rear == MAX-1)
			return 1;
			
	else
		return 0;
}

void display()
{
	if(isempty())
		printf("Empty queue\n");
		
	else
	{
		printf("The elements in the queue are:\n");
		int i;
		for(i=front;i<=rear;i++)
			printf("%d ",q[i]);
			
		printf("\n\n");
	}
}
		
