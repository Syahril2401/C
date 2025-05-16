#include <stdio.h>
#include <stdlib.h>
// Alexander Ricky B.

void readStudentFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100]; 
    printf("List of Students:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); 
    }

    fclose(file);
}

int main() {
    printf("Reading from file: %s\n\n", "studentfile.txt");
    readStudentFile("studentfile.txt");
    return 0;
}
