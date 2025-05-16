#include <stdio.h>

int main() {
    int suhu;
    printf("Masukkan suhu: ");
    scanf("%d", &suhu);
    
    if (suhu > 80) {
        printf("hot\n");
    } else if (suhu > 30) {
        printf("warm\n");
    } else if (suhu >= 15) {
        printf("cool\n");
    } else {
        printf("cold\n"); 
    }
    
    return 0;    
}

