#include<stdio.h>
#include<stdlib.h>

struct subject
{
	int sub[6];
};
	typedef struct subject s;

struct student
	{	
		char name[30];
		char class[30];
		int roll;
		int sem;
		s a;
	};
	typedef struct student st;
	
int main()
{
	void total(st *);
	void input(st *);
	
	int i=0;
	
	st *arr=(st *)malloc(1*sizeof(st));
	
	input(&arr[i]);
		
	total(&arr[i]);
		
	}
	
void input(st* arr)
{	
	int i=0;
	printf("Enter name:");
	gets(arr->name);
	
	printf("\nEnter ID:");
	scanf("%d",&arr->roll);
	
	while((getchar()!='\n'));
	
	printf("\nEnter class:");
		gets(arr->class);
	
	printf("\nEnter Semester:");
	scanf("%d",&arr->sem);
	
	printf("Enter marks(out of 100) obtained in the following subjects of the Semester\n");
	
	printf("English:\n");
	scanf("%d",&arr->a.sub[i]);
	i++;
	
	printf("French:\n");
	scanf("%d",&arr->a.sub[i]);
	i++;
	
	printf("Maths:\n");
	scanf("%d",&arr->a.sub[i]);
	i++;
	
	printf("Computer Science:\n");
	scanf("%d",&arr->a.sub[i]);
	i++;
	
	printf("Geography:\n");
	scanf("%d",&arr->a.sub[i]);
	i++;
	
	printf("History:\n");
	scanf("%d",&arr->a.sub[i]);
}
	
	
void total(st *arr)
{
	int i,sum=0;
	float p;
		
		for(i=0;i<6;i++)
			sum+=arr->a.sub[i];
			
		p=sum/6.0;
		
		printf("Your total is %d\n",sum);
		if(p>=75)
		printf("You have achieved class Distinction!\n");
		
		else if(p>=60)
		printf("You have achieved First Class\n");
		
		else if(p>=55)
		printf("You have passed with Second Class\n");
		
		else
		printf("You have achieved Pass Class\n");
		
			
		printf("\n\n");
	
	
}
