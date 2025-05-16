#include <stdio.h>

int main () {
	int N;
	long long total = 0;
	int awal = 100;
	int bonus = 50;

	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		total += (100+(i*50));
	}
	
	printf("%lld\n", total);
	
	
return 0;	
}
