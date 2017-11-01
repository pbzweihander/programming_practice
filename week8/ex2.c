#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int arr[6];
        make_arr(arr, 45, 6);
        for (int i = 0; i < 6; printf("%d ", arr[i++]));
        printf("\n");
    }
}
