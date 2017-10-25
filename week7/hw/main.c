#include <stdio.h>

void hw7_1();
void hw7_2();

int n = 0;
int a = 0, b = 0;

int main()
{
    printf("HW7-1) n을 입력하세요.\n");
    scanf("%d", &n);
    hw7_1();
    printf("HW7-2) a, b를 입력하세요.\n");
    scanf("%d %d", &a, &b);
    hw7_2();
}
