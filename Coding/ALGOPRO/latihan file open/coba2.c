#include <stdio.h>


void count_employees_by_age(const char *filename, int *count_above_51, int *count_44_to_51, 
                             int *count_36_to_43, int *count_28_to_35, int *count_below_28) {
    FILE *input_file = fopen("year.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Unable to open file.\n");
        return;
    }

    int day, month, year;
    while (fscanf(input_file, "%d/%d/%d", &day, &month, &year) == 3) {
        int age = 2024 - year;

        if (age > 51) {
            (*count_above_51)++;
        } else if (age >= 44) {
            (*count_44_to_51)++;
        } else if (age >= 36) {
            (*count_36_to_43)++;
        } else if (age >= 28) {
            (*count_28_to_35)++;
        } else {
            (*count_below_28)++;
        }
    }

    fclose(input_file);
}

void display_results(int count_above_51, int count_44_to_51, int count_36_to_43, int count_28_to_35, int count_below_28) {
    printf("Employees with age above 51: %d\n", count_above_51);
    printf("Employees with age between 44-51: %d\n", count_44_to_51);
    printf("Employees with age between 36-43: %d\n", count_36_to_43);
    printf("Employees with age between 28-35: %d\n", count_28_to_35);
    printf("Employees with age below 28: %d\n", count_below_28);
}


int main() {
    int count_above_51 = 0;
    int count_44_to_51 = 0;
    int count_36_to_43 = 0;
    int count_28_to_35 = 0;
    int count_below_28 = 0;

    count_employees_by_age("year.txt", &count_above_51, &count_44_to_51, &count_36_to_43, &count_28_to_35, &count_below_28);
    
    display_results(count_above_51, count_44_to_51, count_36_to_43, count_28_to_35, count_below_28);

    return 0;
}
