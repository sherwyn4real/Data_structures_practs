#include<stdio.h>
#include<stdlib.h>

struct student
	{
		char name[30];
		char branch[30];
		int id;
		int age;
		
	};
	typedef struct student s;

int main()
{
	void greater(s *,int);
	void input(s *);
	void display(s *);
	
	int n, i=0;
	printf("How many entries do you need?\n");
	scanf("%d",&n);
	
	while((getchar()!='\n'));
	
	s *a=(s *)malloc(n*sizeof(s));
	
	for(i=0;i<n;i++)
		input(&a[i]);
		
	printf("The entries of students are as follows\n");
	
	for(i=0;i<n;i++)
		display(&a[i]);
	
	printf("Displaying the details of students who are 20 years old or above...\n\n");
		greater(a,n);
		
	}
	
void input(s *a)
{
	
	printf("Enter name:");
	gets(a->name);
	
	printf("\nEnter ID:");
	scanf("%d",&a->id);
	
	printf("\nEnter age:");
	scanf("%d",&a->age);
	
	while((getchar()!='\n'));
	
	printf("\nEnter branch:");
		gets(a->branch);
	
	printf("\n\n");
}


void display(s *a)
{
		printf("ID:%d\n",a->id);
		printf("Name:%s\n",a->name);
		printf("Age:%d\n",a->age);
		printf("Branch:%s\n",a->branch);
		printf("\n\n");
	}
	
void greater(s *a,int n)
{
	int i,c=0;
	
	
	for(i=0;i<n;i++)
		if(a[i].age>=20)
			{
				display(&a[i]);
				c=1;
			}
			
	if(!c)
	printf("There is no student whose age is greater than or equal to 20\n");
} 
