#include <stdio.h>
#include "../Header/register.h"

// Implementasi registrasi pengguna
int registerUser(TabUser *list, char *username, char *password, int money) {
    if (findUser(list, username) != -1) {
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
        return 0;
    }

    if (list->Neff >= MAX_USERS) {
        printf("Register gagal. Kapasitas pengguna sudah penuh.\n");
        return 0;
    }

    stringCopy(list->users[list->Neff].name, username);
    stringCopy(list->users[list->Neff].password, password);
    list->users[list->Neff].money = money;
    list->Neff++;
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    return 1;
}
