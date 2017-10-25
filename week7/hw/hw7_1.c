#include <stdio.h>

int mycal(int n) {
    if (n < 2)
        return 0;
    if (n == 2)
        return 2;
    if (n % 2 != 0)
        n -= 1;
    return n + mycal(n - 2);
}

void hw7_1() {
    extern int n;
    printf("n is %d : %d\n", n, mycal(n));
}
