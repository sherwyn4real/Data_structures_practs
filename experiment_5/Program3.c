#include<stdio.h>
#include<stdlib.h>

struct element
{
	int data;
	struct element*next;
};
typedef struct element node;

node * rear = NULL;
node *front =NULL;
int isempty();
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
	printf("1.Insert	2.Delete	3.Display all	  0.Exit\n");
	scanf("%d",&c);
	
	switch(c)
	{
		case 1:printf("\nEnter element to be inserted\n");
				scanf("%d",&x);
				insert(x);
				printf("\n\n");
				break;
	
		case 2:x=del();
				if(x!= -1)
					printf("%d was deleted\n\n",x);
				else
					goto start;
				break;
				
				
		case 3:display();
				printf("\n\n");
				break;
				
		default:if(c)
				printf("Invalid option. Select again\n\n");
				
		}
	}while(c!=0);
}

void insert(int x)
{
	
			node *temp = (node*)malloc(sizeof(node));
			temp->next=NULL;
			temp->data=x;
			if(rear == NULL)
			{	
				front = rear = temp;
				rear->next = front;
			}
				
			else
			{	
				rear->next = temp;
				temp->next = front;
				rear = temp;
			}
		
}

int del()
{
	if(isempty())
	{
		printf("Queue underflow\n\n\n");
		return -1;
	}
	
	else
	{
		node *temp=front; int x;
		front = front->next;
		x=temp->data;
		free(temp);
			if(front == rear->next)
				{	
					printf("%d was deleted\n\n",x);
					front = rear = NULL;
					return -1;
				}
		return x;
	}
}

int isempty()
{
	if(front == NULL && rear == NULL)
		return 1;
		
	else
		return 0;
}

void display()
{
	if(isempty())
		printf("Empty Queue\n");
		
	else
	{
		node *ptr = front;
		printf("The elements in the queue are as follows:\n");
		do
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}while(ptr!=rear->next);
		
		printf("\n\n");
	}
}

