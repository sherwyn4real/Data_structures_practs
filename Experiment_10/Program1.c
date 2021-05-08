#include <stdio.h> 
int linearsearch(int ar[], int l, int m) 
{ 
    int i; 
    for (i = 0; i < l; i++) 
        if (ar[i] == m) 
            return i; 
    return -1; 
} 
int binarySearch(int ar[], int l, int r, int m) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (ar[mid] == m) 
            return mid; 
  
           if (ar[mid] > m) 
            return binarySearch(ar, l, mid - 1, m); 
  
        return binarySearch(ar, mid + 1, r, m); 
    } 
    return -1; 
} 
int main() 
{ 
    int l;
    printf("Enter the size of the array\n");
    scanf("%d",&l);
    int a[l],i,m,result;
    printf("Enter the elements\n");
    for(i=0;i<l;i++)
    scanf("%d",&a[i]);
    printf("Enter the number you want to locate using linear search\n");
    scanf("%d",&m);
    result = linearsearch(a, l, m); 
    (result == -1)? printf("Element is not present in array") : printf("Element is present at array index %d", result); 
    
    printf("\nEnter the number you want to locate using binary search\n");
    scanf("%d",&m);
    result = binarySearch(a, 0, l - 1, m); 
    (result == -1) ? printf("Element is not present in array") 
                   : printf("Element is present at array index %d",result); 
    return 0; 
}

