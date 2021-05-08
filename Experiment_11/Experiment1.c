
#include <stdio.h> 
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 1; i < n; i++)        
	for (j = 0; j < n-i; j++)  
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
} 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
    printf("%d ", arr[i]); 
    printf("\n"); 
} 

void selectionSort(int a[], int n) 
{ 
    int i, j,pos;
    
   for(i=1;i<n;i++)
    {
		pos=i;
		for(j=i+1;j<n;j++)
			if(a[pos]>a[j])
				pos=j;
		if(a[pos]<a[i-1])
			swap(&a[pos],&a[i-1]);
	}
    
    
} 
 
void insertionSort(int ar[], int mn) 
{ 
    int i, key, j; 
    for (i = 1; i < mn; i++) 
	{ 
        key = ar[i]; 
        j = i - 1; 
        while (j >= 0 && ar[j] > key) 
		{ 
            ar[j + 1] = ar[j]; 
            j = j - 1; 
        } 
        ar[j + 1] = key; 
    } 
} 
  

int main() 
{ 
    int arr[] = {40, 35, 105, 20, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    printf("BUBBLE SORT: \n"); 
    printArray(arr, n); 
    printf("--------------------------- \n"); 
    int aa[] = {66, 59, 22, 0, 12}; 
    int nn = sizeof(aa)/sizeof(aa[0]); 
    selectionSort(aa, nn); 
    printf("SELECTION SORT: \n"); 
    printArray(aa, nn); 
	printf("--------------------------- \n"); 
	printf("INSERTION SORT: \n"); 
    int ar[] = { 69, 30, 100, 22, 15 }; 
    int mn = sizeof(ar) / sizeof(ar[0]); 
    insertionSort(ar, mn); 
    printArray(ar, mn);  
    return 0; 
} 
