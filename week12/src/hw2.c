#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __STUDENT {
    char name[20];
    int score;
    struct __STUDENT* next;
} Student;

Student* insert(Student* root, Student value) {
    Student* head = malloc(sizeof(Student));
    head->next = root;
    Student* cursor = head;

    while (cursor->next != NULL)
        cursor = cursor->next;
    cursor->next = malloc(sizeof(Student));
    strcpy(cursor->next->name, value.name);
    cursor->next->score = value.score;
    cursor->next->next = NULL;

    root = head->next;
    free(head);
    return root;
}

Student* delete(Student* root, char* name) {
    Student* head = malloc(sizeof(Student));
    head->next = root;
    Student* cursor = head;

    while (cursor->next != NULL && strcmp(cursor->next->name, name) != 0)
        cursor = cursor->next;
    if (cursor->next != NULL) {
        Student* tmp = cursor->next;
        cursor->next = cursor->next->next;
        free(tmp);
    }

    root = head->next;
    free(head);
    return root;
}

int compare_by_name(Student* a, Student* b) {
    return strcmp(a->name, b->name);
}

int compare_by_score(Student* a, Student* b) {
    if (a->score == b->score)
        return compare_by_name(a, b);
    else
        return b->score - a->score;
}

Student* sort_and_merge(Student* a, Student* b, int (*comparer)(Student*, Student*)) {
    Student* result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (comparer(a, b) <= 0) {
        result = a;
        result-> next = merge(a->next, b, comparer);
    } else {
        result = b;
        result-> next = merge(a, b->next, comparer);
    }

    return result;
}

void split(Student* from, Student** a, Student** b) {
    Student* fast;
    Student* slow;

    // TODO: top down split
}

Student* sort_by_name(Student* root) {
    // TODO: sort by name
}


Student* sort_by_score(Student* root) {
    // TODO: sort by score
}

int main(void) {
    // TODO: main
}
