#include <stdio.h>

int main() {
    int nA, nB, k;
    float RataRataA, RataRataB;
    
    //nilai kelas A
    printf("Masukkan jumlah siswa kelas A: ");
    scanf("%d", &nA);
    float nilaiSiswaA[nA];
    
    printf("Masukkan nilai siswa kelas A: ");
    float totalNilaiA = 0; 
    for(int i = 0; i < nA; i++) { 
        scanf("%f", &nilaiSiswaA[i]);
        totalNilaiA += nilaiSiswaA[i];
    }
    RataRataA = totalNilaiA / nA;
    
    //nilai kelas B
    printf("Masukkan jumlah siswa kelas B: "); 
    scanf("%d", &nB);
    float nilaiSiswaB[nB];
    
    printf("Masukkan nilai siswa kelas B: ");
    float totalNilaiB = 0; 
    for(int j = 0; j < nB; j++) {
        scanf("%f", &nilaiSiswaB[j]);
        totalNilaiB += nilaiSiswaB[j];
    }
    RataRataB = totalNilaiB / nB;
    
    //memilih kelas
    int pilihan;
    printf("Pilih arah pemindahan: 1 (A ke B), 2 (B ke A): ");
    scanf("%d", &pilihan);
    
    //jumlah siswa yang dipindah
    printf("Masukkan jumlah siswa yang dipindahkan: ");
    scanf("%d", &k);
    
    float totalNilaiDipindahkan = 0; 
    
    if (pilihan == 1) {
        printf("Masukkan nilai siswa yang akan dipindahkan dari kelas A: \n");
        for(int i = 0; i < k; i++) {
            float nilai;
            scanf("%f", &nilai);
            totalNilaiDipindahkan += nilai;
        }
        //hitung rata-rata nilai kelas A baru
        float RataRataBaruA = (totalNilaiA - totalNilaiDipindahkan) / (nA - k);
        
        if (RataRataBaruA >= RataRataA) {
            totalNilaiB += totalNilaiDipindahkan;
            float RataRataBaruB = totalNilaiB / (nB + k);
            
            printf("Rata-rata baru kelas A: %.2f\n", RataRataBaruA);
            printf("Rata-rata baru kelas B: %.2f\n", RataRataBaruB);
        } else {
            printf("Tidak dapat memindahkan siswa tanpa mengurangi rata-rata kelas A.\n");
        }
        
    } else if (pilihan == 2) {
        printf("Masukkan nilai siswa yang akan dipindahkan dari kelas B: \n"); 
        for(int i = 0; i < k; i++) {
            float nilai;
            scanf("%f", &nilai);
            totalNilaiDipindahkan += nilai;
        }
        //hitung rata-rata nilai kelas B baru
        float RataRataBaruB = (totalNilaiB - totalNilaiDipindahkan) / (nB - k);
        
        if (RataRataBaruB >= RataRataB) {
            totalNilaiA += totalNilaiDipindahkan;
            float RataRataBaruA = totalNilaiA / (nA + k);
            
            printf("Rata-rata baru kelas B: %.2f\n", RataRataBaruB);
            printf("Rata-rata baru kelas A: %.2f\n", RataRataBaruA);
        } else {
            printf("Tidak dapat memindahkan siswa tanpa mengurangi rata-rata Kelas B.\n");
        }
    } else {
        printf("Pilihan tidak valid.\n");
    }

    return 0; 
}

