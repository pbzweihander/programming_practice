#include<stdio.h>

float my_cal(char, float, float);

int main(void)
{
    char op;
    float num1, num2, a;

    printf("연산자를 입력하세요 :\n");
    scanf("%c", &op);

    printf("두 개의 숫자를 입력하세요 : \n");
    scanf("%f %f", &num1, &num2);

    a=my_cal(op, num1, num2);

    printf("결과값은 %.2f 입니다.\n", a);

    return 0;
}

float my_cal(char op, float num1, float num2) {
    switch (op) {
        case '+':
            return num1 + num2;
            break;
        case '-':
            return num1 - num2;
            break;
        case '*':
            return num1 * num2;
            break;
        case '/':
            return num1 / num2;
            break;
    }
    return 0.f;
}
