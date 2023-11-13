#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

typedef union {
    int flag;
    struct {
        unsigned int active : 1;
    } bits;
} UserFlag;

typedef struct {
    char username[50];
    char password[50];
    UserFlag activeFlag; 
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser();
void loginUser();

int main() {
    int choice;
    do {
        printf("1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User database is full. Cannot register more users.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    printf("Enter 1 for active or 0 for inactive: ");
    scanf("%d", &newUser.activeFlag.flag);

    users[userCount] = newUser;
    userCount++;

    printf("Registration successful!\n");
}

void loginUser() {
    char username[50];
    char password[50];
    int loggedIn = 0;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0 &&
            users[i].activeFlag.bits.active) {
            printf("Login successful!\n");
            loggedIn = 1;
            break;
        }
    }

    if (!loggedIn) {
        printf("Login failed. Please check your credentials or account status.\n");
    }
}
