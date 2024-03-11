#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binary_search(int A[], int key, int imin, int imax) {
    if (imax < imin) {
        printf("KEY NOT FOUND");
    } else {
        int imid = (imin + imax) / 2;
        if (A[imid] < key) {
            binary_search(A, key, imid + 1, imax);
        } else if (A[imid] > key) {
            binary_search(A, key, imin, imid - 1);
        } else {
            printf("\nKEY %d FOUND AT %d position", A[imid], imid);
        }
    }
}

int main() {
    int n, value;
    clock_t l1, l2;

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

    l1 = clock();
    binary_search(arr, value, 0, n - 1);
    l2 = clock();

    double t1 = ((double)(l2 - l1)) / CLOCKS_PER_SEC;
    printf("TIME : %f \n", t1);

    return 0;
}
