#include <stdio.h>
#include <stdlib.h>

#define MAX 21

// Quicksort
void quicksortHoare(int arr[], int left, int right);
int partitionHoare(int arr[], int left, int right);

void printArray(int arr[], int size);
void swap(int* x, int* y);

int main() {
    int hoareArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("Quicksort (Hoare):\n");
    quicksortHoare(hoareArr, 0, MAX - 1);
    printArray(hoareArr, MAX);
}

void quicksortHoare(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partitionHoare(arr, left, right);
        quicksortHoare(arr, left, pivot);
        quicksortHoare(arr, pivot + 1, right);
    }
}

int partitionHoare(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left - 1;
    int j = right + 1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(&arr[j], &arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}