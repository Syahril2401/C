#include <stdio.h>

int main() {
    char nama[101]; 
    fgets(nama, sizeof(nama), stdin); 

    for (int i = 0; nama[i] != '\0'; i++) {
        if (nama[i] == '\n') {
            nama[i] = '\0'; 
            break; 
        }
    }

    printf("Congrats \"%s\" for joining the CS department at BINUS.\n", nama);

    return 0; 
}
