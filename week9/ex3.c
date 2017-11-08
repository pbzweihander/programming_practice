#include <stdio.h>

int product(int* a, int* b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

int main(void) {
    int m1r1[3];
    int m1r2[3];
    int m2c1[3];
    int m2c2[3];

    printf("행렬 A의 값을 입력하세요:\n");
    scanf("%d %d %d", &m1r1[0], &m1r1[1], &m1r1[2]);
    scanf("%d %d %d", &m1r2[0], &m1r2[1], &m1r2[2]);
    printf("\n");

    printf("행렬 B의 값을 입력하세요:\n");
    scanf("%d %d", &m2c1[0], &m2c2[0]);
    scanf("%d %d", &m2c1[1], &m2c2[1]);
    scanf("%d %d", &m2c1[2], &m2c2[2]);
    printf("\n");

    int m3r1[2];
    int m3r2[2];

    m3r1[0] = product(m1r1, m2c1);
    m3r1[1] = product(m1r1, m2c2);
    m3r2[0] = product(m1r2, m2c1);
    m3r2[1] = product(m1r2, m2c2);
    printf("<행렬 C 결과>\n");
    printf("%d %d\n%d %d\n", m3r1[0], m3r1[1], m3r2[0], m3r2[1]);
}
