#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct element
{
	char data;
	struct element*next;
};
typedef struct element node;

node *top=NULL;
void push(char);
char pop();


int main()
{
	char a[30]; 
	int n,i;
	printf("Enter a string to reverse it\n");
	gets(a);
	
	n=strlen(a);
	
	
	for(i=0;i<n;i++)
			push(a[i]);
	
		
	for(i=0;i<n;i++)
		a[i]=pop();
		
	printf("\nThe reversed string is:\n");
	
	puts(a);
	printf("\n\n\n");
}

void push(char x)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	
		temp->next=top;
		top=temp;
}

char pop()
{
	node *temp=top;
	
	char x;
	x=temp->data;
	top=top->next;
	free(temp);
	return x;
}
	
	
	
	
