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

void change(int* arr, int len, int from, int to) {
    for (int i = 0; i < len; i++)
        if (arr[i] == from)
            arr[i] = to;
}

void find_and_swap(int* arr, int len, int x, int y) {
    int x_i = -1, y_i = -1;
    for (int i = 0; i < len; i++)
        if (arr[i] == x)
            x_i = i;
        else if (arr[i] == y)
            y_i = i;
    if (x_i != -1 && y_i != -1)
        swap(&arr[x_i], &arr[y_i]);
}

void shift_once(int* arr, int len) {
    int tmp = arr[len - 1];
    for (int i = len - 2; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = tmp;
}

void shift(int* arr, int len, int x) {
    for (int i = 0; i < x; i++)
        shift_once(arr, len);
}

void partial_sort(int* arr, int x, int y) {
    int* tmp_arr = calloc(y - x + 1, sizeof(int));
    for (int i = x; i <= y; i++) {
        tmp_arr[i - x] = arr[i];
    }
    sort(tmp_arr, y - x + 1);
    for (int i = x; i <= y; i++) {
        arr[i] = tmp_arr[i - x];
    }
    free(tmp_arr);
}

void print(int* arr, int len) {
    printf("결과: ");
    for (int i = 0; i < len; printf("%d ", arr[i++]));
    printf("\n\n");
}

int main(void) {
    int len;
    printf("배열 A의 크기를 입력하세요.\n");
    scanf("%d", &len);

    int* arr = calloc(len, sizeof(int));
    make_arr(arr, 100, len);
    print(arr, len);

    int b = 1;
    while (b) {
        int command, arg1, arg2;
        printf("명령문을 입력하세요.\n");
        scanf("%d %d %d", &command, &arg1, &arg2);
        switch (command) {
            case 0:
                change(arr, len, arg1, arg2);
                break;
            case 1:
                find_and_swap(arr, len, arg1, arg2);
                break;
            case 2:
                shift(arr, len, arg2);
                break;
            case 3:
                partial_sort(arr, arg1, arg2);
                break;
            case 4:
                b = 0;
                break;
        }
        print(arr, len);
    }
}
