#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL is_anagram(const char* a, const char* b) {
    if (strlen(a) != strlen(b))
        return FALSE;
    char* bb = strdup(b);
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        BOOL matched = FALSE;
        for (int j = 0; j < len; j++)
            if (a[i] == bb[j]) {
                bb[j] = '\0';
                matched = TRUE;
            }
        if (!matched)
            return FALSE;
    }
    return TRUE;
}

int main(void) {
    char keys[20][20];
    int keys_count = 0;

    FILE* input_file = fopen("input.txt", "r");
    FILE* words_file = fopen("words.txt", "r");
    FILE* output_file = fopen("output.txt", "w");

    char key[20];
    while (fscanf(input_file, "%s", key) != EOF)
        strcpy(keys[keys_count++], key);

    char word[20];
    while (fscanf(words_file, "%s", word) != EOF)
        for (int i = 0; i < keys_count; i++)
            if (is_anagram(word, keys[i]))
                fprintf(output_file, "%s is anagram of %s\n", word, keys[i]);
}
