#include<stdio.h>
struct complex
	{
		int r,c;
	}; 
	typedef struct complex op;

int main()
{
	op a,b;
	void display(op,op);
	void operation(op,op);
	
	
	printf("Enter 2 complex numbers\n");
	

		printf("Enter real part of the first number:");
		scanf("%d",&a.r);
		printf("Enter imaginary part:");
		scanf("%d",&a.c);
		
		printf("\nEnter real part of the second number:");
		scanf("%d",&b.r);
		printf("Enter imaginary part:");
		scanf("%d",&b.c);
	
	printf("The two complex numbers that are entered are\n");
	display(a,b);
	operation(a,b);
	
}

	void display(op a,op b)
	{
		printf("%d + i%d",a.r,a.c);
		printf("\n%d + i%d\n",b.r,b.c);
	}
	
	
	void operation(op a,op b)
	{
		printf("The sum of the two numbers is:\n");
		printf("%d + i%d\n",a.r+b.r,a.c+b.c);
		
		printf("The difference of the two numbers is:\n");
		printf("%d + i(%d)\n",a.r-b.r,a.c-b.c);
	}
		
		
	
