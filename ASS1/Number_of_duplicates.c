#include<stdio.h>
int main()
{
	int i,c=0,n,j;
	printf("Enter number of elements in the array\n");
	scanf("%d",&n);
	
	int a[n];
	
	for(i=0;i<n;i++)
		{
			printf("Enter element at position %d: ",i+1);
			scanf("%d",&a[i]);
			
			for(j=0;j<i;j++)
				if(a[j]==a[i])
					{
					c++;
					break;
				}
			
		}
		
		printf("Elements are as follows:\n");
	
	for(i=0;i<n;i++)
			printf("%d ",a[i]);
		
	printf("\nThere are %d duplicates\n",c);
}
		 
			
		
