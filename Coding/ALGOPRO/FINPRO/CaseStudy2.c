#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.bin"

struct Item {
    int id;
    char item_name[50];
    float price;
};

struct Supplier {
    int id;
    char name[50];
    char phone_number[20];
};

struct Inventory {
    char item_id[25];
    char supplier_id[25];
    char item_name[50];
    float price;
    int quantity;
    float sales;
};

void insertRecord();
void showRecords();
void selectRecord();
void deleteRecord();
void updateRecord();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("INVENTORY SYSTEM\n");
        printf("INVENTORY DATA MAIN MENU\n");
        printf("\n");
        printf("What you wanna do?\n");
        printf("======================\n");
        printf("|| 1. Insert Record ||\n");
        printf("|| 2. Show Records  ||\n");
        printf("|| 3. Select Data   ||\n");
        printf("|| 4. Delete Record || \n");
        printf("|| 5. Update Record ||\n");
        printf("|| 6. Exit	    ||\n");
        printf("======================\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                insertRecord();
                break;
            case 2:
                showRecords();
                break;
            case 3:
                selectRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                updateRecord();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
}

void insertRecord() {
    struct Inventory record;
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        perror("Error opening file");
        return;
    }

   printf("Enter Item ID (e.g., A1): ");
    fgets(record.item_id, sizeof(record.item_id), stdin);
    record.item_id[strcspn(record.item_id, "\n")] = 0; 

    printf("Enter Supplier ID (e.g., S1): ");
    fgets(record.supplier_id, sizeof(record.supplier_id), stdin);
    record.supplier_id[strcspn(record.supplier_id, "\n")] = 0; 

    printf("Enter Item Name: ");
    fgets(record.item_name, sizeof(record.item_name), stdin);
    record.item_name[strcspn(record.item_name, "\n")] = 0; 

    printf("Enter Price: ");
    scanf("%f", &record.price);

    printf("Enter Quantity: ");
    scanf("%d", &record.quantity);
  
    record.sales = record.price * record.quantity;

    fwrite(&record, sizeof(struct Inventory), 1, file);
    fclose(file);

    printf("Record inserted successfully.\n");
}

void showRecords() {
    struct Inventory record;
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

	printf("--------------------------------------------------------------------------------------------");
    printf("\n%-15s %-15s %-20s %-15s %-15s %-15s\n", "Item ID", "SUPPLIER_ID", "ITEM_NAME", "PRICE", "QUANTITY", "SALES");
    printf("--------------------------------------------------------------------------------------------\n");
    while (fread(&record, sizeof(struct Inventory), 1, file)) {
       printf("%-15s %-15s %-20s %-15.2f %-15d %-15.2f\n",
       record.item_id, record.supplier_id, record.item_name, record.price, record.quantity, record.sales);
    }
    fclose(file);
}

void selectRecord() {
    char item_id[10];
    struct Inventory record;
    int found = 0;

    printf("Enter Item ID to search: ");
    fgets(item_id, sizeof(item_id), stdin);
    item_id[strcspn(item_id, "\n")] = 0; 

    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    while (fread(&record, sizeof(struct Inventory), 1, file)) {
        if (strcmp(record.item_id, item_id) == 0) {
            printf("Record Found:\n");
            printf("Item ID: %s\nSupplier ID: %s\nItem Name: %s\nPrice: %.2f\nQuantity: %d\nSales: %.2f\n",
                   record.item_id, record.supplier_id, record.item_name, record.price, record.quantity, record.sales);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
    fclose(file);
}

void deleteRecord() {
    char item_id[10];
    struct Inventory record;
    int found = 0;

    printf("Enter Item ID to delete: ");
    fgets(item_id, sizeof(item_id), stdin);
    item_id[strcspn(item_id, "\n")] = 0; 

    FILE *file = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.bin", "wb");
    if (!file || !temp) {
        perror("Error opening file");
        return;
    }

    while (fread(&record, sizeof(struct Inventory), 1, file)) {
        if (strcmp(record.item_id, item_id) == 0) {
            found = 1;
            printf("Record with Item ID '%s' deleted.\n", item_id);
        } else {
            fwrite(&record, sizeof(struct Inventory), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.bin", FILE_NAME);

    if (!found) {
        printf("Record with Item ID '%s' not found.\n", item_id);
    }
}


void updateRecord() {
    char item_id[10];
    struct Inventory record;
    int found = 0;

    printf("Enter Item ID to update: ");
    fgets(item_id, sizeof(item_id), stdin);
    item_id[strcspn(item_id, "\n")] = 0; 

    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    while (fread(&record, sizeof(struct Inventory), 1, file)) {
        if (strcmp(record.item_id, item_id) == 0) {
            found = 1;

            printf("Enter new Supplier ID: ");
            fgets(record.supplier_id, sizeof(record.supplier_id), stdin);
            record.supplier_id[strcspn(record.supplier_id, "\n")] = 0;

            printf("Enter new Item Name: ");
            fgets(record.item_name, sizeof(record.item_name), stdin);
            record.item_name[strcspn(record.item_name, "\n")] = 0;

            printf("Enter new Price: ");
            scanf("%f", &record.price);

            printf("Enter new Quantity: ");
            scanf("%d", &record.quantity);

            record.sales = record.price * record.quantity;

            fseek(file, -sizeof(struct Inventory), SEEK_CUR);
            fwrite(&record, sizeof(struct Inventory), 1, file);

            printf("Record with Item ID '%s' updated successfully.\n", item_id);
            break;
        }
    }

    if (!found) {
        printf("Record with Item ID '%s' not found.\n", item_id);
    }

    fclose(file);
}

