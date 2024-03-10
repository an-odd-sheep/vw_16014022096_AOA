#include <stdio.h>

int binary_search(int A[], int key, int imin, int imax)
{
    while (imax >= imin) {
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
    int n = 10; 
    int value;

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter value you want to search for: ");
    scanf("%d", &value);

    int index = binary_search(arr, value, 0, n - 1);

    if (index != -1) {
        printf("Value found at index: %d\n", index);
    } else {
        printf("Value not found\n");
    }

    return 0;
}
