#include <stdio.h>
#include <stdlib.h>

#define MAX 21

// Quicksort
void quicksortHoare(int arr[], int left, int right);
int partitionHoare(int arr[], int left, int right);
void quicksortLomuto(int arr[], int left, int right);
int partitionLomuto(int arr[], int left, int right);

// Merge Sort
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

// Counting Sort
void countingSort(int arr[], int size);

void printArray(int arr[], int size);
void swap(int* x, int* y);

int main() {
    int hoareArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("Quicksort (Hoare):\n");
    quicksortHoare(hoareArr, 0, MAX - 1);
    printArray(hoareArr, MAX);

    int lomutoArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nQuicksort (Lomuto):\n");
    quicksortLomuto(lomutoArr, 0, MAX - 1);
    printArray(lomutoArr, MAX);

    int mergeArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nMerge Sort:\n");
    mergeSort(mergeArr, 0, MAX - 1);
    printArray(mergeArr, MAX);

    int countingArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nCounting Sort:\n");
    countingSort(countingArr, MAX);
    printArray(countingArr, MAX);
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

void quicksortLomuto(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partitionLomuto(arr, left, right);
        quicksortLomuto(arr, left, pivot - 1);
        quicksortLomuto(arr, pivot + 1, right);
    }
}

int partitionLomuto(int arr[], int left, int right) {
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < arr[right]) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[right]);
    return i;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void countingSort(int arr[], int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int* countArr = (int*)calloc(max + 1, sizeof(int));
    for (int i = 0; i < size; i++) {
        countArr[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        countArr[i] += countArr[i - 1];
    }
    int* outputArr = (int*)malloc(size * sizeof(int));
    for (int i = size - 1; i >= 0; i--) {
        outputArr[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = outputArr[i];
    }
    free(outputArr);
    free(countArr);
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