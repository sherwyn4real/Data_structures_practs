#include<stdio.h>
#include<stdlib.h>

struct element
{
	int data;
	struct element *next;
}; typedef struct element node; 


node *create(node *);
void display(node *);
int count(node *);
void search(node *, int);
node *delete(node *);
node *reverse(node *);
node *addatbeg(node *,int);
node *addatend(node *,int);
node *addafter(node *,int,int);
node *addbefore(node *,int,int);
node *addatpos(node *,int,int);

int main()
{
	node *start=NULL;
	int c,x,number,item,p;
	
	do
	{
		printf("Please select your option\n");
		printf("1.Create\n2.Add at beginning\n3.Add at end\n4.Add after a node\n5.Add before a node\n6.Add at a particular position\n7.Display\n8.Search\n9.Count\n10.Delete\n11.Reverse\n0.exit\n\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:start=create(start);
					printf("\n\n");
					break;
					
			case 2:	printf("Enter the number to be inserted\n");
					scanf("%d",&x);
					start=addatbeg(start,x);
					printf("\n\n");
					break;
			
			case 3: printf("Enter the number to be inserted\n");
					scanf("%d",&x);
					start=addatend(start,x);
					printf("\n\n");
					break;
			
			case 4:	printf("Enter the number to be inserted\n");
					scanf("%d",&x);
					printf("Enter the element after which to insert : ");
					scanf("%d", &item);
					start=addafter(start,x,item);
					printf("\n\n");
					break;
			
			case 5: printf("Enter the number to be inserted\n");
					scanf("%d",&x);
					printf("Enter the element before which to insert : ");
					scanf("%d", &item);
					start=addbefore(start,x,item);
					printf("\n\n");
					break;
			
			case 6: printf("Enter the number to be inserted and its position\n");
					scanf("%d %d",&x,&p);
					start=addatpos(start,x,p);
					break;
			
			case 7:display(start);
					break;
			
			case 8:printf("Enter element to be searched\n");
					scanf("%d",&x);
					search(start,x);
					break;
					
			case 9:number=count(start);
					if(number!=1)
						printf("There are %d elements in the list\n",number);
					else
						printf("There is %d elements in the list\n",number);
					break;
					
			case 10:start=delete(start);
					break;
					
			case 11:start=reverse(start);
					break;
					
			default: if(c)
						printf("Incorrect option chosen. Please enter again\n");
		}
	}while(c!=0);
	
}

node *create(node *start)
{
	int i,n;
	int num;
	
	printf("Enter number of elements\n");
	scanf("%d",&n);
	
	start=NULL;
	if(n==0)
		return start;
		
	printf("Enter element at position 1\n");
	scanf("%d",&num);
	start=addatbeg(start,num);
	
	for(i=2;i<=n;i++)
	{
		printf("Enter element at position %d\n",i);
		scanf("%d", &num);
		start=addatend(start,num);
	}
	
	return start;
	
}
		
node *addatbeg(node *start, int num)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->next=NULL;
	ptr->data=num;
	
	ptr->next=start;
	start=ptr;
	return start;
	
}


node *addatend(node *start, int num)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->next=NULL;
	ptr->data=num;
	
	if(start==NULL)
		{
		ptr->next=start;
		start=ptr;
		return start;
	}
	
	node *temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=ptr;
	
	return start;
	
}

node* addafter(node *start, int num, int item)
{
		node *p, *temp;
		p=start;
		while(p!=NULL) 
		{
			if(p->data==item) 
			{
				temp = (node *)malloc(sizeof( node));
				temp->data=num;
				temp->next=p->next;
				p->next=temp;
				return start;
			}
		p=p->next;
		}
		printf("%d is not present in the list\n", item);
		return start;
}

node *addbefore(node *start, int x, int item)
{
		node *p, *temp;
	
		if(start == NULL) 
		{
			printf("List is empty.\n");
			return start;
		}
		
		if(start->data==item) 
		{
			temp = (node *)malloc(sizeof(node));
			temp->data=x;
			temp->next=start;
			start=temp;
			return start;
		}
		
		p=start;
		
		while(p->next!=NULL) 
		{
			if(p->next->data==item) 
			{
				temp = (node *)malloc(sizeof( node));
				temp->data=x;
				temp->next=p->next;
				p->next=temp;
				return start;
		}
		p=p->next;
		}
		printf("%d is not present in the list\n", item);
		return start;
}

node *addatpos(node *start, int x, int pos)
{
	node *p,*temp;
		int i;
		temp = (node *)malloc(sizeof(node));
		temp->data=x;
		if(pos==1) 
		{
			temp->next=start;
			start=temp;
			return start;
		}
		p=start;
		for(i=2;i<=pos-1;i++) 
			p=p->next;
			
		if(p==NULL) 
			printf("There are less than %d elements.\n", pos);
			
		else 
		{
		temp->next=p->next;
		p->next=temp;
		 }
		return start;
}
		
void display(node *start)
{
	printf("\n\n");
	if(start!=NULL)
	{
		node *ptr=start;
		printf("The list is:\n");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("\n\n");
	}
	
	else
	printf("The list is empty\n");
	printf("\n\n");
}

void search(node *start, int x)
{
	if(start==NULL)
		printf("List is empty\n");
	
	else
	{
		
	node *ptr=start;
	int c=1;
	
	while(ptr->data!=x && ptr!=NULL)
	{
		c++;
		ptr=ptr->next;
	}
	
	if(ptr!=NULL)
		printf("Element is present at position %d\n",c);
		
	else
		printf("Element doesnt exist\n");
	}
	
	printf("\n\n");
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
	
node *delete(node *start)
{	
	int n;

	
	if(start!=NULL)
	{	
		printf("Enter element to be deleted\n");
		scanf("%d",&n);
		node *ptr=start;
		if(start->data==n)
			{
				printf("%d was deleted\n",n);
				free(ptr);
				start=NULL;
				return(start);
			}
		node *temp;
		while(ptr->next->data!=n && ptr!=NULL)
		{
			ptr=ptr->next;
		}
		if(ptr!=NULL)
		{
			temp=ptr->next;
			ptr->next=temp->next;
			printf("%d was deleted\n",temp->data);
			free(temp);
			return start;
		}
		else
		{
			printf("The element doesnt exist\n");
			return start;
		}
	}
	
	else
	{
		printf("The list is empty\n");
		return start;
	}
	
	printf("\n\n");
}

node *reverse(node *start)
{
	
	if(start!=NULL) 
	{
		if(start->next==NULL)
			{
			printf("The list has been reversed\n");
			return start;
		}
		
		else
		{
			node *p,*temp,*ptr=NULL;
			temp=start;
			while(temp!=NULL)
			{
				p=temp->next;
				temp->next=ptr;
				ptr=temp;
				temp=p;
			}
			start=ptr;
			printf("The list is reversed\n");
			printf("\n\n");
			return start;
		}
	}
	else
		{
		printf("List is empty\n");
		return start;
	}
	
	printf("\n\n");
}
			
	
