#include <stdio.h>

int main(void)
{
    int n = 0;
    int even = 0;
    int odd = 0;

    printf("N의 값을 입력하세요.\n");
    scanf("%d", &n);

    even = n / 2;
    odd = (n / 2) + (n % 2);

    printf("홀수 : %d 개, 짝수 : %d 개\n", odd, even);
}
