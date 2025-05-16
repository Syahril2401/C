#include <stdio.h>
#include <string.h>

#define MAX_SEATS 50
#define MAX_NAME_LENGTH 20

typedef struct {
    int seatNumber;
    char name[MAX_NAME_LENGTH + 1];
} Seat;

Seat seats[MAX_SEATS];

// Initialize seats
void initializeSeats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        strcpy(seats[i].name, ""); // Empty name means the seat is vacant
    }
}

// Display seat map
void displaySeats() {
    printf("Seat Map:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        // If the seat is occupied (name is not empty), show "X"
        if (strlen(seats[i].name) > 0) {
            printf("X ");
        } else {
            printf("%d ", seats[i].seatNumber); // If vacant, show the seat number
        }
        // Add a new line after every 10 seats
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}


// Make a reservation
void makeReservation() {
    int seatNumber;
    char name[MAX_NAME_LENGTH + 1];

    printf("Enter your name (max 20 characters): ");
    scanf("%s", name);
    if (strlen(name) > MAX_NAME_LENGTH) {
        printf("Name is too long!\n");
        return;
    }

    printf("Enter seat number (1-50): ");
    scanf("%d", &seatNumber);
    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (strlen(seats[seatNumber - 1].name) > 0) {
        printf("Seat is already taken!\n");
    } else {
        strcpy(seats[seatNumber - 1].name, name);
        printf("Reservation successful!\n");
    }
}

// Cancel a reservation
void cancelReservation() {
    int seatNumber;

    printf("Enter seat number to cancel (1-50): ");
    scanf("%d", &seatNumber);
    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (strlen(seats[seatNumber - 1].name) > 0) {
        strcpy(seats[seatNumber - 1].name, "");
        printf("Reservation canceled!\n");
    } else {
        printf("Seat is already vacant!\n");
    }
}

// Save to text file
void saveToFile() {
    FILE *file = fopen("seats.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < MAX_SEATS; i++) {
        fprintf(file, "%d %s\n", seats[i].seatNumber, seats[i].name);
    }

    fclose(file);
    printf("Data saved to seats.txt\n");
}

// Load from text file
void loadFromFile() {
    FILE *file = fopen("seats.txt", "r");
    if (!file) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    // Read each line from the file
    int seatNumber;
    char name[MAX_NAME_LENGTH + 1];
    while (!feof(file)) {
        // Read seat number and name (if present)
        char line[50]; // Buffer to read the whole line
        if (fgets(line, sizeof(line), file)) {
            if (sscanf(line, "%d %[^\n]", &seatNumber, name) == 2) {
                // Valid seat number and name
                if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
                    strcpy(seats[seatNumber - 1].name, name);
                }
            } else if (sscanf(line, "%d", &seatNumber) == 1) {
                // Seat number exists, but no name (vacant seat)
                if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
                    strcpy(seats[seatNumber - 1].name, ""); // Ensure seat is vacant
                }
            }
        }
    }

    fclose(file);
    printf("Data loaded from seats.txt\n");
}



// Menu
void menu() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display seats\n");
        printf("2. Make reservation\n");
        printf("3. Cancel reservation\n");
        printf("4. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displaySeats(); break;
            case 2: makeReservation(); break;
            case 3: cancelReservation(); break;
            case 4: saveToFile(); printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
}

int main() {
    initializeSeats();
    loadFromFile();
    menu();
    return 0;
}

