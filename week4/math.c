#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 4.0, y = 2.0;
    printf("pow(%.2f, %.2f) = %.2f\n", x, y, pow(x, y));
    printf("sqrt(%.2f) = %.2f\n", x, sqrt(x));
    return 0;
}
