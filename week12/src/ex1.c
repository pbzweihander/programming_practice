#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct __NODE {
    int value;
    struct __NODE* next;
} Node;

void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = malloc(sizeof(Node));
        (*root)->value = value;
        (*root)->next = NULL;
    } else if ((*root)->value > value) {
        Node* node = malloc(sizeof(Node));
        node->value = value;
        node->next = *root;
        *root = node;
    } else {
        Node* node = *root;
        while (node->next != NULL && node->next->value < value)
            node = node->next;
        Node* tmp = node->next;
        node->next = malloc(sizeof(Node));
        node->next->value = value;
        node->next->next = tmp;
    }
}

void delete(Node** root, int value) {
    if (*root == NULL)
        return;
    if ((*root)->value == value) {
        Node* tmp = *root;
        *root = (*root)->next;
        free(tmp);
        return;
    }
    Node* node = *root;
    while (node->next != NULL && node->next->value != value)
        node = node->next;
    if (node->next != NULL) {
        Node* tmp = node->next;
        node->next = tmp->next;
        free(tmp);
    }
}

BOOL find(Node* root, int value) {
    if (root == NULL)
        return FALSE;
    Node* node = root;
    while (node != NULL && node->value != value)
        node = node->next;
    if (node != NULL)
        return TRUE;
    return FALSE;
}

void print(Node* root) {
    if (root == NULL)
        return;
    Node* node = root;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

int main(void) {
    Node* root = NULL;

    char command[7];
    scanf("%s", command);
    while(strcmp(command, "Exit") != 0) {
        if (strcmp(command, "Insert") == 0) {
            int n;
            scanf("%d", &n);
            insert(&root, n);
        } else if (strcmp(command, "Delete") == 0) {
            int n;
            scanf("%d", &n);
            delete(&root, n);
        } else if (strcmp(command, "Find") == 0) {
            int n;
            scanf("%d", &n);
            BOOL b = find(root, n);
            if (b)
                printf("True\n");
            else
                printf("False\n");
        } else if (strcmp(command, "Print") == 0)
            print(root);
        scanf("%s", command);
    }
    print(root);
}
