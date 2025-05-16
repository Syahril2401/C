#include <stdio.h>

int hitung_fpb(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return hitung_fpb(num2, num1 % num2);
}


int hitung_fpb_array(int angka[], int jumlah) {
    int fpb_akhir = angka[0];
    for (int i = 1; i < jumlah; i++) {
        fpb_akhir = hitung_fpb(fpb_akhir, angka[i]);
        if (fpb_akhir == 1) {
            return 1; 
        }
    }
    return fpb_akhir;
}

int main() {
    int jumlah_TC; 
    scanf("%d", &jumlah_TC);
    
    for (int num_case = 1; num_case <= jumlah_TC; num_case++) {
        int jumlah_angka; 
        scanf("%d", &jumlah_angka);
        
        int daftar_angka[jumlah_angka]; 
        for (int i = 0; i < jumlah_angka; i++) {
            scanf("%d", &daftar_angka[i]); 
        }
        
        int hasil_fpb = hitung_fpb_array(daftar_angka, jumlah_angka);
        printf("Case #%d: %d\n", num_case, hasil_fpb);
    }

    return 0;
}
