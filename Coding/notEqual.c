#include <stdio.h>

int main() {
	long long a, b, c, d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	
	long long hasil_kiri = 0;
	long long hasil_kanan = 0;
	hasil_kiri = a * b;
	hasil_kanan = c + d;
	
	if (hasil_kiri > hasil_kanan) {
		printf("True\n");
	} else {
		printf("False\n");
	}
	
return 0;	
}
