#include <stdio.h>
#include <string.h>

typedef struct {
    char kataPendek[51];
    char kataAsli[51];
} Dictionary;

void translateKata(Dictionary *dict, int dictSize, const char *kata, int caseNumber) {
    printf("Case #%d:\n", caseNumber);
    
    char tempKata[1000];
    strcpy(tempKata, kata);
    
    char *word = strtok(tempKata, " ");
    int firstWord = 1;  
    while (word) {
        int found = 0;
        for (int i = 0; i < dictSize; i++) {
            if (strcmp(dict[i].kataPendek, word) == 0) {
                if (!firstWord) {
                    printf(" "); 
                }
                printf("%s", dict[i].kataAsli);
                found = 1;
                break;
            }
        }
        if (!found) {
            if (!firstWord) {
                printf(" "); 
            }
            printf("%s", word);
        }
        firstWord = 0; 
        word = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("testdata.in", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    
    int T, TC;
    fscanf(file, "%d\n", &T);
    
    Dictionary dict[100];
    for (int i = 0; i < T; i++) {
        fscanf(file, "%[^#]#%[^\n]\n", dict[i].kataPendek, dict[i].kataAsli);
    }
    
    fscanf(file, "%d\n", &TC);
    for (int t = 0; t < TC; t++) {
        char kalimat[1000];
        fgets(kalimat, sizeof(kalimat), file);
        kalimat[strcspn(kalimat, "\n")] = 0; 
        translateKata(dict, T, kalimat, t + 1);
    }
    
    fclose(file);
    return 0;
}
