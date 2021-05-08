#include<stdio.h>
#include<ctype.h>
int main()
{
	char a[200];
	int c,v,w,d;
	c=v=w=d=0;
	printf("Enter a string of characters\n");
	scanf("%[^\n]s",a);
	
	
	
	for(int i=0;a[i]!='\0';i++)
		{
			if(isalpha(a[i]))
			{
				a[i]=tolower(a[i]);
				if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u') 
					v++;
				else
					c++;
				}
				
			else if(isdigit(a[i]))
				d++;
				
			else
				if(a[i]==' ' || a[i]=='\t' )
					w++;
		}
	printf("The number of vowels are %d\n",v);
	printf("The number of consonants are %d\n",c);
	printf("The number of digits are %d\n",d);
	printf("The number of whitespace characters are %d\n",w);
	
	}
		
		
