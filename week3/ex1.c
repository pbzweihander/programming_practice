#include <stdio.h>

int main(void) {
    float a = 1, b = 2, c = 3, d = 4;

    printf("a = %f, b = %f, c = %f, d = %f\n\n", a, b, c, d);

    printf("a * b / c = %f\n", a * b / c);
    printf("a * b / c = %.3f\n\n", a * b / c);

    printf("1 + a * b = %f\n", 1 + a * b);
    printf("1 + a * b = %03.0f\n\n", 1 + a * b);

    printf("a = %2.1f, b = %2.1f, c = %2.1f, d = %2.1f\n", a, b, c, d);
    printf("++a * b - c-- = %f\n", ++a * b - c--);
    printf("a = %2.1f, b = %2.1f, c = %2.1f, d = %2.1f\n", a, b, c, d);

    return 0;
}
