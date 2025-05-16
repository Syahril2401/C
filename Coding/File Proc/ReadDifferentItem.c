#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readProductFileByCategory(const char *filename, const char *category) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[2000]; 
    char product[1000], productCategory[1000];

    printf("Products in category '%s':\n", category);
    int found = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, "@");
        if (token != NULL) {
            strcpy(product, token);
            token = strtok(NULL, "\n");
            if (token != NULL) {
                strcpy(productCategory, token);
                if (strcmp(productCategory, category) == 0) {
                    printf("- %s\n", product);
                    found = 1;
                }
            }
        }
    }

    if (!found) {
        printf("No products found in this category.\n");
    }

    fclose(file);
}

int main() {
    char category[1000];
    printf("Meat/Vegetables/Dairy/Seafood/Fruit\n");
    printf("Enter category to search (case sensitive): ");
    scanf("%s", category);

    readProductFileByCategory("Products.txt", category);
    return 0;
}
