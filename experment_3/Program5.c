#include<stdio.h>
#include<stdlib.h>

struct element
{
	int data;
	struct element *next;
}; typedef struct element node; 

node *create(node *);
void display(node *);
void duplicate(node *,int);

node *start2=NULL;
node *ptr2;

int main()
{
	node *start=NULL;
	
	start=create(start);
	printf("\nThe list is as follows\n");
	display(start);
	
	if(start2==NULL)
		printf("There are no duplicates\n");
	else
	{
		printf("The duplicate elements are:\n");
		display(start2);
	}
	
	return 0;
}


void duplicate(node *start,int x)
{
	
	node *ptr=start;
	
	int c=0;
	
	while(ptr!=NULL)
	{
		node *temp=(node *)malloc(sizeof(node));
		temp->next=NULL;
		temp->data=x;
		if(temp->data==ptr->data)
			{
				c++;
				
				if(c==2)
				{
					
					if(start2==NULL)
						start2=ptr2=temp;
						
					else
					{
						node *p=start2;
						while(p!=NULL)
						{
							if(p->data==temp->data)
								break;
			
						else
						
							{
							ptr2->next=temp;
							ptr2=temp;
						}
						
						p=p->next;
						
					}
					}
				}
			}
		ptr=ptr->next;
		}
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
		duplicate(start,temp->data);
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
