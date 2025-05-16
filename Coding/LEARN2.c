#include <stdio.h>

int hitungFPB(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp ;
	}
	return a;
}

int hitungKPK(int a, int b) {
	return(a * b) / hitungFPB(a,b); 
}

int main () {
	int num1, num2;
	
	printf("Masukkan dua bilangan: ");
	scanf("%d %d", &num1, &num2);
	
	int fpb = hitungFPB(num1,num2);
	int kpk = hitungKPK(num1, num2);
	
	printf("FPB dari %d dan %d adalah: %d\n", num1, num2, fpb);
    printf("KPK dari %d dan %d adalah: %d\n", num1, num2, kpk);

    return 0; 
}
