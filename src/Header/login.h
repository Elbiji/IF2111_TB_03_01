#ifndef LOGIN_H
#define LOGIN_H

#include "../ADT/boolean/boolean.h"
#include "../Header/misc.h" 

// Batasan panjang username dan password
#define MAX_USERNAME_LEN 49
#define MIN_PASSWORD_LEN 6
#define MAX_PASSWORD_LEN 12

// Struktur data pengguna
typedef struct {
    char name[MAX_USERNAME_LEN + 1];       // Nama pengguna (maksimal 49 karakter + 1 untuk null terminator)
    char password[MAX_PASSWORD_LEN + 1];   // Password pengguna (maksimal 12 karakter + 1 untuk null terminator)
    int money;                             // Uang pengguna
} User;

// Struktur data daftar pengguna
typedef struct {
    User users[100]; // Array pengguna (maksimal 100 pengguna)
    int Neff;        // Jumlah pengguna yang efektif
} TabUser;

// Fungsi login
int login(TabUser list, User *currentUser);

#endif