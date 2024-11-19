#ifndef LOGIN_H
#define LOGIN_H

#include "../ADT/boolean/boolean.h" // Gunakan boolean dari boolean.h

// Batas maksimum panjang nama pengguna dan password
#define MAX_USERS 100
#define MAX_LEN 50

// Struktur data pengguna
typedef struct {
    char name[MAX_LEN];       // Nama pengguna
    char password[MAX_LEN];   // Password pengguna
    int money;                // Uang pengguna
} User;

// Struktur data daftar pengguna
typedef struct {
    User users[MAX_USERS];    // Array pengguna
    int Neff;                 // Jumlah pengguna yang efektif
} TabUser;

// Deklarasi fungsi login
User* login(TabUser *list, char *username, char *password, User *currentUser);

// Deklarasi fungsi pendukung
boolean readInput(char *buffer, int maxLen);          // Membaca input dengan panjang maksimum
int getUserID(User *currentUser, TabUser *list);      // Mendapatkan ID (indeks) pengguna
boolean isUserLoggedIn(User *currentUser);            // Mengecek apakah ada pengguna yang sedang login
int findUser(TabUser *list, char *username);          // Mencari indeks pengguna berdasarkan username
int stringCompare(char *str1, char *str2);            // Membandingkan dua string

#endif
