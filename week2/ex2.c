#include <stdio.h>

int main(void)
{
    int diameter = 0;
    float pi = 3.14f;

    printf("지름(diameter)의 값을 입력하세요.\n");
    scanf("%d", &diameter);

    float circumference = pi * diameter;
    float area = pi * diameter * diameter / 4.f;

    printf("둘레(circumference): %f\n", circumference);
    printf("널이(area): %f\n", area);
}
