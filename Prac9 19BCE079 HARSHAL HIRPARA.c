/*

a) Write a program to implement Quick sort for sorting
a given set of integers in ascending order.
b) Write a program to implement Heap sort algorithm
for sorting a given set of integers in ascending
order.
c) Write a program to implement merge sort for
sorting a given set of integers in ascending order.

*/

/*
    Implementation of the Quick Sort Algorithm
*/

#include<stdio.h> 
  
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int size;
    printf("Enter size of quick sort array\n");
    scanf("%d",&size);
    int v[size];
    int size_2= sizeof(v) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d of quick sort array:\n",i+1);
        scanf("%d",&v[i]);  
    }
 
    quickSort(v, 0, size-1); 
    printf("Sorted array: \n"); 
    printArray(v, size); 
    return 0; 
} 

/*
Enter size of quick sort array
7
Enter element 1 of quick sort array:
4
Enter element 2 of quick sort array:
6
Enter element 3 of quick sort array:
3
Enter element 4 of quick sort array:
8
Enter element 5 of quick sort array:
9
Enter element 6 of quick sort array:
23
Enter element 7 of quick sort array:
54
Sorted array:
3 4 6 8 9 23 54
*/

/*
    Implementation of the Heap Sort Algorithm
*/

#include <stdio.h>


// rebuild recursive
void rebuild(int v[], int limit, int pos)
{       
    int c1, c2;
    
    c1 = 2 * pos;
    c2 = c1 + 1;
    
    if(c1 > limit || (v[pos - 1] >= v[c1 - 1] && v[pos - 1] >= v[c2 - 1]))
        return;
    
    int greater_index = -1;
    
    if(c2 > limit)
        greater_index = c1;
    else
    {       
        if(v[c1 - 1] > v[c2 - 1])
            greater_index = c1;
        else
            greater_index = c2;
    }
    
    if(greater_index != -1)
    {
        int aux = v[greater_index - 1];
        v[greater_index - 1] = v[pos - 1];
        v[pos - 1] = aux;
        rebuild(v, limit, greater_index);
    }
}


void build(int v[], int size_v)
{
    int left;
    
    if(size_v % 2 == 0)
        left = size_v / 2 + 1;
    else
        left = (size_v - 1) / 2 + 1;
    
    while(left > 1)
    {
        left--;
        rebuild(v, size_v, left);
    }
}

void heap_sort(int v[], int size_v)
{
    // builds the heap
    build(v, size_v);

    /*
        change the item of the position 1 with the item of the position "n", 
        after with "n - 1", "n - 2" until there only 1 item.
    */
    int limit = size_v;
    
    while(1)
    {       
        int aux = v[0];
        v[0] = v[limit - 1];
        v[limit - 1] = aux;
        
        rebuild(v, limit - 1, 1);
            
        limit--;
        
        if(limit <= 2 && v[0] <= v[1])
            break;
    }
}

int main()
{
    int size;
    printf("Enter size of heap array\n");
    scanf("%d",&size);
    int v[size];
    int size_2= sizeof(v) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d of heap array:\n",i+1);
        scanf("%d",&v[i]);  
    }

    heap_sort(v, size_2);

    for(int i = 0; i < size; i++)
        printf("%d ", v[i]); 
    
    return 0;
}
/*
Enter size of heap array
9
Enter element 1 of heap array:
5
Enter element 2 of heap array:
8
Enter element 3 of heap array:
3
Enter element 4 of heap array:
5
Enter element 5 of heap array:
2
Enter element 6 of heap array:
1
Enter element 7 of heap array:
4
Enter element 8 of heap array:
9
Enter element 9 of heap array:
7
1 2 3 4 5 5 7 8 9
*/

/* Merge sort in C */
#include<stdio.h>
#include<stdlib.h>

//mergeing arrayss
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
    int i=0,j=0,k=0;

    while(i<leftCount && j< rightCount) {
        if(L[i]  < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i < leftCount) A[k++] = L[i++];
    while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void MergeSort(int *A,int n) {
    int mid,i, *L, *R;
    if(n < 2) return;

    mid = n/2;  // find the mid index. 

    // create left and right subarrays
    
    L = (int*)malloc(mid*sizeof(int)); 
    R = (int*)malloc((n- mid)*sizeof(int)); 
    
    for(i = 0;i<mid;i++) L[i] = A[i]; 
    for(i = mid;i<n;i++) R[i-mid] = A[i]; 

    //sorting
    MergeSort(L,mid);  
    MergeSort(R,n-mid);  
    Merge(A,L,mid,R,n-mid);  
}

int main() {    
     // creating an array of integers. 
    
    int size;
    printf("Enter size of merge sort array\n");
    scanf("%d",&size);
    int v[size];
    int size_2= sizeof(v) / sizeof(int); 
    // finding number of elements in array as size of complete array in bytes divided by size of integer in bytes. 
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d of merge sort array:\n",i+1);
        scanf("%d",&v[i]);  
    }
 

    // Calling merge sort to sort the array. 
    MergeSort(v,size_2);

    //printing all elements in the array once its sorted.
    for(int i = 0;i < size_2;i++) 
        printf("%d ",v[i]);
    return 0;
}

/*
Enter size of merge sort array
5
Enter element 1 of merge sort array:
8
Enter element 2 of merge sort array:
6
Enter element 3 of merge sort array:
5
Enter element 4 of merge sort array:
8
Enter element 5 of merge sort array:
7
5 6 7 8 8
*/