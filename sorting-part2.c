#include <stdio.h>
#include <stdlib.h>

#define MAX 21

typedef struct {
    int elem[MAX];
    int count;
} ARRAY;

typedef struct Node {
    int data;
    struct Node *link;
} *LL;

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

// Gnome Sort
void gnomeSort(int arr[], int size);

// Radix Sort
void radixSort(int arr[], int size);
void radixCount(int arr[], int size, int exp);

// Strand Sort
void strandSort(ARRAY *arr, ARRAY *out);
void extractStrand(ARRAY *input, ARRAY *sublist);
void mergeStrand(ARRAY* output, ARRAY *sublist);

// Bucket Sort
void bucketSort(ARRAY *arr);
int removeFirst(LL *lp);
void insertSorted(LL *lp, int data);
void initializeBucket(LL *lp);

// Helper Functions
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

    int gnomeArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nGnome Sort:\n");
    countingSort(gnomeArr, MAX);
    printArray(gnomeArr, MAX);

    int radixArr[MAX] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    printf("\nRadix Sort:\n");
    radixSort(radixArr, MAX);
    printArray(radixArr, MAX);

    ARRAY strand = {{2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4}, MAX};
    ARRAY strandOut = {.count = 0};
    printf("\nStrand Sort:\n");
    strandSort(&strand, &strandOut);
    printArray(strandOut.elem, MAX);

    ARRAY bucket = {{2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4}, MAX};
    printf("\nBucket Sort:\n");
    bucketSort(&bucket);
    printArray(bucket.elem, MAX);
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

void gnomeSort(int arr[], int size) {
    int x = 1;
    while (x < size) {
        if (x > 0 && arr[x] < arr[x - 1]) {
            swap(&arr[x], &arr[x - 1]);
            x--;
        } else {
            x++;
        }
    }
}

void radixSort(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        radixCount(arr, size, exp);
    }
}

void radixCount(int arr[], int size, int exp) {
    int output[size];
    int count[10] = {0};
    for (int i = 0; i < size; i++) {
        count[arr[i] / exp % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i] / exp % 10] - 1] = arr[i];
        count[arr[i] / exp % 10]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void strandSort(ARRAY *arr, ARRAY *out) {
    if (arr->count <= 0) {
        return;
    }

    ARRAY sublist = {.count = 0};
    extractStrand(arr, &sublist);
    strandSort(arr, out);
    mergeStrand(out, &sublist);
}

void extractStrand(ARRAY *input, ARRAY *sublist) {
    int i, j;
    sublist->elem[sublist->count++] = input->elem[0];
    for (i = 1, j = 0; i < input->count; i++) {
        if (input->elem[i] >= sublist->elem[sublist->count - 1]) {
            sublist->elem[sublist->count++] = input->elem[i];
        } else {
            input->elem[j++] = input->elem[i];
        }
    }
    input->count = j;
}
void mergeStrand(ARRAY* output, ARRAY *sublist) {
    int *mergedArr = (int *)calloc(output->count + sublist->count, sizeof(int));
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < output->count && j < sublist->count; k++) {
        if (output->elem[i] <= sublist->elem[j]) {
            mergedArr[k] = output->elem[i++];
        } else {
            mergedArr[k] = sublist->elem[j++];
        }
    }
    for (; i < output->count; k++) {
        mergedArr[k] = output->elem[i++];
    }
    for (; j < sublist->count; k++) {
        mergedArr[k] = sublist->elem[j++];
    }
    for (k = 0; k < output->count + sublist->count; k++) {
        output->elem[k] = mergedArr[k];
    }
    output->count += sublist->count;
    free(mergedArr);
}

void initializeBucket(LL *lp) {
    *lp = NULL;
}

void insertSorted(LL *lp, int data) {
    LL temp = malloc(sizeof(struct Node));
    if (temp != NULL) {
        temp->data = data;
        temp->link = NULL;
        if (*lp == NULL || (*lp)->data > data) {
            temp->link = *lp;
            *lp = temp;
        } else {
            LL trav = *lp;
            while (trav->link != NULL && trav->link->data <= data) {
                trav = trav->link;
            }
            temp->link = trav->link;
            trav->link = temp;
        }
    }
}

int removeFirst(LL *lp) {
    if (*lp == NULL) {
        return -1;
    }
    LL temp = *lp;
    *lp = temp->link;
    int data = temp->data;
    free(temp);
    return data;
}

void bucketSort(ARRAY *arr) {
    int i, j, min, max;
    min = arr->elem[0];
    max = arr->elem[0];
    for (i = 0; i < arr->count; i++) {
        if (arr->elem[i] < min) {
            min = arr->elem[i];
        }
        if (arr->elem[i] > max) {
            max = arr->elem[i];
        }
    }
    int range = max - min + 1;
    int bucketNum = (range < arr->count) ? arr->count : range;
    LL *buckets = (LL *)malloc(bucketNum * sizeof(LL));
    for (i = 0; i < bucketNum; i++) {
        initializeBucket(&buckets[i]);
    }
    for (i = 0; i < arr->count; i++) {
        int bucket = (arr->elem[i] - min) * bucketNum / range;
        insertSorted(&buckets[bucket], arr->elem[i]);
    }
    for (i = 0, j = 0; i < bucketNum; i++) {
        while (buckets[i] != NULL) {
            arr->elem[j++] = removeFirst(&buckets[i]);
        }
    }
    free(buckets);
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