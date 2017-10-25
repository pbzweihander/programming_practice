#include <stdio.h>
#include <math.h>

typedef struct sPoint
{
    float x;
    float y;
} Point;

Point get_point()
{
    float x, y;
    Point p;
    scanf("%f %f", &x, &y);
    p.x = x;
    p.y = y;
    return p;
}

float get_distance(Point a, Point b)
{
    float x = a.x - b.x, y = a.y - b.y;
    return sqrt(x * x + y * y);
}

int main(void)
{
    Point base;
    int n;
    float bx, by;
    scanf("%d %f %f", &n, &bx, &by);
    base.x = bx;
    base.y = by;

    float maxd = 0;
    Point maxp;
    for (int i = 0; i < n; i++)
    {
        Point p = get_point();
        float d = get_distance(base, p);
        if (d > maxd)
        {
            maxd = d;
            maxp = p;
        }
    }

    printf("from (%.2f, %.2f) to (%.2f, %.2f) : %.3f\n", base.x, base.y, maxp.x, maxp.y, maxd);
}

