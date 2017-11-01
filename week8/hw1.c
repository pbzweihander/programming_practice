#include <stdio.h>
#include <string.h>

int main(void) {
    char text[32];

    printf("input string : ");
    fgets(text, sizeof(text), stdin);
    int len = strlen(text);
    text[--len] = '\0';

    int i = 0;
    int j = len - 1;
    int b = 0;
    while (i < j) {
        if (text[i++] != text[j--]) {
            b = 1;
            break;
        }
    }
    printf("%s is ", text);
    if (b)
        printf("not ");
    printf("a symmetrical word\n");
}
