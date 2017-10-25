#include <stdio.h>

int fibos[100];

int fibo(int n)
{
    if (n == 1)
        return 0;
    if (fibos[n] != 0)
        return fibos[n];
    if (n == 2)
    {
        fibos[n] = 1;
        return 1;
    }
    fibos[n] = fibo(n - 2) + fibo(n - 1);
    return fibos[n];
}

int main(void)
{
    int n;
    printf("n\n");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", fibo(i));
        sum += fibo(i);
    }
    printf("\nsum: %d\n", sum);
}
