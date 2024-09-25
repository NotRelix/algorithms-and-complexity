#include <stdio.h>
#include <stdlib.h>

int* selectionSort(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    int arr[] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    int arrLen = sizeof(arr) / sizeof(arr[0]);

    printf("Selection Sort:\n");
    int* selectionArr = selectionSort(arr, arrLen);
    printArray(selectionArr, arrLen);
}

int* selectionSort(int arr[], int size) {
    
}

void printArray(int arr[], int size) {
    int x;
    for (x = 0; x < size; x++) {
        printf("%d ", arr[x]);
    }
    printf("\n");
}