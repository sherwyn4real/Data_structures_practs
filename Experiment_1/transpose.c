#include<stdio.h>
int main()
{
	int i,j,r,c;
	printf("Enter number of rows\n");
	scanf("%d",&r);
	 
	printf("Enter number of columns\n");
	 scanf("%d",&c);
	 
	 int a[r][c];
	printf("Enter elements in the matrix\n");
	 
	 
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			printf("Enter element at position %d %d\n",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	
	printf("The original matrix is:\n");
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		printf("%d ",a[i][j]);
		
		printf("\n");
		}
		
	printf("The transpose of the matrix is:\n");
	
	for(j=0;j<c;j++)
	{
		for(i=0;i<r;i++)
		printf("%d ",a[i][j]);
		
		printf("\n");
		}
	}
