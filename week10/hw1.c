#include <stdio.h>

int main(void) {
    int number_of_expressions;
    scanf("%d", &number_of_expressions);
    for(int _i = 0; _i < number_of_expressions; _i++) {
        int sum = 0;
        int number;
        char operator;
        char new_operator = '\0';
        scanf("%d%c", &number, &operator);
        sum = number;
        while (new_operator != '\n') {
            scanf("%d%c", &number, &new_operator);
            switch (operator) {
                case '+':
                    sum += number;
                    break;
                case '-':
                    sum -= number;
                    break;
                case '\n':
                    new_operator = '\n';
                    break;
            }
            operator = new_operator;
        }
        printf("Total : %d\n", sum);
    }
}
