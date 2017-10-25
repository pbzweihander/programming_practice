#include <stdio.h>

int is_prime(int i) {
    if (i == 2)
        return 1;
    if (i % 2 == 0)
        return 0;
    for (int j = 3; j*j <= i; j += 2) {
        if (i % j == 0)
            return 0;
    }
    return 1;
}

int main(void) {
    int n;
    int count = 0;

    printf("정수를 입력하세요 : ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n\n");

    printf("1부터 %d 사이에는 총 %d 개의 소수가 존재합니다.\n", n, count);
}
