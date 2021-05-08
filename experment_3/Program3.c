#include<stdio.h>
#include<stdlib.h>

struct element
{
	int data;
	struct element *next;
}; typedef struct element node; 


node * create(node *);
void display(node *);
node *duplicate(node*,node*,int,int);
int count(node *);
node * add(node *,node*);

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
	

	start3=duplicate(start1,start2,n1,n2);
	
	printf("\nThe union of the two lists is:\n");
	display(start3);
	
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
node *duplicate(node *start1, node *start2,int n1,int n2)
{
	node *p1=start1;
	node *p2=start2;
	
	node *start3,*ptr,*p3;
	start3=NULL;
	int i;
	
	
	if(n1>=n2)
	{	
		for(i=1;i<=n1 && p1!=NULL;i++)
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
					p1=p1->next;
				}
		
		
		for(i=1;i<=n2 && p2!=NULL;i++)
		{	
			p3=start3;
			for(p3->data=p3->data; p3!=NULL;p3=p3->next)
				if(p3->data==p2->data)
					break;
					
			if(p3==NULL)
			{
				node *temp;
				temp=(node *)malloc(sizeof(node));
				temp->next=NULL;
				temp->data=p2->data;
			start3=add(start3,temp);					//adds to the third list
			}
		p2=p2->next;
		}
	}
	
	
	
		
	else
	{	
		for(i=1;i<=n2 && p2!=NULL;i++)
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
					p2=p2->next;
				}
		
		
		for(i=1;i<=n2 && p1!=NULL;i++)
		{	
			p3=start3;
			for(p3->data=p3->data; p3!=NULL && p1->data!=p3->data;p3=p3->next);
				
			if(p3!=NULL)
				continue;
					
			else
			{
				node *temp;
				temp=(node *)malloc(sizeof(node));
				temp->next=NULL;
				temp->data=p1->data;
			start3=add(start3,temp);				//adds to the third list
			}
		p1=p1->next;
		}
		
	}
	
		
	return start3;

}

node *add(node *start3,node *temp)
{
	node *ptr=start3;
	while(ptr->next!=NULL)
		ptr=ptr->next;
		
	ptr->next=temp;
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
