#include <stdio.h>
#include "../Header/register.h"

// Fungsi sederhana untuk menyalin string
void stringCopy(char *dest, const char *src) {
    while ((*dest++ = *src++) != '\0');
}

// Registrasi pengguna dengan meminta input di dalam fungsi
int registerUser(TabUser *list) {
    char username[50], password[50];
    int money;

    printf("Masukkan username: ");
    readInput(username, 50);
    printf("Masukkan password: ");
    readInput(password, 50);
    printf("Masukkan jumlah uang: ");
    scanf("%d", &money);
    getchar(); // Membersihkan buffer input

    if (findUser(list, username) != -1) {
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
        return 0;
    }

    if (list->Neff >= 100) { // Maksimum jumlah pengguna, bisa diubah sesuai kebutuhan
        printf("Register gagal. Kapasitas pengguna sudah penuh.\n");
        return 0;
    }

    stringCopy(list->TC[list->Neff].name, username);
    stringCopy(list->TC[list->Neff].password, password);
    list->TC[list->Neff].money = money;
    list->Neff++;
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    return 1;
}
