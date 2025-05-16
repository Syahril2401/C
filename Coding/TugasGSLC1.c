#include <stdio.h>

int main() {
    
    double pendapatan_bulanan = 10000.0;
    double total_pengeluaran = 6500.0;
    int hari_dalam_bulan = 30;

    
    double sisa_dana = pendapatan_bulanan - total_pengeluaran;

    
    double rata_rata_pengeluaran_harian = total_pengeluaran / hari_dalam_bulan;

    
    printf("Total Bulanan: $%.2f\n", total_pengeluaran);
    printf("Sisa Dana Pengeluaran: $%.2f\n", sisa_dana);
    printf("Rata-Rata Pengeluaran Harian: $%.2f\n", rata_rata_pengeluaran_harian);

    return 0;
}

