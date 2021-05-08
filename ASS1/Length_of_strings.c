#include<stdio.h>
int main()
{
	char a[200];
	int c=0;
	printf("Enter a string of characters\n");
	scanf("%[^\n]s",a);
	
	for(int i=0;a[i]!='\0';i++)
		c++;
		
	printf("The length of the string is %d\n",c);
}
