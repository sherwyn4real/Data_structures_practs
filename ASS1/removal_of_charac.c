#include<stdio.h>
#include<ctype.h>
int main()
{
	char a[100],b[100];
	int i,j;
	printf("Enter a string of characters\n");
	scanf("%[^\n]s",a);
	
	
	i=0,j=0;
	while(a[i]!='\0')
	{
				if(isalpha(a[i]))
					b[j++]=a[i];
		i++;
	}
	
	b[j]='\0';
			
	printf("The final result:\n");
	puts(b);
}
