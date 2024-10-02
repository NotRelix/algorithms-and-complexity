#include <stdio.h>
#include <limits.h>

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

int main() {
    int arr[] = {2, 6, 9, 10, 3, 31, 1, 16, 21, 49, 28, 30, 9, 5, 11, 2, 32, 24, 27, 6, 4};
    int arrLen = sizeof(arr) / sizeof(arr[0]);
    tournamentSort(arr, arrLen);
    for (int x = 0; x < arrLen; x++) {
        printf("%d ", arr[x]);
    }
}