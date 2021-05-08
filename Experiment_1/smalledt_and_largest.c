#include<stdio.h>
int main()
{
	int n,i,a[100],large,small;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++)
	{
	printf("Enter element at position %d:\n",i+1);
	scanf("%d",&a[i]);
	}
	
	printf("The elements are:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	large=small=a[0];
	
	for(i=1;i<n;i++)
		{
		if(large<a[i])
			large=a[i];
			
		if(small>a[i])
			small=a[i];
			
		}
		
		printf("\nThe largest element is %d and the smallest element is %d\n",large,small);
		
	}
	
	
