#include<stdio.h>
#include<stdlib.h>

struct student
	{
		int id;
		int age;
		float percent;
	};
	typedef struct student s;

int main()
{
	void smallest(s *,int);
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
	
	printf("Displaying the details of student(s) having lowest percentage...\n\n");
		smallest(a,n);
		
	}
	
void input(s *a)
{
	
	
	printf("\nEnter Student ID:");
	scanf("%d",&a->id);
	
	printf("\nEnter age:");
	scanf("%d",&a->age);
	
	printf("\nEnter Percentage:");
		scanf("%f",&a->percent);
	
	printf("\n\n");
}

void display(s *a)
{
		printf("ID:%d\n",a->id);
		printf("Age:%d\n",a->age);
		printf("Percentage:%f\n",a->percent);
		printf("\n");
	}
	
void smallest(s* a,int n)
{
	int i;
	float small=a[0].percent;
	
	
	for(i=1;i<n;i++)
		if(small>a[i].percent)
				small=a[i].percent;
				
	for(i=0;i<n;i++)
		if(a[i].percent==small)
			display(&a[i]);
			
		}
