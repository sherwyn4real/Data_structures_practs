#include<stdio.h>
#include<stdlib.h>

struct element
{
	int data;
	struct element *next;
}; typedef struct element node; 


node * create(node *);
void display(node *);
node *intersect(node*,node*,int,int);
int count(node *);

int main()
{	
	int n1,n2;
	
	node *start1=NULL;
	node *start2=NULL;
	node *start3=NULL;
	
	printf("Enter number of elements in List 1\n");
	start1=create(start1);
	printf("\nEnter number of elements in List 2\n");
	start2=create(start2);
	
	n1=count(start1);
	n2=count(start2);
	
	printf("\nThe two lists entered are:\nList1: ");
	display(start1);
	printf("\nList2: ");
	display(start2);
	

	start3=intersect(start1,start2,n1,n2);
	
	if(start3!=NULL)
		{
			printf("\nThe intersection of the two lists is:\n");
			display(start3);
		}
	else
		printf("There are no common elements in these lists\n");
	
}
	
	
node * create(node *start)
{
	int n,i;
	node *ptr;
	
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		node *temp=(node *)malloc(n*sizeof(node));
		temp->next=NULL;
		printf("\nEnter element at pos %d: ",i);
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
node *intersect(node *start1, node *start2,int n1,int n2)
{
	node *p1=start1;
	node *p2=start2;
	
	node *start3,*ptr;
	start3=NULL;
	int i=1;
	
	
	if(n1<=n2)
	{	
		while(i++<=n1)
		{	
			p2=start2;
			while(p2!=NULL)
			{
				
				if(p1->data==p2->data)
					{
						node *temp;
						temp=(node *)malloc(sizeof(node));
						temp->next=NULL;
					
						temp->data=p1->data;
						
						if(start3==NULL)
							start3=ptr=temp;
							
						else
						{
							ptr->next=temp;
							ptr=temp;
						}
					}
					p2=p2->next;
				}
		p1=p1->next;
		}
	}
	
	else
	{	
		while(i++<=n2)
		{
			p1=start1;
				while(p1!=NULL)
				{
				if(p2->data==p1->data)
					{
						node *temp;
						temp=(node *)malloc(sizeof(node));
						temp->next=NULL;
					
						temp->data=p2->data;
						
						if(start3==NULL)
							start3=ptr=temp;
						else
						{
							ptr->next=temp;
							ptr=temp;
						}
					}
					p1=p1->next;
				}
			p2=p2->next;
			}
	
		
	} 
	return start3;

}

int count(node *start)
{
	int c=0;
	if(start!=NULL)
	{
		node *ptr=start;
		while(ptr!=NULL)
		{
				c++;
				ptr=ptr->next;
			}
		return c;
	}
	
	else
		return c;
	}
	
	
void display(node *start)
{
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
	
}
