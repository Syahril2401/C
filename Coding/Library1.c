#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOKS 1000
#define	MAX_PATRONS 500
#define	MAX_TITTLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_GENRE_LENGTH 30
#define MAX_NAME_LENGTH 50
#define	LATE_FEE_PER_DAY 2.0
#define MAX_DAYS_LATE 30


//struktur tanggal
typedef struct {
	int day;
	int month;
	int year;
} Date;

//struktur buku
typedef struct {
	int bookID;
	char tittle[MAX_TITTLE_LENGTH];
	char author[MAX_AUTHOR_LENGTH];
	char genre[MAX_GENRE_LENGTH];
	int isAvaliable;
} Book;

//struktur patron
typedef struct {
	int patronID;
	char name[MAX_NAME_LENGTH];
} Patron;

//struktur peminjaman
typedef struct {
	int bookID;
	int patronID;
	Date borrowDate;
	Date dueDate;
	Date returnDate;
} Borrowing;

//fungsi utk hitung selisih hari antara 2 tanggal
int daysDifference(Date date1, Date date2) {
	//konversi tanggal ke time_t
	struct tm tm1 = {0}, tm2 = {0};
	tm1.tm_year = date1.year - 1900;
	tm1.tm_mon = date1.month - 1;
	tm1.tm_mday = date1.day;
	
	tm2.tm_year = date2.year - 1900;
	tm2.tm_mon = date2.month - 1;
	tm2.tm_mday = date2.day;
	
	time_t t1 = mktime(&tm1);
	time_t t2 = mktime(&tm2);
	
	//hitung selisih detik dan konversi ke hari
	return (int)difftime(t2, t1) / (60 * 60 * 24);
}

//fungsi utk hitung denda keterlambatan
float calculateLateFee(Date returnDate, Date dueDate) {
	int daysLate = daysDifference(dueDate, returnDate);
	
	if (daysLate <= 0) {
		return 0.0; //gk kena denda
	}
	
	if (daysLate > MAX_DAYS_LATE) {
		daysLate = MAX_DAYS_LATE; //kasi batas perhitungan denda
	}
	
	return daysLate * LATE_FEE_PER_DAY;
}

//main fungsi
int main () {
	Date dueDate = {1, 5, 2023};
	Date returnDate = {3, 5, 2024};
	
	float lateFee = calculateLateFee(returnDate, dueDate);
	
	printf("Denda keterlambatan: $%.2f\n", lateFee);
	
	return 0;
}










