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

// Login pengguna
User* login(TabUser *list, char *username, char *password, User *currentUser) {
    if (currentUser != NULL) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser->name);
        return currentUser;
    }

    int index = findUser(list, username);
    if (index == -1 || !stringCompare(list->users[index].password, password)) {
        printf("Username atau password salah.\n");
        return NULL;
    }

    printf("Anda telah login ke PURRMART sebagai %s.\n", username);
    return &list->users[index];
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

// Mendapatkan ID (indeks) pengguna yang sedang login
int getUserID(User *currentUser, TabUser *list) {
    if (currentUser == NULL) return -1;
    return findUser(list, currentUser->name);
}

// Mengecek apakah ada pengguna yang sedang login
boolean isUserLoggedIn(User *currentUser) {
    return currentUser != NULL;
}
