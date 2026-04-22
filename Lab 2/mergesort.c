#include <stdio.h>
#include <time.h> 

void merge(int a[],int low,int mid,int high){
    int i,j,k,c[100];
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            c[k++]=a[i++];
        }
        else{
            c[k++]=a[j++];
        }
    }
    while(i<=mid){
        c[k++]=a[i++];
    }
    while(j<=high){
        c[k++]=a[j++];
    }

    for(i=low;i<=high;i++){
        a[i]=c[i];
    }
}

void mergesort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
        }
}

int main(){
    int n;
    printf("Enter the length of array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter the array elements %d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("Elements in the array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    clock_t start = clock();
    mergesort(a,0,n-1); 
    clock_t end = clock();

    printf("\nElements in the sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nExecution Time: %f seconds\n", time_taken);
    
    return 0;
}