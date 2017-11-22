#include <stdio.h>
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

int main(void) {
}
