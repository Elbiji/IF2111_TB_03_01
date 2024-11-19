#include <stdio.h>
#include "../Header/login.h"

// Membandingkan dua string secara manual
int stringCompare(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

// Mencari indeks pengguna berdasarkan username
int findUser(TabUser *list, char *username) {
    for (int i = 0; i < list->Neff; i++) {
        if (stringCompare(list->users[i].name, username)) {
            return i;
        }
    }
    return -1;
}

// Login pengguna dengan loop untuk input ulang
int login(TabUser *list, User *currentUser) {
    char username[50], password[50];
    int index;

    if (currentUser == NULL) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser->name);
        return -1; // Indikasi tidak perlu login
    }

    while (1) { // Looping terus hingga login berhasil atau pengguna menyerah
        printf("Masukkan username: ");
        if (!readInput(username, 50)) continue; // Jika input gagal, ulangi
        printf("Masukkan password: ");
        if (!readInput(password, 50)) continue;

        index = findUser(list, username);
        if (index != -1 && stringCompare(list->users[index].password, password)) {
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
            return index; // Kembalikan indeks user
        } else {
            printf("Username atau password salah. Coba lagi.\n");
        }
    }
}

// Membaca input dengan batas panjang tertentu
boolean readInput(char *buffer, int maxLen) {
    int i = 0;
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < maxLen - 1) {
            buffer[i++] = ch;
        } else {
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Input terlalu panjang! Maksimum %d karakter.\n", maxLen - 1);
            return false;
        }
    }
    buffer[i] = '\0';
    return true;
}
