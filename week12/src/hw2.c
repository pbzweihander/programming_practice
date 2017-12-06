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
        result-> next = sort_and_merge(a->next, b, comparer);
    } else {
        result = b;
        result-> next = sort_and_merge(a, b->next, comparer);
    }

    return result;
}

void split_before_sort(Student* from, Student** a, Student** b) {
    Student* fast;
    Student* slow;

    if (from == NULL || from->next == NULL) {
        *a = from;
        *b = NULL;
    } else {
        slow = from;
        fast = from->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *a = from;
        *b = slow->next;
        slow->next = NULL;
    }
}

Student* merge_sort(Student* head, int (*comparer)(Student*, Student*)) {
    Student* a;
    Student* b;

    if (head == NULL || head->next == NULL)
        return head;

    split_before_sort(head, &a, &b);

    a = merge_sort(a, comparer);
    b = merge_sort(b, comparer);

    return sort_and_merge(a, b, comparer);
}

Student* sort_by_name(Student* root) {
    return merge_sort(root, *compare_by_name);
}


Student* sort_by_score(Student* root) {
    return merge_sort(root, *compare_by_score);
}

void print(Student* root) {
    Student* cursor = root;
    while (cursor != NULL) {
        printf("%s(%d)", cursor->name, cursor->score);
        if (cursor->next != NULL)
            printf(" -> ");
        cursor = cursor->next;
    }
    printf("\n");
}

int main(void) {
    Student* root = NULL;

    char command[8];
    while (1) {
        printf("Input:\n");
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            char name[20];
            int score;
            scanf("%s %d", name, &score);
            Student s;
            strcpy(s.name, name);
            s.score = score;
            root = insert(root, s);
        } else if (strcmp(command, "delete") == 0) {
            char name[20];
            scanf("%s", name);
            root = delete(root, name);
        } else if (strcmp(command, "print") == 0)
            print(root);
        else if (strcmp(command, "sort1") == 0) {
            root = sort_by_name(root);
            print(root);
        } else if (strcmp(command, "sort2") == 0) {
            root = sort_by_score(root);
            print(root);
        } else if (strcmp(command, "exit") == 0)
            return 0;
    }
}
