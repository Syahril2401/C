#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struktur Data
typedef struct {
    char accountID[50];
    char name[100];
    char status[20];
} Account;

typedef struct {
    int menuItemID;
    char itemName[100];
    float price;
} MenuItem;

typedef struct {
    int orderID;
    int menuItemID;
    char customerID[50];
    char paymentStatus[20];
    char orderStatus[20];
} Order;

// Fungsi untuk Menyimpan Data ke File
void SaveAccountToFile(Account account) {
    FILE *file = fopen("accounts.txt", "a");
    if (file == NULL) {
        printf("Error opening accounts file.\n");
        return;
    }
    fprintf(file, "%s,%s,%s\n", account.accountID, account.name, account.status);
    fclose(file);
}

void SaveMenuToFile(MenuItem menuItem) {
    FILE *file = fopen("menu.txt", "a");
    if (file == NULL) {
        printf("Error opening menu file.\n");
        return;
    }
    fprintf(file, "%d,%s,%.2f\n", menuItem.menuItemID, menuItem.itemName, menuItem.price);
    fclose(file);
}

void SaveOrderToFile(Order order) {
    FILE *file = fopen("orders.txt", "a");
    if (file == NULL) {
        printf("Error opening orders file.\n");
        return;
    }
    fprintf(file, "%d,%d,%s,%s,%s\n", order.orderID, order.menuItemID, order.customerID, order.paymentStatus, order.orderStatus);
    fclose(file);
}

// Fungsi Registrasi Akun
void AccountRegistration() {
    Account account;
    printf("Enter Account ID: ");
    scanf("%s", account.accountID);
    printf("Enter Name: ");
    getchar();  // Consume newline
    fgets(account.name, sizeof(account.name), stdin);
    account.name[strcspn(account.name, "\n")] = '\0';  // Remove newline character
    strcpy(account.status, "Unvalidated");

    SaveAccountToFile(account);
    printf("Account created successfully and saved to file.\n");
}

void ValidateAccount() {
    char accountID[50];
    printf("Enter Account ID to Validate: ");
    scanf("%s", accountID);

    FILE *file = fopen("accounts.txt", "r");
    FILE *tempFile = fopen("accounts_temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error processing accounts file.\n");
        return;
    }

    char line[200];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        Account account;
        sscanf(line, "%[^,],%[^,],%s", account.accountID, account.name, account.status);
        if (strcmp(account.accountID, accountID) == 0) {
            found = 1;
            strcpy(account.status, "Validated");
        }
        fprintf(tempFile, "%s,%s,%s\n", account.accountID, account.name, account.status);
    }
    fclose(file);
    fclose(tempFile);

    // Replace old file with updated file
    remove("accounts.txt");
    rename("accounts_temp.txt", "accounts.txt");

    if (found) {
        printf("Account validated successfully.\n");
    } else {
        printf("Account not found.\n");
    }
}

// Fungsi Login
int Login() {
    char accountID[50];
    printf("Enter Account ID to Login: ");
    scanf("%s", accountID);

    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        printf("No accounts found. Please register first.\n");
        return 0;
    }

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        Account account;
        sscanf(line, "%[^,],%[^,],%s", account.accountID, account.name, account.status);
        if (strcmp(account.accountID, accountID) == 0) {
            if (strcmp(account.status, "Validated") == 0) {
                printf("Login successful. Welcome, %s!\n", account.name);
                fclose(file);
                return 1;
            } else {
                printf("Account not validated. Please validate your account first.\n");
                fclose(file);
                return 0;
            }
        }
    }
    fclose(file);
    printf("Account not found. Please register first.\n");
    return 0;
}

// Fungsi Pengelolaan Menu
void AddMenuItem() {
    MenuItem menuItem;
    printf("Enter Menu Item ID: ");
    scanf("%d", &menuItem.menuItemID);
    printf("Enter Item Name: ");
    getchar();  // Consume newline
    fgets(menuItem.itemName, sizeof(menuItem.itemName), stdin);
    menuItem.itemName[strcspn(menuItem.itemName, "\n")] = '\0';  // Remove newline character
    printf("Enter Price: ");
    scanf("%f", &menuItem.price);

    SaveMenuToFile(menuItem);
    printf("Menu item added successfully and saved to file.\n");
}

void ViewMenu() {
    FILE *file = fopen("menu.txt", "r");
    if (file == NULL) {
        printf("No menu available.\n");
        return;
    }

    printf("Menu:\n");
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        MenuItem menuItem;
        sscanf(line, "%d,%[^,],%f", &menuItem.menuItemID, menuItem.itemName, &menuItem.price);
        printf("ID: %d, Item: %s, Price: %.2f\n", menuItem.menuItemID, menuItem.itemName, menuItem.price);
    }
    fclose(file);
}

// Fungsi Pemesanan
void OrderFood() {
    Order order;
    printf("Enter Order ID: ");
    scanf("%d", &order.orderID);
    printf("Enter Menu Item ID: ");
    scanf("%d", &order.menuItemID);
    printf("Enter Customer ID: ");
    scanf("%s", order.customerID);

    FILE *file = fopen("menu.txt", "r");
    if (file == NULL) {
        printf("Menu not available.\n");
        return;
    }

    char line[200];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        MenuItem menuItem;
        sscanf(line, "%d,%[^,],%f", &menuItem.menuItemID, menuItem.itemName, &menuItem.price);
        if (menuItem.menuItemID == order.menuItemID) {
            found = 1;
            break;
        }
    }
    fclose(file);

    if (found) {
        strcpy(order.paymentStatus, "Unpaid");
        strcpy(order.orderStatus, "Pending");
        SaveOrderToFile(order);
        printf("Order placed successfully and saved to file.\n");
    } else {
        printf("Menu item not found.\n");
    }
}

void Payment() {
    int orderID;
    printf("Enter Order ID to Make Payment: ");
    scanf("%d", &orderID);

    FILE *file = fopen("orders.txt", "r");
    FILE *tempFile = fopen("orders_temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        if (file) fclose(file);
        if (tempFile) fclose(tempFile);
        return;
    }

    char line[200];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        Order order;
        int parsed = sscanf(line, "%d,%d,%49[^,],%19[^,],%19s", 
                            &order.orderID, &order.menuItemID, order.customerID, order.paymentStatus, order.orderStatus);
        if (parsed != 5) {
            printf("Invalid line format: %s", line);
            continue;
        }

        if (order.orderID == orderID) {
            found = 1;
            strcpy(order.paymentStatus, "Paid");
        }
        fprintf(tempFile, "%d,%d,%s,%s,%s\n", order.orderID, order.menuItemID, order.customerID,
                order.paymentStatus, order.orderStatus);
    }
    fclose(file);
    fclose(tempFile);

    if (found) {
        if (remove("orders.txt") != 0) {
            perror("Error removing orders.txt");
            return;
        }
        if (rename("orders_temp.txt", "orders.txt") != 0) {
            perror("Error renaming temporary file");
            return;
        }
        printf("Payment successful.\n");
    } else {
        printf("Order not found.\n");
        remove("orders_temp.txt"); // Hapus file sementara jika tidak digunakan
    }
}


// Fungsi Utama
int main() {
    int choice;
    int loggedIn = 0;

    printf("Welcome to Orderly!!!\n");

    while (1) {
        if (!loggedIn) {
            printf("\n1. Register Account\n");
            printf("2. Validate Account\n");
            printf("3. Login\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    AccountRegistration();
                    break;
                case 2:
                    ValidateAccount();
                    break;
                case 3:
                    loggedIn = Login();
                    break;
                case 4:
                    printf("Thank you for using the Restaurant Ordering System!\n");
                    exit(0);
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } else {
            printf("\n1. Add Menu Item\n");
            printf("2. View Menu\n");
            printf("3. Place Order\n");
            printf("4. Make Payment\n");
            printf("5. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    AddMenuItem();
                    break;
                case 2:
                    ViewMenu();
                    break;
                case 3:
                    OrderFood();
                    break;
                case 4:
                    Payment();
                    break;
                case 5:
                    loggedIn = 0;
                    printf("Logged out successfully.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}

