#include <stdio.h>

int main () {
	int N;
	scanf("%d", &N);
	
	int A[N];
	int B[N];
	int hasil[N];
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	for (int i = 0; i <= N; i++) {
		scanf("%d", &B[i]);
	}
	
	for (int i = 0; i < N; i++) { 
		hasil[A[i]] = B[i];
	}
	
	for (int i = 0; i < N; i++) {
		printf("%d", hasil[i]);
		if (i < N - 1) {
			printf(" ");
		}
	}
	printf("\n");
	
	
return 0;	
}
