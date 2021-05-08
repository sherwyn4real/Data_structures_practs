#include <stdio.h>  
int largest(int a[]);  
void radix_sort(int a[]);  

void print(int a[], int n)
{
	 for(int i=0;i<10;i++)  
        printf(" %d ", a[i]); 
	}
	
int main()  
{  
     
    int a[10]={99,32,105,54,33,23,69,89,44,32};       
    printf("The array before sorting: \n");
    print(a,10);
    radix_sort(a); 
    printf("\n\nThe sorted array is: \n");  
	print(a,10);
	printf("\n\n");
}  
  
int largest(int a[])  
{     
    int larger=a[0], i;   
    for(i=1;i<10;i++)  
    {  
        if(a[i]>larger)  
        larger = a[i];  
    }  
    return larger;  
}  
void radix_sort(int a[])  
{  
    int bucket[10][10], bucket_count[10];  
    int i, j, k, remainder, NOP=0, divisor=1, larger, pass;  
    larger = largest(a);  
    while(larger>0)  
    {  
        NOP++;  
        larger/=10;  
    }  
    for(pass=0;pass<NOP;pass++) // Initialize the buckets  
    {  
        for(i=0;i<10;i++)  
        bucket_count[i]=0;  
        for(i=0;i<10;i++)  
        {  
            // sort the numbers according to the digit at passth place            
            remainder = (a[i]/divisor)%10;  
            bucket[remainder][bucket_count[remainder]] = a[i];  
            bucket_count[remainder] += 1;  
        }  
        // collect the numbers after PASS pass  
        i=0;  
        for(k=0;k<10;k++)  
        {  
            for(j=0;j<bucket_count[k];j++)  
            {  
                a[i] = bucket[k][j];  
                i++;  
            }  
        }  
        divisor *= 10;  
      
}  
}  
