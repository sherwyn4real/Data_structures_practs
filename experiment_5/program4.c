#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int q[MAX];
int front=-1;
int rear=-1;

void insert(int x);
int del();
void display();
int main()
{
	int c,x;
	
	start:
	do
	{
	printf("Select your choice:\n");
	printf("1.Insert	2.Delete	3.Display all	0.Exit\n");
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
					printf("%d was deleted\n\n",x);
				else
					goto start;
				break;
				
		case 3:display();
				printf("\n");
				break;
				
		default:if(c)
				printf("Invalid option. Select again\n\n");
				
		}
	}while(c!=0);
}

void insert(int x)
{
	if((front == 0 && rear==MAX-1) || (front == rear+1))
			{
				printf("Queue overflow\n\n");
				return;
			}
		
			
		if(rear==MAX-1 && front!=0)
				rear=-1;
	
	if(front==-1)
		front++;
		
	q[++rear]=x;
		
}


int del()
{
		if(front==-1)
			{
			printf("Queue empty\n\n");
			return -1;
			}
		 if (front == rear)
			{
				int x;
				x=q[front];
				front=rear=-1;
				return x;
			}
		
		if(front == MAX-1)
			{
				front=0;
				return  q[MAX-1];
			}
			
		front++;
		return q[front-1];
}


void display()
{
	if(front == -1 && rear == -1)
		printf("Empty queue\n\n");
		
	else
	{
		printf("The elements in the queue are:\n");
		if(rear<front)
		{
			int i;
			for(i=front;i<MAX;i++)
				printf("%d ",q[i]);
				
			for(i=0;i<=rear;i++)
				printf("%d ",q[i]);
			printf("\n\n");
		}
		
		else
		{
			for(int i=front;i<=rear;i++)
				printf("%d ",q[i]);
			printf("\n\n");
				
		}
	}
}


		
