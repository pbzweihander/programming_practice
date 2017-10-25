#include <stdio.h>

int gcd(int a, int b) {
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    for (int i = a; i >= 1; i--)
        if (a % i == 0 && b % i == 0)
            return i;
    return 1;
}

void hw7_2() {
    extern int a, b;
    printf("a is %d, b is %d : %d\n", a, b, gcd(a, b));
}
