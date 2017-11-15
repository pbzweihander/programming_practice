#include <stdio.h>
#include <limits.h>

const int BIT_COUNT = sizeof(int) * CHAR_BIT;

void bit_print(int a) {
    int i;
    int mask = 1 << (BIT_COUNT - 1);

    for (i = 1; i <= BIT_COUNT; i++) {
        putchar((a & mask) == 0 ? '0' : '1');
        a <<= 1;
        if (i % CHAR_BIT == 0 && i < BIT_COUNT)
            putchar(' ');
    }
}

int scan_binary() {
    int raw;
    int n = 0;
    int i = 0;
    scanf("%d", &raw);
    while (raw >= 10) {
        int a = raw % 10;
        raw /= 10;
        n += a * (1 << i++);
    }
    n += raw * (1 << i);
    return n;
}

int main(void) {
    int a;
    int b;
    printf("Input 1 : ");
    a = scan_binary();
    printf("Input 2 : ");
    b = scan_binary();

    printf("Result: ");
    bit_print(a + b);
    printf(" (%d)\n", a + b);
}
