#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int A[], int key, int imin, int imax, int *iterations)
{
    *iterations = 0; 

    while (imax >= imin) {
        (*iterations)++; 
        int imid = (imin + imax) / 2;

        if (A[imid] == key) {
            return imid;
        } else if (A[imid] < key) {
            imin = imid + 1;
        } else {
            imax = imid - 1;
        }
    }
    return -1; 
}

int main() {
    
    int n, value, iterations;
    
    printf("Enter value of n: ");
    scanf("%d", &n); 
    
    int arr[n];
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter value you want to search for: ");
    scanf("%d", &value);

    clock_t l1, l2;

    l1 = clock();
    int index = binary_search(arr, value, 0, n - 1, &iterations);
    l2 = clock();

    if (index != -1) {
        printf("Value found at index: %d\n", index);
    } else {
        printf("Value not found\n");
    }
    
    double t1 = 1000000 * ((double)(l2 - l1)) / CLOCKS_PER_SEC;
    printf("TIME (in micro seconds) : %f \n", t1);
    printf("Number of iterations: %d\n", iterations);

    return 0;
}
