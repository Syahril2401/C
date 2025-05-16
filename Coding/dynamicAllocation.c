#include <stdio.h>
#include <stdlib.h>

int main() {
	int *Bilangan, n;
	
	scanf("%d", &n);
	
	Bilangan = (int *)malloc(n * sizeof(int));//malloc untuk mengalokasikan memori sesuai jumlah bilangan.
	
	if(!Bilangan) {
		printf("Alokasi gagal\n");
		return 1;
	}
	
	for(int i = 0; i < n; i++){
		printf("Bilangan ke-%d\n", i + 1);
		scanf("%d", &Bilangan[i]);
	}
	
	printf("Bilangan: ");
	for(int i = 0; i < n; i++){
		printf("%d ", Bilangan[i]);
	}
	printf("\n");
	
	free(Bilangan);//free untuk membebaskan memori setelah selesai.
	
return 0;
}
