#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

struct hotel{
    /* data */
    int roomnum;
    int checkin;
    int checkout;
    int price;
    bool isBooked;
};


struct Customer{
    /* data */
    char name[60];
    int age;
    char gender;
};

struct user{
    /* data */
    char username[60];
    char password[60];
};

void display() {
    printf("~Book Hotel Room~ \n");
    printf("1. Log In \n");
    printf("2. Exit \n");
}

void displayUserMenu() {
    printf("\n User Menu \n");
    printf("1. Book a Room\n");
    printf("2. Cancel a Booking\n");
    printf("3. Check Room Status\n");
    printf("4. Logout\n");
    printf("Enter your choice: ");
}

// struct login (struct user users[], int *loggedInUserId, int numUsers) {
//     char username[50];
//     char password[50];
//     printf("enter username: ");
//     scanf("%s", username);
//     printf("enter password: ");
//     scanf("%s", password);
//         for (int i = 0; i < numUsers; i++) {
//         if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
//             *loggedInUserId = i;
//             return;
//         }
//     }

//     *loggedInUserId = -1;
// }

int login(struct user users[], int *loggedInUserId, int numUsers) {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%49s", username); // "%49s" To prevent buffer overflow

    printf("Enter password: ");
    scanf("%49s", password); // "%49s" To prevent buffer overflow

    // getpass("Enter password: ");

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            *loggedInUserId = i;
            return 1; // Return 1 indicate's successful
        }
    }

    *loggedInUserId = -1;
    return 0; // Return 0 indicate's failed
}

void bookRoom(struct hotel rooms[], int numRooms) {
    int roomChoice;
    printf("Available rooms: \n");
    for (int i = 0; i < numRooms; i++) {
        if (!rooms[i].isBooked) {
            printf("%d. Room %d\n", i + 1, rooms[i].roomnum);
        }
    }
    printf("Enter your choice: ");
    scanf("%d", &roomChoice);
    roomChoice--; // Adjust for 0-based indexing
    if (roomChoice >= 0 && roomChoice < numRooms && !rooms[roomChoice].isBooked) {
        rooms[roomChoice].isBooked = true;
        printf("Room %d booked successfully.\n", rooms[roomChoice].roomnum);
    } else {
        printf("Invalid choice or room already booked.\n");
    }
}

void cancelBooking(struct hotel rooms[], int numRooms) {
    int roomChoice;
    printf("Booked rooms: \n");
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].isBooked) {
            printf("%d. Room %d\n", i + 1, rooms[i].roomnum);
        }
    }
    printf("Enter your choice: ");
    scanf("%d", &roomChoice);
    roomChoice--; // Adjust for 0-based indexing
    if (roomChoice >= 0 && roomChoice < numRooms && rooms[roomChoice].isBooked) {
        rooms[roomChoice].isBooked = false;
        printf("Room %d cancelled successfully.\n", rooms[roomChoice].roomnum);
    } else {
        printf("Invalid choice or room not booked.\n");
    }
}

void checkRoomStatus(struct hotel rooms[], int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: %s\n", rooms[i].roomnum, rooms[i].isBooked ? "Booked" : "Available");
    }
}
