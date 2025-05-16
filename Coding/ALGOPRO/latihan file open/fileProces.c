#include <stdio.h>

struct dmy {
    int day;
    int month;
    int year;
};

int main() {
    int age52 = 0, age44_51 = 0, age36_43 = 0, age28_35 = 0, age27 = 0;
    FILE *file = fopen("year.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    struct dmy date;

    while (fscanf(file, "%d/%d/%d", &date.day, &date.month, &date.year) == 3) {
        int year_temp = 2024 - date.year;

        if (year_temp > 51) {
            age52++;
        } else if (year_temp >= 44 && year_temp <= 51) {
            age44_51++;
        } else if (year_temp >= 36 && year_temp <= 43) {
            age36_43++;
        } else if (year_temp >= 28 && year_temp <= 35) {
            age28_35++;
        } else {
            age27++;
        }
    }

    fclose(file);

    printf("Employees with age above 51: %d\n", age52);
    printf("Employees with age between 44-51: %d\n", age44_51);
    printf("Employees with age between 36-43: %d\n", age36_43);
    printf("Employees with age between 28-35: %d\n", age28_35);
    printf("Employees with age below 28: %d\n", age27);

    return 0;
}

