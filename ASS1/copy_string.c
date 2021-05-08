#include<stdio.h>
int main()
{
	char a[100],b[100];
	int i=0,j=0;
	printf("Enter a string of characters\n");
	scanf("%[^\n]s",a);

	while((getchar())!='\n');
	
	while(a[i]!='\0')
	b[j++]=a[i++];
	
	b[j]='\0';
	
	printf("The copied string:\n");
	puts(b);
}
