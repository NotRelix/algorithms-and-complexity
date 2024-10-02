#include <stdio.h>
#include <stdlib.h>
#define MAX 21

void selectionSort(int arr[], int size);
void bubbleSort(int arr[], int size);

void swap(int* x, int* y);
void printArray(int arr[], int size);

int main() {
    int selectionArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("Selection Sort:\n");
    selectionSort(selectionArr, MAX);
    printArray(selectionArr, MAX);

    int bubbleArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nBubble Sort:\n");
    bubbleSort(bubbleArr, MAX);
    printArray(bubbleArr, MAX);
}

void selectionSort(int arr[], int size) {
    for (int x = 0; x < size; x++) {
        int min = x;
        for (int y = x + 1; y < size; y++) {
            if (arr[min] > arr[y]) {
                min = y;
            }
        }
        swap(&arr[min], &arr[x]);
    }
}

void bubbleSort(int arr[], int size) {
    for (int x = size - 1; x > 0; x--) {
        for (int y = 1; y <= x; y++) {
            if (arr[y] < arr[y - 1]) {
                swap(&arr[y], &arr[y - 1]);
            }
        }
    }
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int size) {
    for (int x = 0; x < size; x++) {
        printf("%d ", arr[x]);
    }
    printf("\n");
}