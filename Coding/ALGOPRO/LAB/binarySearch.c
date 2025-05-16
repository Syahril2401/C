#include <stdio.h>

int binarySearch(int arr[], int low, int high; int target){
//	int left = 0;
//	int right = n - 1;

	while (low <= high) {
		int mid = low + (high -low) / 2;
		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target){
			low mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

void bubleSort(int arr[], int n){
	for (int i; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main () {
	int data [] = {40, 20, 30, 10, 50};
	int n = sizeof(data) / sizeof(data[0]);
	int target = 30;
	
	printf("Data sebelum diurutkan\n");
	for(int i = 0; i < n; i++){
		printf("%d", data);
	}
	
	printf("\n")
	
	int result = linearSearch(data, n, target);
	
	if (result != -1){
		printf("Data ditemukan di index %d\n", result);
	}
	else{
		printf("Data tidak ditemukan\n");
	}
return 0;
}
