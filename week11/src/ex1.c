#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    char id[20];
    int grade;
    char raw_grade[3];
} Student;

int compare_student(const void* a, const void* b) {
    if (((Student*)a)->grade > ((Student*)b)->grade)
        return -1;
    else if (((Student*)a)->grade < ((Student*)b)->grade)
        return 1;
    else
        return strcmp(((Student*)a)->id, ((Student*)b)->id);
}

int main(void) {
    Student students[20];
    char name[20];
    char id[20];
    char raw_grade[3];
    int i = 0;
    while (scanf("%s %s %s", name, &id, raw_grade) != EOF) {
        strcpy(students[i].name, name);
        strcpy(students[i].id, id);
        students[i].grade = 0;
        strcpy(students[i].raw_grade, raw_grade);
        switch (raw_grade[0]) {
            case 'A':
                students[i].grade += 40;
                break;
            case 'B':
                students[i].grade += 30;
                break;
            case 'C':
                students[i].grade += 20;
                break;
            case 'D':
                students[i].grade += 10;
                break;
            case 'F':
                students[i].grade += 0;
                break;
        }
        if (raw_grade[0] != 'F' && raw_grade[1] != '\0') {
            switch (raw_grade[1]) {
                case '+':
                    students[i].grade += 3;
                    break;
                case '-':
                    students[i].grade -= 3;
                    break;
            }
        }
        i++;
    }

    qsort(students, i, sizeof(Student), compare_student);

    for(int j = 0; j < i; j++)
        printf("%s\t%s\t%s\n", students[j].name, students[j].id, students[j].raw_grade);
}
