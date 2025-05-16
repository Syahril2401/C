#include<stdio.h>

int main()
{
	int N, i, j;
	
	scanf("%d", &N);
	
	int matriks[N][N];
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &matriks[i][j]);
		}
	}
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d", matriks[j][i]);
			if(j < N - 1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
