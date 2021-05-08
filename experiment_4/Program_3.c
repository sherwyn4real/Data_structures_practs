#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define TAB '\t'
#define SPACE ' '
struct element
{
	float data;
	struct element *next;
}; typedef struct element node;

node *top=NULL;

int p=-1;
char infix[30];
char postfix[30];
void push(float x);
int instack_prio(char);
int incoming_prio(char);
float pop();
int isempty();

void evaluate();
void display_stack();


int main()
{
	char x,z; int i; 
	printf("Enter your infix expression\n");
	gets(infix);
	
	
	for(i=0;i<strlen(infix);i++)
		{
			x=infix[i];
			
			if(x==SPACE || x==TAB)
				continue;
				
			switch(x)
			{
				case '(': push(x);
							break;
							
				case  '+':
				
				case  '-':
				
				case  '/':
				
				case  '*':
				
				case  '^': while(!isempty() && incoming_prio(x)<=instack_prio(top->data))
								{
									z=pop();
								postfix[++p]=z;
								
							}
							push(x);
							//display_stack();
							break;
				
				case ')': while( (z=pop())!='(')
								postfix[++p]=z;
							break;
				
				default: postfix[++p]=x;  
			}
		}
		while(!isempty())
				postfix[++p]=pop();
			
				
	printf("The postfix equivalent is:");		
	puts(postfix);

	evaluate();
			
}



int incoming_prio(char x)
{
	switch(x)
	{
		case '+':
		
		case '-': return 1;
		
		case '*':
		
		case '%':
		
		case '/':return 2;
		
		case '^':return 4;
		
		default: return -1;
	}
}

int instack_prio(char x)
{
	switch(x)
	{
		case '+':
		
		case '-': return 1;
		
		case '*':
		
		case '%':
		
		case '/':return 2;
		
		case '^':return 3;
		
		default: return -1;
	}
}

void push(float x)
{
	
	node *temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	temp->data=x;
	
	
	if(top==NULL)
		top=temp;
		
	else
	{
		temp->next=top;
		top=temp;
	}
}


float pop()
{
	node *temp=top; float x;
	top=top->next;
	x=temp->data; 
	free(temp);
	return x;
}

int isempty()
{
	if(top==NULL)
		return 1;
		
	else
		return 0;
	}


void evaluate()
{
	float a,b,temp;
	float val;
	
	for(int i=0;i<=p;i++)
	{
		
		if(postfix[i]>='0' && postfix[i]<='9')
				push(postfix[i]-'0');
				
		
		else
			{
			a=pop();
			b=pop();
			
			
			switch(postfix[i])
			{
				case '+': temp=b+a;
						break;
				
				case '-':temp=b-a;
							break;
							
				case '*':temp=b*a;
						 break;			
				
				case '/':temp=b/a;
							break;
							
				case '%':temp=(int)b%(int)a;
							break;
							
				case '^':temp=pow(b,a);
							break;
			}
			push((float)temp);
			
		}
		//display_stack();
		//printf("\n");
		
	}
	val=pop();
	
	printf("The value of this expression is %f",val);
	
	printf("\n\n");

}

void display_stack()
{
	node *ptr=top;
	
	while(ptr!=NULL)
	{
		printf("%f",ptr->data);
		ptr=ptr->next;
	}
}
		
	
