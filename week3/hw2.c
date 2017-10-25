#include <stdio.h>

int main(void) {
    int n;
    printf("숫자를 입력하세요 : ");
    scanf("%d", &n);
    for (int i = 0; i <= n / 2; i++) {
        int ws = n / 2 - i;
        for (int j = 0; j < ws; j++)
            printf(" ");
        for (int j = 0; j < n - ws * 2; j++)
            printf("*");
        printf("\n");
    }
    for (int i = n / 2 - 1; i >= 0; i--) {
        int ws = n / 2 - i;
        for (int j = 0; j < ws; j++)
            printf(" ");
        for (int j = 0; j < n - ws * 2; j++)
            printf("*");
        printf("\n");
    }
}
