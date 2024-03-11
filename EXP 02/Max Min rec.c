#include <stdio.h>
#include <time.h>

void MaxMin_linear(int a[], int n, int* maxl, int* minl, int* iterations) {
    *minl = *maxl = a[0];
    *iterations = 0; // Initialize iteration counter
   
    for(int i = 1; i < n; i++) {
        (*iterations)++; // Increment iteration counter
        if (a[i] >= *maxl) {
            *maxl = a[i];
        } else if (a[i] <= *minl) {
            *minl = a[i];
        }
    }
}

void MaxMin_dac(int a[], int i, int j, int* max, int* min, int* iterations) {
    if (i == j) {
        *min = *max = a[i];
    } else if (i == j - 1) {
        (*iterations)++; // Increment iteration counter
        if (a[i] < a[j]) {
            *max = a[j];
            *min = a[i];
        } else {
            *max = a[i];
            *min = a[j];
        }
    } else {
        int max1, min1;
        int mid = (i + j) / 2;
       
        MaxMin_dac(a, i, mid, max, min, iterations);
        MaxMin_dac(a, mid + 1, j, &max1, &min1, iterations);
       
        if (*max < max1) {
            *max = max1;
        }
        if (*min > min1) {
            *min = min1;
        }
        *iterations += 2; // Increment iteration counter for each recursive call
    }
}

int main() {
    int maxl, minl, max, min, n, iterations_linear, iterations_dac;
    clock_t l1, l2, d1, d2;
    
    printf("Enter value of n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    l1 = clock();
    MaxMin_linear(arr, n, &maxl, &minl, &iterations_linear);
    l2 = clock();
   
    d1 = clock();
    MaxMin_dac(arr, 0, n - 1, &max, &min, &iterations_dac);
    d2 = clock();
   
    double t1 = 1000000 * ((double)(l2 - l1)) / CLOCKS_PER_SEC;
    double t2 = 1000000 * ((double)(d2 - d1)) / CLOCKS_PER_SEC;
   
    printf("LINEAR : \n");
    printf("MAX = %d, MIN = %d \n", maxl, minl);
    printf("TIME (in microseconds) : %.2f \n", t1);
    printf("Number of iterations: %d\n", iterations_linear);
   
    printf("DIVIDE AND CONQUER : \n");
    printf("MAX = %d, MIN = %d \n", max, min);
    printf("TIME (in microseconds): %.2f \n", t2);
    printf("Number of iterations: %d\n", iterations_dac);
   
    return 0;
}
