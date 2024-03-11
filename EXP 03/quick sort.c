#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int left, int right, int *iterations) {
    int pivot = A[left];
    int lo = left + 1;
    int hi = right;

    while (lo <= hi) {
        while (A[hi] > pivot)
            hi--;
        while (lo <= hi && A[lo] <= pivot)
            lo++;
        if (lo <= hi) {
            swap(&A[lo], &A[hi]);
            (*iterations)++;
        }
    }

    swap(&A[left], &A[hi]);
    return hi;
}

void quicksort(int A[], int left, int right, int *iterations) {
    if (left < right) {
        int q = partition(A, left, right, iterations);
        quicksort(A, left, q - 1, iterations);
        quicksort(A, q + 1, right, iterations);
    }
}

int main() {
    int n = 10; 
    int arr[n]; 
    clock_t t1, t2;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
        printf("%d ", arr[i]);
    }
    printf("\n");

    t1 = clock();
    int iterations = 0; 
    quicksort(arr, 0, n - 1, &iterations);
    t2 = clock();


    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Number of iterations: %d\n", iterations);

    double t = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
    printf("TIME : %f \n", t);
    return 0;
}
