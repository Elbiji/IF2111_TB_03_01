#include "../Header/Load.h" 

#include <stdio.h>
#include <stdlib.h>
// #include "../Header/misc.h"
// #include "../ADT/array/array.h"
// #include "../ADT/mesinkarakter/mesinkarakter.h"
// #include "../ADT/mesinkata/mesinkata.h"
// #include "../ADT/arraydin/arraydin.h"
// #include "../ADT/array/array.c"
// #include "../ADT/arraydin/arraydin.c"
// #include "../ADT/mesinkarakter/mesinkarakter.c"
// #include "../ADT/mesinkata/mesinkata.c"

/* Implementasi strcat */
void customStrcat(char *dest, const char *src) {
    while (*dest != '\0') {
        dest++; // Menemukan akhir dari string tujuan
    }
    while (*src != '\0') {
        *dest = *src; // Menambahkan string sumber
        dest++;
        src++;
    }
    *dest = '\0'; 
}

/* Implementasi strcpy */
void CopyString(const char *src, char *dest) {
    while (*src != '\0') { // Salin setiap karakter dari src ke dest
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0'; 
}

/* Fungsi utama untuk memuat data dari file */
boolean loadFile(const char *filename, ArrayDinBarang *barangArray, TabUser *userArray) {
    DeallocateArrayDinBarang(barangArray);
    char filepath[100] = "./save/";  // Direktori save file
    customStrcat(filepath, filename);  // Gunakan customStrcat untuk gabungkan nama file ke path

    START(filepath, "r");  // Inisialisasi pembacaan file
    if (IsEOP()) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return false;
    }

    /* Membaca jumlah barang */
    int nBarang = 0;
    if (isStrAllDigit(CurrentWord.TabWord)) {
        nBarang = atoi(CurrentWord.TabWord);
    } else {
        printf("Format file salah (jumlah barang invalid).\n");
        return false;
    }

    MakeArrayDinBarang(barangArray);  // Alokasikan array barang
    for (int i = 0; i < nBarang; i++) {
        ADV();
        int harga = atoi(CurrentWord.TabWord);  // Baca harga barang
        ADV();
        CopyString(CurrentWord.TabWord, barangArray->A[i].name);  // Baca nama barang
        barangArray->A[i].price = harga;
    }
    barangArray->Neff = nBarang;

    /* Membaca jumlah pengguna */
    ADV();
    int nUsers = 0;
    if (isStrAllDigit(CurrentWord.TabWord)) {
        nUsers = atoi(CurrentWord.TabWord);
    } else {
        printf("Format file salah (jumlah pengguna invalid).\n");
        return false;
    }

    MakeEmpty(userArray);  // Alokasikan array pengguna
    for (int i = 0; i < nUsers; i++) {
        ADV();
        int money = atoi(CurrentWord.TabWord);  // Baca jumlah uang pengguna
        ADV();
        CopyString(CurrentWord.TabWord, userArray->TC[i].name);  // Baca nama pengguna
        ADV();
        CopyString(CurrentWord.TabWord, userArray->TC[i].password);  // Baca password pengguna
        userArray->TC[i].money = money;
    }
    userArray->Neff = nUsers;

    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
    return true;
}

// /* Fungsi untuk menampilkan data barang */
// void displayBarang(const ArrayDinBarang *barangArray) {
//     printf("Daftar Barang:\n");
//     for (int i = 0; i < barangArray->Neff; i++) {
//         printf("- %s (Harga: %d)\n", barangArray->A[i].name, barangArray->A[i].price);
//     }
// }

// /* Fungsi untuk menampilkan data pengguna */
// void displayUsers(const TabUser *userArray) {
//     printf("Daftar Pengguna:\n");
//     for (int i = 0; i < userArray->Neff; i++) {
//         printf("- %s (Uang: %d)\n", userArray->TC[i].name, userArray->TC[i].money);
//     }
// }

/* Fungsi utama */
// int main() {
//     ArrayDinBarang barangArray;
//     TabUser userArray;

//     char filename[50];
//     printf("Masukkan nama file: ");
//     readInput(filename, 50);

//     if (loadFile(filename, &barangArray, &userArray)) {
//         displayBarang(&barangArray);
//         displayUsers(&userArray);
//     }

//     return 0;
// }