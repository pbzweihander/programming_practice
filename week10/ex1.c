#include <stdio.h>

int main(void) {
    int number_of_classes;
    scanf("%d", &number_of_classes);
    for (int _i = 0; _i < number_of_classes; _i++) {
        int target_mean, number_of_students;
        scanf("%d %d", &target_mean, &number_of_students);

        int sum = 0;
        for(int _j = 0; _j < number_of_students; _j++) {
            int s;
            scanf("%d", &s);
            sum += s;
        }
        float actual_mean = (float)sum / (float)number_of_students;
        if (actual_mean >= target_mean)
            printf("YES\n");
        else
            printf("No\n");
    }
}
