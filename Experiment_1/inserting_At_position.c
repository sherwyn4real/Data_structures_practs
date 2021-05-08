#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x,p,n,i,a[100];
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

	printf("\nEnter an element and its position in the array\n");
	scanf("%d %d",&x,&p);
	
	
	if(p>n+1 || p<0)
	{
		printf("Position is out of bounds\n");
		exit(1);
	}
	
	else
	{
		
	for(i=n;i>=0 && i>=p;i--)
			a[i]=a[i-1];
		
	
	a[p-1]=x;
		
	n=n+1;
	printf("The elements now are:\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
}
		
		
		
		
