#include <stdio.h>

int main(void)
{
    int first = 0;
    int second = 0;
    int third = 0;
    float mean = .0f;

    printf("1차, 2차, 3차 점수를 입력하세요.\n");
    scanf("%d %d %d", &first, &second, &third);

    mean = (first + second + third) / 3.f;

    if (mean >= 80)
        printf("PASS\n");
    else
        printf("FAIL\n");
}
