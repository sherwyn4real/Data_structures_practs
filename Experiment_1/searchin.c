#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x,n,i,a[100],p;
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

	printf("\nEnter an element you want to search in the array\n");
	scanf("%d",&x);
	
	for(i=0;i<n;i++)
		if(a[i]==x)
			{
				p=i+1;
			break;
		}
		
		
	if(i>=n)
		printf("Element not in the list\n");
		
	else
		printf("Element is at position %d\n",p);
	}
	
