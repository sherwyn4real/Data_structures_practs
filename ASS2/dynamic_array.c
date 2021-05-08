#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,n,i,small;
	printf("Enter number of elements in the array:");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter element at location %d:",i+1);
		scanf("%d",&a[i]);
	}
	
	small=a[0];
	for(i=1;i<n;i++)
		if(small>a[i])
			small=a[i];
			
	printf("The smallest element is %d\n",small);
	
}
