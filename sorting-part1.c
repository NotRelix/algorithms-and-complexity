#include <stdio.h>
#include <stdlib.h>
#define MAX 21

void selectionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void combSort(int arr[], int size);
void insertionSort(int arr[], int size);
void shellSort(int arr[], int size);
void heapSort(int arr[], int size);
void heapify(int arr[], int size, int root);
void tournamentSort(int arr[], int size);
void createTree(int arr[], int tree[], int size, int* value);
void recreate(int tree[], int size, int* value);
int winner(int pos1, int pos2, int tree[], int size);


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
    
    int heapArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nHeap Sort:\n");
    heapSort(heapArr, MAX);
    printArray(heapArr, MAX);

    int tournamentArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nTournament Sort:\n");
    tournamentSort(tournamentArr, MAX);
    printArray(tournamentArr, MAX);
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

void heapSort(int arr[], int size) {
    for (int x = size / 2 - 1; x >= 0; x--) {
        heapify(arr, size, x);
    }
    for (int x = size - 1; x >= 0; x--) {
        swap(&arr[x], &arr[0]);
        heapify(arr, x, 0);
    }
}

void heapify(int arr[], int size, int root) {
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int largest = root;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != root) {
        swap(&arr[largest], &arr[root]);
        heapify(arr, size, largest);
    }
}

int winner(int pos1, int pos2, int tree[], int size) {
    int x = pos1 >= size ? pos1 : tree[pos1];
    int y = pos2 >= size ? pos2 : tree[pos2];
    return tree[x] < tree[y] ? x : y;
}

void recreate(int tree[], int size, int* value) {
    int i = tree[1];
    while (i > 1) {
        int j, k = i / 2;
        if (i % 2 == 0 && i < 2 * size - 1) {
            j = i + 1;
        } else {
            j = i - 1;
        }
        tree[k] = winner(i, j, tree, size);
        i = k;
    }
    *value = tree[tree[1]];
    tree[tree[1]] = INT_MAX;
}

void createTree(int arr[], int tree[], int size, int* value) {
    for (int i = 0; i < size; i++) {
        tree[i + size] = arr[i];
    }
    for (int i = 2 * size - 1; i > 1; i -= 2) {
        int k = i / 2;
        int j = i - 1;
        tree[k] = winner(i, j, tree, size);
    }
    *value = tree[tree[1]];
    tree[tree[1]] = INT_MAX;
}

void tournamentSort(int arr[], int size) {
    int tree[2 * size];
    int value;
    createTree(arr, tree, size, &value);
    for (int i = 0; i < size; i++) {
        arr[i] = value;
        recreate(tree, size, &value);
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