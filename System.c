#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "Function.c"

int main() {
    int choice;
    char str;
    int loggedInUserId = -1;
    bool status = true;
    struct user users[1] = {"user", "password"}; 
    struct hotel rooms[3] = {
            {101, 0, 0, 0, false}, 
            {102, 0, 0, 0, false}, 
            {103, 0, 0, 0, false}
        };
    int numUsers = 1; 
    int numRooms = 3;


    while (status){
        display();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (login(users, &loggedInUserId, numUsers) == 1) {
                printf("Login successful. Welcome!\n");
                // Display user menu
                while (status == true) {
                    displayUserMenu();
                    scanf("%d", &choice);
                    switch (choice) {
                    case 1:
                        printf("Book a Room\n");
                        bookRoom(rooms, numRooms);
                        break;
                    case 2:
                        printf("Cancel a Booking\n");
                        cancelBooking(rooms, numRooms);
                        break;
                    case 3:
                        printf("Check Room Status\n");
                        checkRoomStatus(rooms, numRooms);
                        break;
                    case 4:
                        printf("~LOGGED OUT~ Thank you!, See you Next time soon...\n");
                        status = false;
                        break;
                    default:
                        printf("Invalid choice! \n");
                        break;
                    }
                }
                } else {
                printf("\n Login failed. Please check your username and password.\n");
            }
            break;
        case 2:
            printf("\n Thank you!, See you Next time soon...\n");
            status = false;
            return 1;
        default:
            printf("\n Invalid choice! Try Again... \n");
            break;
        }
    }


    return 0;
}
