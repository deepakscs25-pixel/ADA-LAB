#include <stdio.h>

int n;

void main(){
    int a[100];
    printf("Enter no of elements:");
    scanf("%d",&n);

    printf("Enter the Array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    heapsort(a,n);
    printf("sorted array:");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
}

void heapsort(int a[], int n) {
    int i, temp;
    
    heap_cons(a, n);
    
    for (i = n - 1; i > 0; i--) {
       
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        
       
        heap_add(a, i - 1); 
    }
}

void heap_cons(int a[], int n) {
    int i, j, k, item;
    
    for (k = 1; k < n; k++) {
        item = a[k];
        i = k;
        j = (i - 1) / 2;
        
        while (i > 0 && item > a[j]) {
            a[i] = a[j];
            i = j;
            j = (i - 1) / 2;
        }
        a[i] = item;
    }
}

void heap_add(int a[], int n) {
    int i, j, item;
    
    j = 0;
    item = a[j];
    i = 2 * j + 1;
    
    while (i <= n) {
        if (i + 1 <= n) {
            if (a[i] < a[i + 1]) {
                i++;
            }
        }
        
        if (item < a[i]) {
            a[j] = a[i];
            j = i;
            i = 2 * j + 1;
        } else {
            break;
        }
    }
    a[j] = item;
}