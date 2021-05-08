#include<stdio.h>
#include<ctype.h>
int main()
{
	char a[100],b[100];
	int i,j;
	printf("Enter a string of characters\n");
	scanf("%[^\n]s",a);
	i=0;
	while(a[i]!='\0')
	i++;
	
	j=0;
	i=i-1;
	while(i>=0)
	b[j++]=a[i--];
	
	b[j]='\0';
	printf("The revrsal is:\n");
	puts(b);
}
