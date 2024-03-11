#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    int iterations = 0;

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        iterations++; 
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
    return iterations;
}

int mergeSort(int A[], int p, int r) {
    int iterations = 0;
    if (p < r) {
        int q = (p + r) / 2;
        iterations += mergeSort(A, p, q);
        iterations += mergeSort(A, q + 1, r);
        iterations += merge(A, p, q, r);
    }
    return iterations;
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
    int iterations = mergeSort(arr, 0, n - 1);
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
