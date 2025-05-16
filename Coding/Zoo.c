#include <stdio.h>

int main () {
	int N;
	scanf("%d", &N);
	
	int Total = 0;
	int Binatang;
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Binatang);
		Total += Binatang;
	}
	
	printf("%d\n", Total);
	
return 0;	
}
