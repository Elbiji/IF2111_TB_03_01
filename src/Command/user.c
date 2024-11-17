#include <stdio.h>
#include "user.h"

// Fungsi untuk membandingkan dua string
int stringCompare(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) { // Karakter tidak cocok
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0'); // Pastikan kedua string selesai
}

// Fungsi untuk menyalin string
void stringCopy(char *dest, char *src) {
    while (*src) {
        *dest = *src; // Salin karakter satu per satu
        dest++;
        src++;
    }
    *dest = '\0'; // Akhiri string dengan null terminator
}

// Inisialisasi daftar pengguna
void initUserList(UserList *list) {
    list->count = 0; // Set jumlah pengguna menjadi 0
}

// Cari pengguna berdasarkan username
int findUser(UserList *list, char *username) {
    for (int i = 0; i < list->count; i++) {
        if (stringCompare(list->users[i].name, username)) {
            return i; // Kembalikan indeks jika username ditemukan
        }
    }
    return -1; // Kembalikan -1 jika username tidak ditemukan
}

// Fungsi untuk register
int registerUser(UserList *list, char *username, char *password) {
    // Register gagal karena username sudah ada
    if (findUser(list, username) != -1) {
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
        return 0; // Registrasi gagal
    }

    // Cek apakah kapasitas maksimum pengguna sudah tercapai
    if (list->count >= MAX_USERS) {
        printf("Register gagal. Kapasitas pengguna sudah penuh.\n");
        return 0; // Registrasi gagal
    }

    // Register berhasil
    stringCopy(list->users[list->count].name, username);
    stringCopy(list->users[list->count].password, password);
    list->count++; // Increment jumlah pengguna
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    return 1; // Registrasi berhasil
}

// Fungsi untuk login
User* login(UserList *list, char *username, char *password, User *currentUser) {
    // Login gagal karena pengguna belum logout
    if (currentUser != NULL) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser->name);
        return currentUser; // Kembalikan pengguna yang sedang login
    }

    // Cari pengguna berdasarkan username
    int index = findUser(list, username);
    // Login gagal karena username tidak ditemukan atau password salah
    if (index == -1 || !stringCompare(list->users[index].password, password)) {
        printf("Username atau password salah.\n");
        return NULL; // Login gagal
    }

    // Login berhasil
    printf("Anda telah login ke PURRMART sebagai %s.\n", username);
    return &list->users[index]; // Kembalikan pointer ke pengguna yang login
}

// Fungsi untuk logout 
void logout(User **currentUser) {
    // Logout gagal karena belum login
    if (*currentUser == NULL) {
        printf("Anda belum login.\n");
    // Logout berhasil
    } else {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", (*currentUser)->name);
        *currentUser = NULL; // Set pointer pengguna menjadi NULL
    }
}
