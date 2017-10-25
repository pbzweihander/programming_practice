#include <stdio.h>

int check_prime(int n) {
    if (n == 2)
      return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
        return 0;
    return 1;
}

int mycal(int n) {
    if (n < 2)
        return 2;
    if (n == 2)
        return 2;
    if (n % 2 == 0)
        n -= 1;
    if (check_prime(n))
        return n + mycal(n - 2);
    else
        return mycal(n - 2);
    return 2;
}

int main() {
    int num;
    printf("n을 입력하세요 : ");
    scanf("%d", &num);
    printf("%d\n", mycal(num));
}
