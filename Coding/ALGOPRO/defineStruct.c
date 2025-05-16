#include <stdio.h>
#include <string.h>
#include <time.h>  

struct TanggalLahir {
    int tanggal;
    int bulan;
    int tahun;
};

struct Alamat {
    char jalan[50];
    int nomor;
    char kota[50];
    char provinsi[50];
};

struct Mahasiswa {
    char nama[50];
    int NIM;
    struct Alamat alamat;
    struct TanggalLahir tgl;    
};

int main() {
    struct Mahasiswa mahasiswa[5];
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int tahun_sekarang = tm.tm_year + 1900;  
    
    for(int i = 0; i < 5; i++) {
        printf("Masukkan detail mahasiswa %d:\n", i + 1);
        
        printf("NIM mahasiswa: ");
        scanf("%d", &mahasiswa[i].NIM);
        
        printf("Nama: ");
        scanf(" %[^\n]", mahasiswa[i].nama);
        
        printf("Alamat\n");
        printf("  Jalan: ");
        scanf(" %[^\n]", mahasiswa[i].alamat.jalan);
        
        printf("  Nomor: ");
        scanf("%d", &mahasiswa[i].alamat.nomor);
        
        printf("  Kota: ");
        scanf(" %[^\n]", mahasiswa[i].alamat.kota);
        
        printf("  Provinsi: ");
        scanf(" %[^\n]", mahasiswa[i].alamat.provinsi);

        
        int valid_tanggal = 0;
        while (!valid_tanggal) {
            printf("Tanggal Lahir:\n");
            
            printf("  Tanggal (1-31): ");
            scanf("%d", &mahasiswa[i].tgl.tanggal);
            
            printf("  Bulan (1-12): ");
            scanf("%d", &mahasiswa[i].tgl.bulan);
            
            printf("  Tahun (<= %d): ", tahun_sekarang);
            scanf("%d", &mahasiswa[i].tgl.tahun);
            
            
            if (mahasiswa[i].tgl.tanggal >= 1 && mahasiswa[i].tgl.tanggal <= 31 &&
                mahasiswa[i].tgl.bulan >= 1 && mahasiswa[i].tgl.bulan <= 12 &&
                mahasiswa[i].tgl.tahun <= tahun_sekarang) {
                
                valid_tanggal = 1;  
            } else {
                printf("Input tanggal, bulan, atau tahun tidak valid. Coba lagi.\n");
            }
        }

        printf("\n");
    }

    
    printf("\nData Mahasiswa:\n");
    for (int i = 0; i < 5; i++) {
        printf("Mahasiswa %d:\n", i + 1);
        printf("  NIM: %d\n", mahasiswa[i].NIM);
        printf("  Nama: %s\n", mahasiswa[i].nama);
        printf("  Alamat: Jalan %s, No. %d, Kota %s, Provinsi %s\n", 
               mahasiswa[i].alamat.jalan, 
               mahasiswa[i].alamat.nomor, 
               mahasiswa[i].alamat.kota, 
               mahasiswa[i].alamat.provinsi);
        printf("  Tanggal Lahir: %02d-%02d-%d\n\n", 
               mahasiswa[i].tgl.tanggal, 
               mahasiswa[i].tgl.bulan, 
               mahasiswa[i].tgl.tahun);
    }

    return 0;
}

