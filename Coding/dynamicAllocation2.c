#include <stdio.h>
#include <stdlib.h>

struct STR_Position {
    int X;
    int Y;
};

struct STR_DOT {
    char C;
    struct STR_Position POS;
};

int main() {
    struct STR_DOT *DOT = malloc(sizeof(struct STR_DOT));

    if (DOT == NULL) {
        printf("alokasi memori gagal\n");
        return 1;
    }

    printf("Masukkan karakter: ");
    scanf(" %c", &DOT->C);

    printf("Masukkan posisi X: ");
    scanf("%d", &DOT->POS.X);

    printf("Masukkan posisi Y: ");
    scanf("%d", &DOT->POS.Y);

    printf("Karakter: %c\n", DOT->C);
    printf("Posisi: (%d, %d)\n", DOT->POS.X, DOT->POS.Y);

    free(DOT);

    return 0;
}
