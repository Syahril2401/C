#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Alexander Ricky Budianto

void readStudentFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100]; 
    printf("Current Students:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); 
    }

    fclose(file);
}

void addStudentToFile(const char *filename, const char *studentName) {
    FILE *file = fopen(filename, "a"); 
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", studentName); 
    fclose(file);
}

int main() {
    char newStudent[100];

    printf("Reading from file: %s\n\n", "students.txt");
    readStudentFile("students.txt");

    printf("\nEnter new student name to add: ");
    fgets(newStudent, sizeof(newStudent), stdin);
    newStudent[strcspn(newStudent, "\n")] = 0; 

    addStudentToFile("students.txt", newStudent);
    printf("\nUpdated List of Students:\n");
    readStudentFile("students.txt");

    return 0;
}
