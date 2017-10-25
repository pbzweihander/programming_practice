#include <stdio.h>

void print_result(int a, int b, char o, int result);

int main(void) {
    int a, b;
    printf("2개의 정수를 입력하세요 : ");
    scanf("%d %d", &a, &b);
    print_result(a, b, '+', a + b);
    print_result(a, b, '*', a * b);
    print_result(a, b, '%', a % b);
}

void print_result(int a, int b, char o, int result) {
    printf("%d %c %d = %d (8진수 : %o) (16진수 : %x)\n", a, o, b, result, result, result);
    for (int i = 0; i < result; i++)
        printf("*");
    printf("\n");
}

