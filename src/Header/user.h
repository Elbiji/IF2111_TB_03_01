#ifndef USER_H
#define USER_H

// Definisi batas maksimum pengguna dan panjang string
#define MAX_USERS 100
#define MAX_LEN 50

// Struktur data untuk menyimpan informasi pengguna
typedef struct {
    char name[MAX_LEN];       // Nama pengguna
    char password[MAX_LEN];   // Password pengguna
    int money;                // Tambahan atribut untuk menyimpan uang pengguna (sesuai data di file konfigurasi)
} User;

// Struktur data untuk menyimpan daftar pengguna
typedef struct {
    User users[MAX_USERS];    // Array pengguna
    int Neff;                 // Jumlah pengguna yang efektif
} TabUser;

// Inisialisasi daftar pengguna
void initUserList(TabUser *list);

// Cari pengguna berdasarkan username
int findUser(TabUser *list, char *username);

// Fungsi untuk register
int registerUser(TabUser *list, char *username, char *password, int money);

// Fungsi untuk login
User* login(TabUser *list, char *username, char *password, User *currentUser);

// Fungsi untuk logout 
void logout(User **currentUser);

#endif
