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

void load(const char *filename, TabUser *Users, ArrayDinBarang *array, Queue *items_request) {
    // Inisialisasi ulang struktur data
    MakeEmpty(Users);
    CreateQueue(items_request);
    DeallocateArrayDinBarang(array);
    MakeArrayDinBarang(array);

    // Path ke file konfigurasi
    char filepath[256];
    int i = 0;
    while (filename[i] != '\0') {
        filepath[i] = filename[i];
        i++;
    }
    filepath[i++] = '\0';

    STARTWORD(filepath, "r");
    if (EndWord) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }

    // Membaca jumlah barang
    totalinventory = atoi(CurrentWord.TabWord);

    // Membaca data barang
    for (int i = 0; i < totalinventory; i++) {
        ADVWORD();
        Barang inventory;
        inventory.price = atoi(CurrentWord.TabWord);

        ADVWORD();
        int nameindex = 0;
        for (int j = 0; j < CurrentWord.Length; j++) {
            inventory.name[nameindex++] = CurrentWord.TabWord[j];
        }

        inventory.name[nameindex] = '\0';  // Mengakhiri string nama barang
        InsertBarang(array, inventory, i);
    }

    // Membaca jumlah pengguna
    ADVWORD();
    totaluser = atoi(CurrentWord.TabWord);
    Users->Neff = totaluser;

    // Membaca data pengguna
    for (int i = 0; i < totaluser; i++) {
        ADVWORD();
        Users->TC[i].money = atoi(CurrentWord.TabWord);

        ADVWORD();
        int nameindex = 0;
        for (int j = 0; j < CurrentWord.Length; j++) {
            Users->TC[i].name[nameindex++] = CurrentWord.TabWord[j];
        }
        Users->TC[i].name[nameindex] = '\0';  // Akhiri string nama

        ADVWORD();
        int passindex = 0;
        for (int j = 0; j < CurrentWord.Length; j++) {
            Users->TC[i].password[passindex++] = CurrentWord.TabWord[j];
        }
        Users->TC[i].password[passindex] = '\0';  // Akhiri string password
    }

    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

// int main() {
//     TabUser Users;
//     ArrayDinBarang Items;
//     Queue Requests;

//     MakeArrayDinBarang(&Items);
//     CreateQueue(&Requests);

//     char filename[256];
//     printf("Masukkan nama file untuk load (contoh: savefile.txt):\n");

//     // Membaca input nama file tanpa scanf
//     char c;
//     int idx = 0;
//     while ((c = getchar()) != '\n' && idx < 255) {
//         filename[idx++] = c;
//     }
//     filename[idx] = '\0';  // Akhiri dengan null terminator

//     // Memuat data dari file
//     printf("\nMemuat data dari %s...\n", filename);
//     load(filename, &Users, &Items, &Requests);

//     // Menampilkan hasil untuk verifikasi
//     printf("\n--- Daftar Barang ---\n");
//     for (int i = 0; i < Items.Neff; i++) {
//         printf("%d: %s (Harga: %d)\n", i + 1, Items.A[i].name, Items.A[i].price);
//     }

//     printf("\n--- Daftar Pengguna ---\n");
//     for (int i = 0; i < Users.Neff; i++) {
//         printf("%d: %s (Uang: %d, Password: %s)\n", i + 1, Users.TC[i].name, Users.TC[i].money, Users.TC[i].password);
//     }

//     DeallocateArrayDinBarang(&Items);
//     return 0;
// }