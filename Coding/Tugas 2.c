#include <stdio.h>

int main () {
	float totalAwal, diskon, totalAkhir;
	
	scanf("%f", &totalAwal);
	
	if (totalAwal < 10000 || totalAwal > 10000000){
		printf("Total tiak valid");
		return 1;
	}
	
	if (totalAwal >= 5000000) {
		diskon = 0.20;
	} else if (totalAwal >= 1000000) {
		diskon = 0.10;
	} else {
		diskon = 0.05;
	}
	
	totalAkhir - totalAwal *(1 - diskon);
	
	printf("Total belanja anda : %.2f\n", totalAwal);
	printf("Selamat anda mendapatkan diskon %.2f\n", diskon * 100);
	printf("Total belanja anda menjadi %.2f!\n", totalAkhir);

return 0;	
}
