#include <stdio.h>  
  
/* Function to merge the subarrays of a[] */  
// Merges two subarrays of a[].
// First subarray is a[big....mid]
// Second subarray is arr[mid+1..end]

void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; //create temporary arrays  
      
    /* copy data to temp arrays */ 
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    

      /* Merge the temp arrays back into arr[l..r]*/

    i = 0; /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = beg;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }  
/* Copy the remaining elements of L[], if there
    are any */  
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
     /* Copy the remaining elements of R[], if there
    are any */ 
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    

 /* beg is for left index and end is right index of the
sub-array of arr to be sorted */ 

void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  //Find the middle point to divide the array into two                   				//halves:
        mergeSort(a, beg, mid);  //Call mergeSort for first half: 
        mergeSort(a, mid + 1, end);  //Call mergeSort for second half:
        merge(a, beg, mid, end);  //Merge the two halves sorted in step 2 and 3:
    }  
}  
  
/* Function to print the array */  
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
  
int main()  
{  
    int a[] = { 12, 31, 25, 8, 32, 17, 40, 42 };  

    int n = sizeof(a) / sizeof(a[0]);  // To find out length of array here n=8.
    printf("Before sorting array elements are - \n");  
    printArray(a, n);  
    mergeSort(a, 0, n - 1);  
    printf("After sorting array elements are - \n");  
    printArray(a, n);  
    return 0;  
}  
