 #include<stdio.h>
int main()
{
	int i,j,a[50][50],b[50][50],r,c,sum[50][50];
	printf("Enter number of rows\n");
	scanf("%d",&r);
	 
	printf("Enter number of columns\n");
	 scanf("%d",&c);
	 
	printf("Enter elements in the first matrix\n");
	 
	 
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			printf("Enter element at position %d %d\n",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	
		
	printf("\nEnter elements in the second matrix");
	 
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
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
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		printf("%d ",b[i][j]);
		
		printf("\n");
		}
	
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			sum[i][j]=a[i][j]+b[i][j];
			
	printf("\nThe sum of the two matrices is\n");
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		printf("%d	",sum[i][j]);
		
		printf("\n");
		}
	printf("\n");
	
	}
	
	
	
