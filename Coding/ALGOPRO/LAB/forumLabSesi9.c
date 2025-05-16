#include <stdio.h>

//Fungsi untuk Binary Seacrh
int binarySearch(int arr[], int size, int target){
	int left;//inisial index dari kiri
	int right = size - 1;//inisial index dari kanan
	
	//selama index kiri tidak melebihi index kanan
	while(left <= right) {
		int mid = left + (right - left) / 2;//Menghitung index tengah
		//jika elemen di tengah sama dengan target
		if (arr[mid] == target){
			return mid;//Mengembalikan index tengah
		}
		//jika elemen di tengah lebih kecil dari target
		else if (arr[mid] < target){
			left = mid + 1;//memindah index dari kiri ke kanan
		}
		//jika elemen di tengah lebih besar dari target 
		else {
			right = mid - 1;// memindahkan index dari kaanan ke kiri
		}
	}
	return -1;//kembalikan nilai 
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // Array yang sudah terurut
    int size = sizeof(arr) / sizeof(arr[0]); // Hitung ukuran array
    int target; // Variabel untuk menyimpan nilai target

    
    printf("Masukkan angka yang ingin dicari: ");
    scanf("%d", &target); // Input dari pengguna

    // Panggil fungsi binarySearch
    int result = binarySearch(arr, size, target);

    // Cek hasil pencarian
    if (result != -1) {
        printf("Elemen %d ditemukan pada indeks %d\n", target, result);
    } else {
        printf("Elemen %d tidak ditemukan\n", target);
    }

    return 0; // program berakhir
}
