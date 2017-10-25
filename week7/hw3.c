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

int factor_rec(int* factors, int factor_count, int n) {
    int i = 2;
    if (n == 1) {
        return factor_count;
    }
    if (n % i == 0) {
        factors[factor_count++] = i;
        return factor_rec(factors, factor_count, n / i);
    }
    i++;
    if (n % i == 0) {
        factors[factor_count++] = i;
        return factor_rec(factors, factor_count, n / i);
    }
    while (i <= n) {
        if (check_prime(i)) {
            if (n % i == 0) {
                factors[factor_count++] = i;
                return factor_rec(factors, factor_count, n / i);
            }
        }
        i += 2;
    }
    return factor_count;
}

void factorize(int n) {
    int factors[1000];
    int factor_count = 0;
    factor_count = factor_rec(factors, factor_count, n);

    printf("%d = %d", n, factors[0]);
    if (factor_count > 1) {
        for (int i = 1; i < factor_count; i++)
            printf(" * %d", factors[i]);
    }
    printf("\n");
}

int main(void) {
    int n;
    printf("Input value : ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Error\n");
        return 1;
    }
    factorize(n);
}
