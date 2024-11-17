#include <stdio.h>
#include "user.h"

int main() {
    UserList userList;
    User *currentUser = NULL; // Pointer untuk pengguna yang sedang login
    initUserList(&userList);  // Inisialisasi daftar pengguna

    char command[10];
    char username[MAX_LEN], password[MAX_LEN];

    while (1) {
        // Minta input command dari pengguna
        printf("\nCommand (REGISTER, LOGIN, LOGOUT, EXIT): ");
        scanf("%s", command);

        if (stringCompare(command, "REGISTER")) {
            // Proses command REGISTER
            printf("Username: ");
            scanf("%s", username);
            printf("Password: ");
            scanf("%s", password);
            registerUser(&userList, username, password);

        } else if (stringCompare(command, "LOGIN")) {
            // Proses command LOGIN
            printf("Username: ");
            scanf("%s", username);
            printf("Password: ");
            scanf("%s", password);
            currentUser = login(&userList, username, password, currentUser);

        } else if (stringCompare(command, "LOGOUT")) {
            // Proses command LOGOUT
            logout(&currentUser);

        } else if (stringCompare(command, "EXIT")) {
            // Proses command EXIT
            printf("Keluar dari program. Dadah ^_^\n");
            break;

        } else {
            printf("Command tidak dikenali.\n");
        }
    }

    return 0;
}
