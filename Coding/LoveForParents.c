#include <stdio.h>

int main (){
	int N, Q;
	
	scanf("%d", &N);
	int harga[N];
	
	for (int i = 0; i < N; i++){
		scanf("%d", &harga[i]);
	}
	
	scanf("%d", &Q);
	
	for (int i = 1; i <= Q; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		
		harga[A - 1] = B;
		
		printf("Case #%d: ", i);
		for (int j = 0; j < N; j++) {
			printf("%d", harga[j]);
			if (j <N - 1){
			printf(" ");
		}
	}
	printf("\n");
}
	

return 0;
}

