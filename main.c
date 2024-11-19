#include <stdio.h>
#include <string.h>
#include "../Header/login.h"
#include "../Header/logout.h"
#include "../Header/register.h"
#include "../ADT/boolean/boolean.h"

// Fungsi sederhana untuk menyalin string
void stringCopy(char *dest, const char *src) {
    while ((*dest++ = *src++) != '\0');
}

int main() {
    TabUser userList = { .Neff = 0 };
    User *currentUser = NULL;
    char username[MAX_LEN], password[MAX_LEN];
    int choice, money;

    while (1) {
        printf("\n--- PURRMART ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Logout\n");
        printf("4. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar(); // Untuk membersihkan newline dari buffer input

        switch (choice) {
            case 1: // Register
                printf("Masukkan username: ");
                readInput(username, MAX_LEN);
                printf("Masukkan password: ");
                readInput(password, MAX_LEN);
                printf("Masukkan jumlah uang: ");
                scanf("%d", &money);
                getchar();
                registerUser(&userList, username, password, money);
                break;
            case 2: // Login
                printf("Masukkan username: ");
                readInput(username, MAX_LEN);
                printf("Masukkan password: ");
                readInput(password, MAX_LEN);
                currentUser = login(&userList, username, password, currentUser);
                break;
            case 3: // Logout
                logout(&currentUser);
                break;
            case 4: // Exit
                printf("Keluar dari program.\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
}
