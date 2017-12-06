#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __STUDENT {
    char name[20];
    int stud_id;
    char major[20];
    struct __STUDENT* next;
} Student;

Student* get_list(FILE* file) {
    Student* root = malloc(sizeof(Student));

    char name[20];
    int stud_id;
    char major[20];

    Student* student = root;
    fscanf(file, "%s %d %s", name, &stud_id, major);
    strcpy(student->name, name);
    student->stud_id = stud_id;
    strcpy(student->major, major);

    while(fscanf(file, "%s %d %s", name, &stud_id, major) != EOF) {
        student->next = malloc(sizeof(Student));
        student = student->next;
        strcpy(student->name, name);
        student->stud_id = stud_id;
        strcpy(student->major, major);
        student->next = NULL;
    }

    return root;
}

Student* search(Student* student, char* name) {
    if (student == NULL)
        return NULL;
    else if (strcmp(name, student->name) == 0)
        return student;
    else
        search(student->next, name);
}

void print(Student* root) {
    if (root == NULL)
        return;
    Student* student = root;
    while (student != NULL) {
        printf("%s %d %s\n", student->name, student->stud_id, student->major);
        student = student->next;
    }
}

int main(void) {
    Student* root = get_list(fopen("input.txt", "r"));
    printf("-------------------------------\n");
    print(root);
    printf("-------------------------------\n");

    char name[20];
    while (1) {
        printf("Enter the name:\n");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0)
            break;

        Student* student = search(root, name);
        if (student == NULL)
            continue;

        int command;
        printf("Choose the option(1.student_id 2.major):\n");
        scanf("%d", &command);
        switch (command) {
            case 1: {
                int id;
                scanf("%d", &id);
                student->stud_id = id;
                }
                break;
            case 2: {
                char major[20];
                scanf("%s", major);
                strcpy(student->major, major);
                }
                break;
        }
        printf("\n");
        print(root);
        printf("\n");
    }
}
