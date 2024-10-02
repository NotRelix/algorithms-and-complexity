#include <stdio.h>
#include <stdlib.h>
#define MAX 21

void selectionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void combSort(int arr[], int size);
void insertionSort(int arr[], int size);
void shellSort(int arr[], int size);

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

    int combArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nComb Sort:\n");
    combSort(combArr, MAX);
    printArray(combArr, MAX);

    int insertionArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nInsertion Sort:\n");
    insertionSort(insertionArr, MAX);
    printArray(insertionArr, MAX);

    int shellArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nShell Sort:\n");
    shellSort(shellArr, MAX);
    printArray(shellArr, MAX);
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

void combSort(int arr[], int size) {
    int gap = size;
    int sorted = 0;
    float shrinkFactor = 1.3;
    while (gap > 1 || !sorted) {
        sorted = 1;
        gap = (int)(gap / shrinkFactor);
        if (gap < 1) gap = 1;
        for (int x = 0; x < size - gap; x++) {
            if (arr[x] > arr[x + gap]) {
                swap(&arr[x], &arr[x + gap]);
                sorted = 0;
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    int x, y, key;
    for (x = 1; x < size; x++) {
        key = arr[x];
        y = x - 1;
        while (y >= 0 && arr[y] > key) {
            arr[y + 1] = arr[y];
            y--;
        }
        arr[y + 1] = key;
    }
}

void shellSort(int arr[], int size) {
    int x, y, gap;
    for (gap = size / 2; gap > 0; gap /= 2) {
        for (x = gap; x < size; x++) {
            int key = arr[x];
            for (y = x; y >= gap && arr[y] < arr[y - gap]; y -= gap) {
                arr[y] = arr[y - gap];
            }
            arr[y] = key;
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