#include <stdio.h>

int main() {
    char operator;
    double angka1, angka2, hasil;

    printf("Pilih operator (+, -, *, %%, /): ");
    
    scanf("%c", &operator);

    printf("Input numbers: ");
    scanf("%lf %lf", &angka1, &angka2);

    switch (operator) {
        case '+':
            hasil = angka1 + angka2;
            printf("Hasil: %.2lf\n", hasil);
            break;
        case '-':
            hasil = angka1 - angka2;
            printf("Hasil: %.2lf\n", hasil);
            break;
        case '*':
            hasil = angka1 * angka2;
            printf("Hasil: %.2lf\n", hasil);
            break;
        case '%' :
        	printf("Hasil %d\n", (int)angka1 % (int)angka2);
        	break;
        case '/':
            if (angka2 != 0) {
                hasil = angka1 / angka2;
                printf("Hasil: %.2lf\n", hasil);
            } else {
                printf("Pembagian tidak boleh angka 0.\n");
            }
            break;
        default:
            printf("Operator tidak valid.\n");
            break;
    }

    return 0;
}

