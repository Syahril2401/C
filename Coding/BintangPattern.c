#include <stdio.h>

int main() {
//    int N;
//    printf("Masukkan nilai N (1-4): ");
//    scanf("%d", &N);
//    
//    if (N < 1 || N > 4) {
//        printf("Masukkan nilai N 1 sampe 4.\n");
//        return 1;
//    }

int N = 4;
	//baris
    for (int i = 0; i < N; i++) {
      //kolom
	    for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                printf("*");
            } else {
            	printf(" ");
			}
        }
        printf("\n");
    }

    return 0;
}

