#include <stdio.h>
#include <time.h>

int partition(int a[],int low,int high){
    int i,j,temp,pivot;
    pivot=a[low];
    i=low+1;
    j=high;

    while(i<=j){
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }

        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

    temp=a[low];
    a[low]=a[j];
    a[j]=temp;

    return j;
}

void quick_sort(int a[],int low,int high){
    if(low<high){
        int p=partition(a,low,high);
        quick_sort(a,low,p-1);
        quick_sort(a,p+1,high);
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\nOriginal array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    clock_t start = clock();

    quick_sort(a, 0, n - 1);

    
    clock_t end = clock();

    printf("\n\nSorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nExecution Time: %f seconds\n", time_taken);

    return 0;
}
