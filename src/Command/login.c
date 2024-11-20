#include <stdio.h>
#include "../Header/login.h"


// Fungsi Login
int login(TabUser list, User *currentUser) { // Login pengguna dengan loop untuk input ulang
    char username[50], password[50];
    int index;

    if (currentUser != NULL) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser->name);
        return -1; // Tidak perlu login
    }

    while (1) {
        // Input username
        printf("Masukkan username: ");
        if (!readInput(username, 50)) continue; // Ulang jika input gagal

        // Input password
        printf("Masukkan password: ");
        if (!readInput(password, 20)) continue; // Ulang jika input gagal
        int passLen = strLength(password);
        if (passLen < 6 || passLen > 20) {
            printf("Password tidak valid! Panjang password harus 6-20 karakter.\n");
            continue;
        }

        // Validasi username dan password
        index = IndexUserInFile(list, username);
        if (index != -1 && isStrEqual(list.TC[index].password, password)) {
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
            return index; // Return indeks user
        } else {
            printf("Username atau password salah. Coba lagi.\n");
        }
    }
}