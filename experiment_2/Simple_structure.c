#include<stdio.h>
#include<stdlib.h>

struct employee
	{
		char name[30];
		char q[40];
		int salary;
		int age;
		
	};
	typedef struct employee e;




int main()
{
	
	void input(e *);
	void average(e *,int);
	void display(e *);
	
	int n, i=0;
	printf("How many entries do you need?\n");
	scanf("%d",&n);
	
	e *a=(e *)malloc(n*sizeof(e));
	
	for(i=0;i<n;i++)
		input(&a[i]);
		
	printf("The entries are as follows\n\n");
	
	for(i=0;i<n;i++)
		display(&a[i]);
		
	average(a,n);
		

	
}

void input(e *a)
{
	printf("Enter name:");
	scanf("%s",a->name);
	
	while((getchar()!='\n'));
	
	printf("\nEnter Qualification:");
	gets(a->q);
	
	printf("\nEnter age:");
	scanf("%d",&a->age);
	
	printf("\nEnter salary:");
	scanf("%d",&a->salary);
	
	printf("\n\n");
}
	
void display(e *a)
{
	
		printf("Name:%s\n",a->name);
		printf("Qualification:%s\n",a->q);
		printf("Age:%d\n",a->age);
		printf("Salary:%d\n",a->salary);
		printf("\n\n");
	}
		
void average(e *a,int n)
{
	int sum=0,i;
	
	for(i=0;i<n;i++)
		sum+=a[i].salary;
		
	printf("The average salary of these employees is %f\n",(float)sum/n);

}
