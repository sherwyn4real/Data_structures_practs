#include<stdio.h>
#include<stdlib.h>
struct element
	{
		int data;
		struct element* next;
	}; typedef struct element node;

	

 
int main()
{
	
	node* start;
	start=NULL;
	
	node* create(node *);
	void display(node *);
	
	void search(node *,int);
	node *reverse(node *);
	int c,x;
	
	
	start=NULL;
	
	
	
	do
	{
	printf("Enter a choice\n");
	printf("1.Creation 2.Display 3.reverse 4.search 0.exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:start=create(start);break;
		case 2:display(start);break;
		case 3:start=reverse(start);break;
		case 4:printf("Enter element to be searched\n");
				scanf("%d",&x);
				search(start,x);
				break;
		default: if(c)
				 printf("invalid choice\n");
			 }
				 
	}while(c!=0);
	

}
	node* create(node *start)
{
	node *ptr,*temp=NULL;
	int n,i;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	
	
	
	for(i=1;i<=n;i++)
		{
		temp=(node*)malloc(sizeof(node));
		
		printf("Enter data in element %d\n",i);
		scanf("%d",&temp->data);
		temp->next=NULL;
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

void display(node * start)
{
	if(start==NULL)
	printf("LIST DOESNT EXIST\n");
	
	
	else
		{
		 node* ptr=start;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		
		printf("\n");
	}
	
	
	
}
	

void search(node *start, int x)
{
	
	if(start!=NULL)
	{
		node *ptr=start;

		
		while(ptr!=NULL)
			{
				
				if(ptr->data==x)
				{
					printf("found!\n");
					break;
				}
			ptr=ptr->next;
				
			}
			
		if(ptr==NULL)
		printf("Not found!\n");;
	}
	
	else
	printf("The list doesnt exist\n");
}
	
node * reverse(node *start)
{
	if(start!=NULL)
	{
		node *prev,*front,*ptr;
		
		ptr=start;
		
		prev=NULL;
		while(ptr!=NULL)
		{
			front=ptr->next;
			ptr->next=prev;
			prev=ptr;
			ptr=front;
		}
		
		start=prev;
		}
	
	else
		printf("The list doesnt exist. Create one first\n");
		
	return start;
}
			
		


		


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*int n,r,c=0,m,t;

	
	printf("Enter a no\n");
		scanf("%d",&n);
		
		m=n;

		while(m>0)	
		{
			r=m%10;
			if(r!=0)
			{
				if(n%r=0)
					c=c+1;
				
			}
		m=m/10;
		}

	printf("%d\n",c);*/

	
	

