#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struktur data untuk menyimpan informasi buku
struct bookInfo {
    char bookId[25];
    char bookTitle[50];
    char authName[50];
    int yearPublished;
};

// Fungsi untuk menambahkan buku baru
void inputBook() {
    struct bookInfo book;
    FILE *file = fopen("books.dat", "ab");// Membuka file dalam mode append binary
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

// Input data buku dari pengguna
    printf("Enter Book ID: ");
    scanf("%s", book.bookId);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", book.bookTitle);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", book.authName);
    printf("Enter Year Published: ");
    scanf("%d", &book.yearPublished);

// Menyimpan data buku ke file
    fwrite(&book, sizeof(struct bookInfo), 1, file);
    fclose(file);
    printf("Book added successfully!\n");
}

// Fungsi untuk menampilkan daftar buku
void displayBooks() {
    struct bookInfo book;
    FILE *file = fopen("books.dat", "rb"); // Membuka file dalam mode read binary
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nList of Books:\n");
	// Membaca dan menampilkan data buku satu per satu
    while (fread(&book, sizeof(struct bookInfo), 1, file)) {
        printf("Book ID: %s\n", book.bookId);
        printf("Book Title: %s\n", book.bookTitle);
        printf("Author Name: %s\n", book.authName);
        printf("Year Published: %d\n", book.yearPublished);
        printf("-------------------------\n");
    }
    fclose(file);
}

// Fungsi untuk memperbarui data buku
void updateBook() {
    struct bookInfo book;
    char bookId[25];
    int found = 0;

    printf("Enter Book ID to update: ");
    scanf("%s", bookId);

    FILE *file = fopen("books.dat", "rb+");// Membuka file dalam mode read/write binary
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
// Mencari buku berdasarkan ID
    while (fread(&book, sizeof(struct bookInfo), 1, file)) {
        if (strcmp(book.bookId, bookId) == 0) { // ID cocok
            found = 1;
            // Input data baru
            printf("Enter new Book Title: ");
            scanf(" %[^\n]", book.bookTitle);
            printf("Enter new Author Name: ");
            scanf(" %[^\n]", book.authName);
            printf("Enter new Year Published: ");
            scanf("%d", &book.yearPublished);
            
            // Menulis ulang data buku yang diperbarui
            fseek(file, -sizeof(struct bookInfo), SEEK_CUR);
            fwrite(&book, sizeof(struct bookInfo), 1, file);
            printf("Book updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Book ID not found!\n");
    }
    fclose(file);
}

// Fungsi untuk menghapus buku berdasarkan ID
void deleteBook() {
    struct bookInfo book;
    char bookId[25];
    int found = 0;

    printf("Enter Book ID to delete: ");
    scanf("%s", bookId);

    FILE *file = fopen("books.dat", "rb"); // Membuka file utama
    FILE *tempFile = fopen("temp.dat", "wb"); // Membuka file sementara
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    // Menyalin data buku kecuali yang ingin dihapus
    while (fread(&book, sizeof(struct bookInfo), 1, file)) {
        if (strcmp(book.bookId, bookId) != 0) {
            fwrite(&book, sizeof(struct bookInfo), 1, tempFile);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);
    
    // Mengganti file lama dengan file baru
    remove("books.dat");
    rename("temp.dat", "books.dat");

    if (found) {
        printf("Book deleted successfully!\n");
    } else {
        printf("Book ID not found!\n");
    }
}

// Fungsi untuk mengurutkan buku berdasarkan judul
void bubbleSortBooks() {
    struct bookInfo books[100];
    int count = 0;
    FILE *file = fopen("books.dat", "rb"); // Membuka file untuk membaca semua data
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Membaca semua data buku ke array
    while (fread(&books[count], sizeof(struct bookInfo), 1, file)) {
        count++;
    }
    fclose(file);

    // Menggunakan bubble sort untuk mengurutkan array berdasarkan judul
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(books[j].bookTitle, books[j + 1].bookTitle) > 0) {
                struct bookInfo temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    // Menulis ulang data yang sudah diurutkan ke file
    file = fopen("books.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fwrite(books, sizeof(struct bookInfo), count, file);
    fclose(file);
}

// Fungsi utama
int main() {
    int pilihMenu;

    while (1) {
    	printf("============================\n");
        printf("||	Library Menu:		  ||\n");
        printf("||	1. Input Book		  ||\n");
        printf("||	2. Display Books	  ||\n");
        printf("||	3. Update Book		  ||\n");
        printf("||	4. Delete Book		  ||\n");
        printf("||	5. Sort Books by Title    ||\n");
        printf("||	6. Exit			  ||\n");	
        printf("============================\n");	
        printf("Enter your choice: ");
        scanf("%d", &pilihMenu);
        
        // Memanggil fungsi berdasarkan pilihan pengguna
        switch (pilihMenu) {
            case 1:
                inputBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                bubbleSortBooks();
                printf("Books sorted successfully!\n");
                break;
            case 6:
                printf("Exiting......\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
