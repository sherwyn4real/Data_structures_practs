#include<stdio.h>
#include<stdlib.h>

struct element
{
	int data;
	struct element *next;
}; typedef struct element node; 

node * create(node *);
void display(node *);
node *merge(node*,node*,node*);
node * add(node *,node*);

int main()
{
	
	node *start1=NULL;
	node *start2=NULL;
	node *start3=NULL;
	
	printf("Enter number of elements in List 1\n");
	start1=create(start1);
	printf("\nEnter number of elements in List 2\n");
	start2=create(start2);

	
	printf("\nThe two lists entered are:\nList1: ");
	display(start1);
	printf("\nList2: ");
	display(start2);
	

	start3=merge(start1,start2,start3);
	
	printf("\nThe merged list is:\n");
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

node *merge(node *start1,node *start2,node* start3)
{
	node *ptr;
	node *p1=start1,   *p2=start2;
	
	while(p1!=NULL)
	{
		node *temp=(node *)malloc(sizeof(node));
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
	
	while(p2!=NULL)
	{
		node *temp=(node *)malloc(sizeof(node));
		temp->next=NULL;
		temp->data=p2->data;
		
		ptr->next=temp;
		ptr=temp;
		p2=p2->next;
	}
	return start3;

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
