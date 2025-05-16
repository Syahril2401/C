#include <stdio.h>
#include <string.h>

typedef struct {
    int nomor;
    char nama[100];
} Tanaman;

void urutTanaman(Tanaman t[], int n) {
    Tanaman temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(t[i].nama, t[j].nama) > 0) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
        }
}

int main() {
    FILE *file = fopen("testdata.in", "r");
    if (!file) return 1;

    int N;
    fscanf(file, "%d", &N);
    Tanaman tanaman[100];

    for (int i = 0; i < N; i++)
        fscanf(file, "%d#%[^\n]", &tanaman[i].nomor, tanaman[i].nama);

    fclose(file);
    urutTanaman(tanaman, N);

    for (int i = 0; i < N; i++)
        printf("%d %s\n", tanaman[i].nomor, tanaman[i].nama);

    return 0;
}
