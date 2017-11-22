#include<stdio.h>

void my_print(char c,int n) {
    for (int i = 0; i < n; i++)
        printf("%c", c);
    printf("\n");
}

int main(void) {
    char c;
    int n;
    printf("출력할 문자를 입력하세요 : \n");
    scanf("%c",&c);
    printf("개수를 입력하세요 : \n");
    scanf("%d",&n);

    my_print(c,n);

    return 0;
}
