#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_LEN = 8;

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

int insert(int* arr, int len, int n) {
    if (len == MAX_LEN)
        return len;
    if (len == 0) {
        arr[len++] = n;
        return len;
    }

    int i = 0;
    while (i < len && arr[i] <= n)
        i++;
    for (int j = len - 1; j >= i; j--)
        if (j + 1 < MAX_LEN)
            arr[j + 1] = arr[j];
    arr[i] = n;
    return ++len;
}

int delete(int* arr, int len, int n) {
    if (len == 0)
        return len;

    int i = 0;
    while (i < len && arr[i] != n)
        i++;
    if (i == len)
        return len;
    for (int j = i; j < len - 1; j++)
        arr[j] = arr[j + 1];
    return --len;
}

void print(int* arr, int len) {
    for (int i = 0; i < len; printf("%d ", arr[i++]));
    printf("\n");
}

int insert_menu(int* arr, int len) {
    int n;
    printf("Input number : ");
    scanf("%d", &n);
    return insert(arr, len, n);
}

int delete_menu(int* arr, int len) {
    int n;
    printf("Input number : ");
    scanf("%d", &n);
    return delete(arr, len, n);
}

void print_menu(int* arr, int len) {
    printf("The number of item : %d\n", len);
    print(arr, len);
}

int main(void) {
    srand(time(NULL));

    int arr[8];
    int len = 3;
    make_arr(arr, 64, len);

    int b = 1;
    while (b) {
        int menu;
        printf("0. Exit 1. Insert 2. Delete 3. Print\n");
        printf("Select Menu : ");
        scanf("%d", &menu);

        switch (menu) {
            case 0:
                print(arr, len);
                b = 0;
                break;
            case 1:
                len = insert_menu(arr, len);
                break;
            case 2:
                len = delete_menu(arr, len);
                break;
            case 3:
                print_menu(arr, len);
                break;
        }
        printf("\n");
    }
}
