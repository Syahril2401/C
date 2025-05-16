#include <stdio.h>
#include <math.h>

// fungsi hitung akar persamaan kuadrat
void calculateRoots(double a, double b, double c, double *x1, double *x2, int *imaginary) {
    double d;
    // hitung diskriminan
    d = b * b - 4 * a * c;

    if (d < 0) {
        *imaginary = 1; 
    } else {
        *imaginary = 0; 
        *x1 = (-b + sqrt(d)) / (2 * a); // hitung akar pertama
        *x2 = (-b - sqrt(d)) / (2 * a); // hitung akar kedua
    }
}


void getUserInput(double *a, double *b, double *c) {
    printf("Input koefisien a: ");
    scanf("%lf", a);
    printf("Input koefisien b: ");
    scanf("%lf", b);
    printf("Input koefisien c: ");
    scanf("%lf", c);
}

int main() {
    double a, b, c, x1, x2;
    int imaginary;

    
    getUserInput(&a, &b, &c);


    if (a == 0) {
        printf("Koefisien 'a' tidak boleh nol.\n");
        return 1; // Keluar dari program jika 'a' nol
    }

    // Menghitung akar
    calculateRoots(a, b, c, &x1, &x2, &imaginary);

    // Menampilkan hasil
    if (imaginary) {
        printf("Akar imajiner\n");
    } else {
        printf("Akar: x1 = %lf, x2 = %lf\n", x1, x2);
    }

    return 0; 
}

