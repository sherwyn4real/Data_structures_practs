#include<stdio.h>
int main()
{
	int i,j,a[50][50],b[50][50],r,c,c2,sum[50][50],k;
	printf("Enter number of rows of first matrix\n");
	scanf("%d",&r);
	 
	printf("Enter number of columns\n");
	 scanf("%d",&c);
	 
	printf("Enter number of columns in the second matrix\n");
	scanf("%d",&c2);
	
	printf("Enter elements in the first matrix\n");
	 
	 
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			printf("Enter element at position %d %d\n",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	
		
	printf("\nEnter elements in the second matrix\n");
	 
	for(i=0;i<c;i++)
		for(j=0;j<c2;j++)
		{
			printf("Enter element at position %d,%d\n",i+1,j+1);
			scanf("%d",&b[i][j]);
		}
		
		
	printf("The two matrices are:\n");
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		printf("%d ",a[i][j]);
		
		printf("\n");
		}
		
	printf("\n");
	
	for(i=0;i<c;i++)
	{
		for(j=0;j<c2;j++)
		printf("%d ",b[i][j]);
		
		printf("\n");
		}
		
	for(i=0;i<r;i++)
		for(j=0;j<c2;j++)
		{
			sum[i][j]=0;
			for(k=0;k<c;k++)
			sum[i][j]+=a[i][k]*b[k][j];
		}
		
	printf("\n");
	printf("The product of the matrices is\n");
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c2;j++)
		printf("%d	",sum[i][j]);
		
		printf("\n");
		}
	}
		
