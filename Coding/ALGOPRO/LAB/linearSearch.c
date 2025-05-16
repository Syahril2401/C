#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
	for (int i = 0; i < n; i++){
		if (arr[i] == target ){
			return 1;
		}
	}
}

int main () {
	int data [] = {10, 20, 30, 40};
	int n = sizeof(data) / sizeof(data[0]);
	int target = 20;
	
	int result = linearSearch(data, n, target);
	
	if (result != -1){
		printf("Data ditemukan di index %d\n", result);
	}
	else{
		printf("Data tidak ditemukan\n");
	}
return 0;
}
