#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mhs {
    char name[100];
    long long nim;
    float gpa;
};

void inputStudent(struct Mhs *student) {
    printf("NIM: ");
    scanf("%lld", &student->nim);
    getchar(); 

    printf("Name: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0'; 

    do {
        printf("GPA: ");
        scanf("%f", &student->gpa);
        if (student->gpa < 0.0 || student->gpa > 4.0) {
            printf("Invalid GPA. Please enter a value between 0.0 and 4.0.\n");
        }
    } while (student->gpa < 0.0 || student->gpa > 4.0);
}

void writeFile(const char *fileName) {
    FILE *file = fopen(fileName, "wb");
    if (!file) {
        perror("Error creating file");
        return;
    }

    struct Mhs student;
    for (int i = 0; i < 5; i++) {
        printf("Student %d\n", i + 1);
        inputStudent(&student);
        fwrite(&student, sizeof(student), 1, file);
    }

    fclose(file);
    printf("File created successfully.\n");
}

void appendFile(const char *fileName) {
    FILE *file = fopen(fileName, "ab");
    if (!file) {
        perror("Error opening file for appending");
        return;
    }

    struct Mhs student;
    for (int i = 0; i < 5; i++) {
        printf("Student %d\n", i + 1);
        inputStudent(&student);
        fwrite(&student, sizeof(student), 1, file);
    }

    fclose(file);
    printf("Records appended successfully.\n");
}

void readFile(const char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        perror("Error opening file for reading");
        return;
    }

    struct Mhs student;
    float totalGpa = 0, highestGpa = 0, lowestGpa = 100.0;
    int count = 0;

    printf("\n%-10s %-20s %-5s\n", "NIM", "Name", "GPA");
    printf("%-10s %-20s %-5s\n", "----------", "--------------------", "-----");

    while (fread(&student, sizeof(student), 1, file)) {
        printf("%-10lld %-20s %.2f\n", student.nim, student.name, student.gpa);
        if (student.gpa > highestGpa) highestGpa = student.gpa;
        if (student.gpa < lowestGpa) lowestGpa = student.gpa;
        totalGpa += student.gpa;
        count++;
    }

    fclose(file);

    if (count > 0) {
        printf("\nHighest GPA  : %.2f\n", highestGpa);
        printf("Lowest GPA   : %.2f\n", lowestGpa);
        printf("Average GPA  : %.2f\n", totalGpa / count);
    } else {
        printf("No records found.\n");
    }
}

int main() {
    const char *fileName = "Mhs.dat";
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create and write to file\n");
        printf("2. Append records to file\n");
        printf("3. Read and display file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: writeFile(fileName); break;
            case 2: appendFile(fileName); break;
            case 3: readFile(fileName); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
