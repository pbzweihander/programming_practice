#include<stdio.h>

int is_prime(int);

int main(void) {
    int n, a;

    printf("양수를 입력하세요. : ");
    scanf("%d", &n);

    a = is_prime(n);

    if(a==0)
        printf("%d는 소수가 아닙니다.\n",n);
    else if(a==1)
        printf("%d는 소수입니다.\n",n);

    return 0;
}

int is_prime(int n) {
    if (n == 2)
      return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}
