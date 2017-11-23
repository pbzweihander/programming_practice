#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 200

typedef struct {
    int real;
    int imaginary;
} dc;

dc dc_add(dc a, dc b) {
    dc c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    return c;
}

dc dc_multi(dc a, dc b) {
    dc c;
    c.real = (a.real * b.real) - (a.imaginary * b.imaginary);
    c.imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
    return c;
}

void dc_print(dc n) {
    if (n.imaginary == 0)
        printf("%d\n", n.real);
    else
        printf("(%d + %di)\n", n.real, n.imaginary);
}

int consume_int(char** cursor) {
    int n;
    sscanf(*cursor, "%d", &n);
    while (**cursor != ' ' && **cursor != '\n' && **cursor != '\0')
        *cursor += 1;
    return n;
}

dc consume_dc(char** cursor) {
    int r, i;
    sscanf(*cursor, "(%d + %di)", &r, &i);
    while (**cursor != ')')
        *cursor += 1;
    *cursor += 1;
    dc c;
    c.real = r;
    c.imaginary = i;
    return c;
}

dc consume_word(char** cursor) {
    if (**cursor == '(') {
        return consume_dc(cursor);
    } else {
        dc n;
        n.real = consume_int(cursor);
        n.imaginary = 0;
        return n;
    }
}

int main(void) {
    char line[MAX_LINE_LENGTH];
    printf("Input : ");
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        if (strncmp(line, "end", 3) == 0)
            return 0;
        char* cursor = line;
        dc operand1 = consume_word(&cursor);
        cursor++;
        char operator = *cursor;
        cursor++;
        cursor++;
        dc operand2 = consume_word(&cursor);

        dc result;
        switch (operator) {
            case '+':
                result = dc_add(operand1, operand2);
                break;
            case '*':
                result = dc_multi(operand1, operand2);
                break;
        }
        dc_print(result);
        printf("Input : ");
    }
}
