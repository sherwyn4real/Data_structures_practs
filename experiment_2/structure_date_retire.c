#include<stdio.h>
#include<stdlib.h>

struct date
{
	int d,m,y;
};
	typedef struct date dof;
	
struct employee
	{
		int id;
		dof b,j;
		};
	typedef struct employee e;

int main()
{
	void retire(e *);
	void input(e *);
	
	
	e *a=(e *)malloc(1*sizeof(e));
	
	input(a);
	
	retire(a);
	
}

void input(e *a)
{
	printf("\nEnter Employee ID:");
	scanf("%d",&a->id);
	
	printf("\nEnter date of birth DD-MM-YYY:");
	scanf("%d %d %d",&a->b.d,&a->b.m,&a->b.y);
	
	printf("\nEnter date of joining DD-MM-YYY:");
	scanf("%d %d %d",&a->j.d,&a->j.m,&a->j.y);
	
}


void retire(e *a)
{
	 int years,day,month,years_left,months_left,days_left;
	
	years=a->j.y-a->b.y;
	month=a->j.m-a->b.m;
	day=a->j.d-a->b.d;
	
	if(month<0)
	  month=month*-1;
	
	if(day<0)
		day*=-1;
		
	 if(a->j.m<a->b.m)
	{	years-=1;
		month=12-month;
	}

	if(a->j.d<a->b.d)
		{
			month-=1;
			day=31-day;
		}
		

	years_left=60-years;
	months_left=month;
	days_left=day;
	
	
	
	if(month!=0 || day!=0)
		years_left-=1;
	
	
	if(month!=0)
		months_left=12-month;
		
	
	if(day<0)
		day=-1*day;
		
	
	if(day!=0)
		{
			months_left-=1;
			days_left=31-day;
		}
	
	if(days_left<0)
		days_left=days_left*-1;
		
	
	
	if(months_left<0)
		months_left=months_left*-1;
		
		
	printf("You will retire in exactly %d years, %d  month(s) and %d day(s)\n\n",years_left,months_left,days_left);	

}
	
