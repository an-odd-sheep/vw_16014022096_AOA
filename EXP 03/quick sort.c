#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int left, int right) {
    int pivot = A[left];
    int lo = left + 1;
    int hi = right;

    while (lo <= hi) {
        while (A[hi] > pivot)
            hi--;
        while (lo <= hi && A[lo] <= pivot)
            lo++;
        if (lo <= hi)
            swap(&A[lo], &A[hi]);
    }

    swap(&A[left], &A[hi]);
    return hi;
}

void quicksort(int A[], int left, int right) {
    if (left < right) {
        int q = partition(A, left, right);
        quicksort(A, left, q - 1);
        quicksort(A, q + 1, right);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generator
    int n = 10; // Size of the array
    int arr[n]; // Declare an array of size n

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Fill the array with random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
