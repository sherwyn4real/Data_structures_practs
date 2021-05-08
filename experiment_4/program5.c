#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SPACE ' '
#define TAB '\t'
struct element
{
	char data;
	struct element *next;
};
typedef struct element  node;

node *top=NULL;
void push(char);
char pop();
int compare(char);

int main()
{
	int i;
	char a[30];
	start:
	printf("Enter your parentheses\n");
	gets(a);
	
	for(i=0;i<strlen(a);i++)
	{	 char c=a[i];
		if(c!=SPACE && c!=TAB)
		{
			switch(c)
			{
				
			case '(':
			
			case '[':
			
			case '{': push(c);
						break;
						
			case ')':
			
			case ']':
			
			case '}':if(!compare(c))
						{
						printf("Parentheses are not balanced\n");
						printf("\n\n\n");		
						exit(1);
					}
					break;
					
			default:printf("Please enter only brackets\n");
					goto start;
				}
			}      //[()]{}{[()()]()}
		}
	
			
	if(top!=NULL)
		printf("Parentheses are not balanced\n");
		
	else
		printf("Parentheses are balanced\n");

	printf("\n\n\n");			
}

int compare(char x)
{
	switch(x)
	{
		case ')':if(pop()!='(')
					return 0;
				break;

		case ']':if(pop()!='[')
					return 0;
				break;
					
		case '}':if(pop()!='{')
					return 0;
				break;
		
		default: return -1;
	}
	
	return 1;
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
	if(top==NULL)
		{
			printf("Parentheses are unbalanced\n");
			printf("\n\n\n");
			exit(1);
		}
		
	else
	{
		char x;
		node *temp=top;
		top=top->next;
		x=temp->data;
		free(temp);
		return x;
	}
}
