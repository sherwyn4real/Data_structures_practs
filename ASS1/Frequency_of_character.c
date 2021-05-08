#include<stdio.h>

int main()
{
	char x, *a;
	int count=0;
	
	printf("Enter a string of characters\n");
	scanf("%[^\n]s",a);

	
	while((getchar())!='\n');
	printf("Enter the character whose frequency is to be found in the entered string\n");
	scanf("%c",&x);
	
	for(int i=0;a[i]!='\0';i++)
		if(a[i]==x)
			count++;
	
	printf("The character appears %d times in the string\n",count);
	
	
	
	}
