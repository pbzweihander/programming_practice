#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++)
            if (arr[min] > arr[j])
                min = j;
        swap(&arr[i], &arr[min]);
    }
}

int main(void) {
    int* arr1;
    int* arr2;
    int len1;
    int len2;

    printf("배열 A의 크기와 값을 입력하세요:\n");
    scanf("%d", &len1);
    arr1 = calloc(len1, sizeof(int));
    for (int i = 0; i < len1; i++)
        scanf("%d", &arr1[i]);
    printf("\n");

    printf("배열 B의 크기와 값을 입력하세요:\n");
    scanf("%d", &len2);
    arr2 = calloc(len2, sizeof(int));
    for (int i = 0; i < len2; i++)
        scanf("%d", &arr2[i]);
    printf("\n");

    int* arr3;
    int len3 = len1 + len2;
    arr3 = calloc(len3, sizeof(int));
    for (int i = 0; i < len1; i++)
        arr3[i] = arr1[i];
    for (int i = len1; i < len3; i++)
        arr3[i] = arr2[i - len1];
    selection_sort(arr3, len3);

    printf("<결과>\n");
    printf("배열 C의 크기: %d\n", len3);
    for (int i = 0; i < len3; printf("%d ", arr3[i++]));
    printf("\n\n");
}
