#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    float max = 0.f;
    int maxx1, maxy1, maxx2, maxy2, maxx3, maxy3;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2, x3, y3;
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
        float area = (x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) / 2.f;
        if (area < 0.f)
            area *= -1.f;
        if (max < area) {
            max = area;
            maxx1 = x1;
            maxx2 = x2;
            maxx3 = x3;
            maxy1 = y1;
            maxy2 = y2;
            maxy3 = y3;
        }
    }
    printf("(%d, %d), (%d, %d), (%d, %d) = %.2f\n", maxx1, maxy1, maxx2, maxy2, maxx3, maxy3, max);
}
