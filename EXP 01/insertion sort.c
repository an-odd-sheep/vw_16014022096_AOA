#include <stdio.h>
#include <stdlib.h>
int count_i = 0;

void insertionSort(int A[], int n) {
    int i, j, key;
     
    for (j = 1; j < n; j++) {
        count_i++;
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
            
        }
        A[i + 1] = key;
    }
    
}

int main() {
      int  n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
   
    printf("Count : %d \n", count_i);

    return 0;
}

    