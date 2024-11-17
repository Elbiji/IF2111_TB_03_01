#ifndef USER_H
#define USER_H

// Definisi batas maksimum pengguna dan panjang string
#define MAX_USERS 100
#define MAX_LEN 50

// Struktur data untuk menyimpan informasi pengguna
typedef struct {
    char name[MAX_LEN];       // Nama pengguna
    char password[MAX_LEN];   // Password pengguna
} User;

// Struktur data untuk menyimpan daftar pengguna
typedef struct {
    User users[MAX_USERS];    // Array pengguna
    int count;                // Jumlah pengguna yang terdaftar
} UserList;

// Inisialisasi daftar pengguna
void initUserList(UserList *list);

// Cari pengguna berdasarkan username
int findUser(UserList *list, char *username);

// Fungsi untuk register
int registerUser(UserList *list, char *username, char *password);

// Fungsi untuk login
User* login(UserList *list, char *username, char *password, User *currentUser);

// Fungsi untuk logout 
void logout(User **currentUser);

#endif
