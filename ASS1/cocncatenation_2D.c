#include<stdio.h>
int main()
{
	char a[10][10], b[3][10];
	int i=0,k=3,j=0;
	
	printf("Enter strings in the first matrix\n");
	for(i=0;i<3;i++)
			{
			printf("Enter a string\n");
			scanf("%[^\n]s",a[i]);
			while((getchar())!='\n'); 
			}
			
	printf("Enter strings in the second matrix\n");
	
	for(i=0;i<3;i++)
			{
			printf("Enter a string\n");
			scanf("%[^\n]s",b[i]); 
			while((getchar())!='\n');
			}
	
	printf("The first matrix:\n");
	
	for(i=0;i<3;i++)
		puts(a[i]);
		
	printf("The second matrix:\n");
	
	for(i=0;i<3;i++)
		puts(b[i]);
		
	for(i=0;i<3;i++)
		{
		for(j=0;b[i][j]!='\0';j++)
			a[k][j]=b[i][j];
		k++;
	}
		
	
	
	printf("After concatenation, the result is:\n");
	for(i=0;i<6;i++)
		puts(a[i]);
		
		
		
		}
		
