#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct {
    char species[32];
    int count;
} Fruit;

typedef struct __FRUITNODE{
    Fruit* this;
    struct __FRUITNODE* next;
} FruitNode;

int sum(FruitNode* root) {
    if (root->next == NULL)
        return root->this->count;
    else
        return root->this->count + sum(root->next);
}

void push_inner(FruitNode* node, Fruit* fruit) {
    if (strcmp(node->this->species, fruit->species) == 0)
        node->this->count += fruit->count;
    else if (node->next == NULL) {
        node->next = malloc(sizeof(FruitNode));
        node->next->this = fruit;
        node->next->next = NULL;
    } else
        push_inner(node->next, fruit);
}

BOOL pop_inner(FruitNode* node, Fruit* fruit) {
    if (strcmp(node->this->species, fruit->species) == 0) {
        if (node->this->count > fruit->count) {
            node->this->count -= fruit->count;
            return TRUE;
        }
    } else if (node->next != NULL)
        pop_inner(node->next, fruit);
    return FALSE;
}

BOOL push(FruitNode* root, Fruit* fruit) {
    if (sum(root) + fruit->count > 8)
        return FALSE;
    push_inner(root, fruit);
    return TRUE;
}

BOOL pop(FruitNode* root, Fruit* fruit) {
    if (sum(root) - fruit->count < 0)
        return FALSE;
    return pop_inner(root, fruit);
}

void print_box_inner(FruitNode* node) {
    if (node != NULL) {
        printf("%s %s\n", node->this->species, node->this->count);
        if (node->next != NULL)
            print_box_inner(node->next);
    }
}

void print_box(FruitNode* root) {
    printf("== fruitbox ==\n");
    print_box_inner(root);
    printf("==========\n");
}

int main(void) {
    FruitNode* root = NULL;
    while (TRUE) {
        char command[4];
        char species[32];
        int count;
        scanf("%s %s %d", command, species, &count);
        Fruit* fruit = malloc(sizeof(Fruit));
        strcpy(fruit->species, species);
        fruit->count = count;
        if (command[0] == 'i') {
            BOOL b = FALSE;
            if (root == NULL) {
                root = malloc(sizeof(FruitNode));
                root->this = fruit;
                root->next = NULL;
                b = TRUE;
            } else {
                b = push(root, fruit);
            }
            print_box(root);
            if (b == FALSE)
                printf("Box is full\n");
            printf("\n");
        }
        if (command[0] == 'o') {
            BOOL b = FALSE;
            if (root == NULL) {
                b = FALSE;
            } else {
                b = pop(root, fruit);
            }
            print_box(root);
            if (b == FALSE)
                printf("Not enough fruit\n");
            printf("\n");
        }
    }
}
