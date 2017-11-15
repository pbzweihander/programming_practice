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
    printf("\n");
}

int main(void) {
    int a, n;
    printf("a : ");
    scanf("%d", &a);
    printf("n : ");
    scanf("%d", &n);

    printf("\nBitwise a: ");
    bit_print(a);

    int mask_right = (1 << n) - 1;
    int mask_left = ~(mask_right << (BIT_COUNT - n));
    int right = a & mask_right;
    int shifted = (a >> n) & mask_left;
    int left = right << (BIT_COUNT - n);
    int b = shifted | left;

    printf("\nCircular right shift a: ");
    bit_print(b);
    printf("\n");
}
