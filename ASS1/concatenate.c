#include<stdio.h>
int main()
{
	char a[400],b[200];
	int i=0,j=0;
	printf("Enter a string of characters in the first character array\n");
	scanf("%[^\n]s",a);

	while((getchar())!='\n');
	
	printf("Enter a string of characters in the second character array\n");
	scanf("%[^\n]s",b);
	
	while(a[i]!='\0')
	i++;
	
	while(b[j]!='\0')
	a[i++]=b[j++];
	
	a[i]='\0';
	
	printf("The final result is: %s\n",a);
	
}
