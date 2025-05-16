#include <stdio.h>
#include <string.h>

struct plantData {
    char alias[100];
    char species[100];
};

int main() {
    FILE *inputFile = fopen("testdata.in", "r");
    if (!inputFile) return 1;

    int totalPlants;
    fscanf(inputFile, "%d", &totalPlants);
    struct plantData plantList[totalPlants];

    for (int i = 0; i < totalPlants; i++) {
        fscanf(inputFile, " %[^\n#]#%[^\n]", plantList[i].alias, plantList[i].species);
    }

    int totalQueries;
    fscanf(inputFile, "%d", &totalQueries);

    for (int j = 0; j < totalQueries; j++) {
        char queryName[40];
        fscanf(inputFile, " %s", queryName);

        int foundIndex = -1;
        for (int k = 0; k < totalPlants; k++) {
            if (strcmp(queryName, plantList[k].alias) == 0) {
                foundIndex = k;
                break;
            }
        }

        if (foundIndex == -1) {
            printf("Case #%d: N/A\n", j + 1);
        } else {
            printf("Case #%d: %s\n", j + 1, plantList[foundIndex].species);
        }
    }

    fclose(inputFile);
    return 0;
}

