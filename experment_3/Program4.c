#include<stdio.h>
#include<stdlib.h>

struct element
{
	int data;
	struct element *next;
}; typedef struct element node; 

node *create(node *);
void display(node *);
void divide(node *);

int main()
{
	node *start=NULL;
	
	start=create(start);
	printf("\nThe list is as follows\n");
	display(start);
	
	divide(start);
	return 0;
}


void divide(node *start)
{
	node *even=NULL,*odd=NULL;
	
	node *ptr=start,*p1,*p2;
	
	while(ptr!=NULL)
	{
		node *temp=(node*)malloc(sizeof(node));
		temp->next=NULL;
		temp->data=ptr->data;
		
		if(temp->data%2==0)
			{
				if(even==NULL)
					even=p1=temp;
					
				else
				{
					p1->next=temp;
					p1=temp;
				}
			}
			
		else
		{
			if(odd==NULL)
					odd=p2=temp;
					
			else
			{
				p2->next=temp;
				p2=temp;
			}
		}
		
		ptr=ptr->next;
	}
	
	printf("The division of the list into Even and Odd lists is as follows\n");
	printf("\nEven list:");
	display(even);
	printf("odd list:");
	display(odd);
}
		

node *create(node *start)
{
	int n,i;
	node *ptr;
	
	printf("Enter number of elements\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		node *temp=(node *)malloc(n*sizeof(node));
		temp->next=NULL;
		printf("\nEnter element at pos %d:",i);
		scanf("%d",&temp->data);
		if(i==1)
			start=ptr=temp;
		
		else
		{
			ptr->next=temp;
			ptr=temp;
		}
	}
	
	return start;
	
}

void display(node *start)
{
	printf("\n");
	if(start!=NULL)
	{
		node *ptr=start;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
	
	else
	printf("The list is empty\n");
	printf("\n\n");
}
