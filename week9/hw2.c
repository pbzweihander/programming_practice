#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct sVec {
    int* arr;
    int size;
    int len;
} Vec;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++)
            if (arr[min] > arr[j])
                min = j;
        swap(&arr[i], &arr[min]);
    }
}

void make_arr(int* arr, int max, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % max + 1;
        while(i != 0) {
            int b = 0;
            for (int j = 0; j < i; j++)
                if (arr[i] == arr[j])
                    b = 1;
            if (b == 0)
                break;
            arr[i] = rand() % max + 1;
        }
    }
    sort(arr, len);
}

void arrcp(int* from, int* to, int size) {
    for (int i = 0; i < size; i++)
        to[i] = from[i];
}

void print(Vec* vec) {
    printf("The size of array : %d\n", vec->size);
    for (int i = 0; i < vec->len; printf("%d ", vec->arr[i++]));
    printf("\n\n");
}

void insert(Vec* vec, int n) {
    if (vec->len == vec->size) {
        int* tmp_arr = calloc(vec->size, sizeof(int));
        arrcp(vec->arr, tmp_arr, vec->size);
        free(vec->arr);
        vec->arr = calloc(vec->size * 2, sizeof(int));
        arrcp(tmp_arr, vec->arr, vec->size);
        vec->size *= 2;
        free(tmp_arr);
    }

    int i = 0;
    while (i < vec->len && vec->arr[i] <= n)
        i++;
    for (int j = vec->len - 1; j >= i; j--)
        if (j + 1 < vec->size)
            vec->arr[j + 1] = vec->arr[j];
    vec->arr[i] = n;
    vec->len += 1;
}

void delete(Vec* vec, int n) {
    int i = 0;
    while (i < vec->len && vec->arr[i] != n)
        i++;
    if (i == vec->len)
        return;
    for (int j = i; j < vec->len - 1; j++)
        vec->arr[j] = vec->arr[j + 1];
    vec->len -= 1;

    if (vec->len < vec->size / 2) {
        vec->size /= 2;
        int* tmp_arr = calloc(vec->size, sizeof(int));
        arrcp(vec->arr, tmp_arr, vec->size);
        free(vec->arr);
        vec->arr = calloc(vec->size, sizeof(int));
        arrcp(tmp_arr, vec->arr, vec->size);
        free(tmp_arr);
    }
}

int get_number() {
    int n;
    printf("Input number : ");
    scanf("%d", &n);
    return n;
}

int main(void) {
    Vec vec;
    vec.size = 4;
    vec.len = 3;
    vec.arr = calloc(vec.size, sizeof(int));
    make_arr(vec.arr, 64, vec.len);

    int b = 1;
    while (b) {
        int command;
        printf("0. Exit 1. Insert 2. Delete 3. Print\n");
        printf("Select Menu : ");
        scanf("%d", &command);

        switch (command) {
            case 0:
                b = 0;
                break;
            case 1:
                insert(&vec, get_number());
                break;
            case 2:
                delete(&vec, get_number());
                break;
            case 3:
                break;
            default:
                return 1;
        }
        print(&vec);
    }
}
