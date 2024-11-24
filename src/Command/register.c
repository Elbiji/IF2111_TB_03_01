#include <stdio.h>
#include "../Header/register.h"

// Fungsi menyalin string
void stringCopy(char *dest, const char *src) {
    while ((*dest++ = *src++) != '\0'); // Salin setiap karakter hingga null terminator
}

// Registrasi pengguna dengan validasi username, password, dan uang
void registerUser(TabUser *list) {
    char username[50], password[50], moneyStr[20];
    int money;

    while (1) {
        // Input username 
        printf("Masukkan username (maksimum 49 karakter, tanpa spasi): ");
        if (!readInput(username, 50)) continue; // Ulang jika input tidak valid
        if (containsSpace(username)) { // Validasi username tidak mengandung spasi
            printf("Username tidak boleh mengandung spasi.\n");
            continue;
        }

        // Periksa apakah username sudah ada di daftar
        if (isUserInFile(*list, username)) {
            printf("Akun dengan username %s gagal dibuat karena sudah ada. Silakan lakukan REGISTER ulang.\n", username);
            continue; // Gagal karena username sudah ada
        }

        // Input password
        while (1){
            printf("Masukkan password (maksimum 20 karakter): ");
            if (!readInput(password, 50)) continue; // Ulang jika input tidak valid
            int passLen = strLength(password);
            if (containsSpace(password)) { // Validasi username tidak mengandung spasi
                printf("Password tidak boleh mengandung spasi.\n");
                continue;
            }
            if (passLen < 6 || passLen > 20) { // Validasi panjang password
                printf("Password tidak valid! Panjang password harus 6-20 karakter.\n");
                continue;
            }
            break;
        }

        // Input jumlah uang
        while (1){
            printf("Masukkan jumlah uang awal: ");
            if (!readInput(moneyStr, 20)) continue; // Ulang jika input tidak valid

            
            if (!isStrAllDigit(moneyStr)) { // Validasi apakah input hanya terdiri dari digit
                printf("Input jumlah uang tidak valid. Masukkan angka positif.\n");
                continue;
            }
            money = atoi(moneyStr); // Konversi string ke integer
            if (money < 0) { // Validasi uang harus positif
                printf("Jumlah uang tidak boleh negatif.\n");
                continue;
            }
            break;
        }

        break; // Semua input valid
    }

    // Periksa apakah kapasitas daftar pengguna sudah penuh
    if (list->Neff >= 100) {
        printf("Register gagal. Kapasitas pengguna sudah penuh.\n");
        return;
    }

// Tambah pengguna baru
    stringCopy(list->TC[list->Neff].name, username);
    stringCopy(list->TC[list->Neff].password, password);
    list->TC[list->Neff].money = money;
    list->Neff++;
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
}
