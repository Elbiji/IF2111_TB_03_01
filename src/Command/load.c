#include "../Header/Load.h"

// #include "../Header/misc.h"
// #include "../ADT/array/array.h"
// #include "../ADT/mesinkarakter/mesinkarakter.h"
// #include "../ADT/mesinkata/mesinkata.h"
// #include "../ADT/arraydin/arraydin.h"
// #include "../ADT/array/array.c"
// #include "../ADT/arraydin/arraydin.c"
// #include "../ADT/mesinkarakter/mesinkarakter.c"
// #include "../ADT/mesinkata/mesinkata.c"

#include <stdio.h>
#include <stdlib.h>

// customStrcat("save/", filename);
void customStrcat(char *dest, char *src) {
    int i = 0;
    while (dest[i] != '\0') {
        i++; // Menemukan akhir dari string tujuan
    }
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0'; 
}


void load(TabUser *Users, ArrayDinBarang *array) {
    // Inisialisasi ulang struktur data
    Barang inventory;
    char filename[MAX_LEN];
    

    ResetTabUser(Users);

    DeallocateArrayDinBarang(array);
    MakeArrayDinBarang(array);

    // Membuat path file lengkap

    while (1) {
        printf("Masukkan nama file yang akan di load :\n");
        char dest[MAX_LEN] = "save/";
        if (!readInput(filename, MAX_LEN)){
            continue;
        }
        customStrcat(dest, filename);
        printf("%s\n",dest); 


        STARTWORD(dest, "r");
        if (pitaFile == NULL){
            printf("Tidak ada file dengan nama tersebut!\n");
            continue;
        }

        // Memeriksa apakah baris pertama adalah jumlah barang yang valid
        if (CurrentWord.Length == 0 || !isStrAllDigit(CurrentWord.TabWord)) {
            printf("Konfigurasi file tidak valid. Mohon perbaiki file konfigurasi.\n");
            continue;
        }

        // Membaca jumlah barang
        int totalinventory = atoi(CurrentWord.TabWord);


        // Membaca data barang
        for (int i = 0; i < totalinventory; i++) {
            ADVWORD();

            inventory.price = atoi(CurrentWord.TabWord);

            ADVWORD();

            // Membaca nama barang
            int nameindex = 0;
            for (int j = 0; j < CurrentWord.Length; j++) {
                inventory.name[nameindex++] = CurrentWord.TabWord[j];
            }
            
            while(GetCC() == ' '){
                inventory.name[nameindex++] = ' ';
                ADVWORD();

                for (int j = 0; j < CurrentWord.Length; j++){
                    inventory.name[nameindex++] = CurrentWord.TabWord[j];
                }
            }

            inventory.name[nameindex] = '\0';
            printf("Adding item: %s, price: %d\n", inventory.name, inventory.price);
            InsertBarang(array, inventory, i);

        }

        // Setup users
        ADVWORD();
        int totaluser = atoi(CurrentWord.TabWord);
        Users->Neff = totaluser;
        for (int i = 0; i < totaluser; i++) {
            ADVWORD();
            Users->TC[i].money = atoi(CurrentWord.TabWord);
            
            ADVWORD();
            for (int j = 0; j < CurrentWord.Length; j++) {
                Users->TC[i].name[j] = CurrentWord.TabWord[j];
            }
            Users->TC[i].name[CurrentWord.Length] = '\0';
            
            ADVWORD();
            for (int j = 0; j < CurrentWord.Length; j++) {
                Users->TC[i].password[j] = CurrentWord.TabWord[j];
            }
            Users->TC[i].password[CurrentWord.Length] = '\0';
        }
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
            break; // Keluar dari loop jika file valid
    }
}

// Fungsi main untuk pengujian
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
//     filename[idx] = '\0'; // Akhiri dengan null terminator

//     // Memuat data dari file
//     printf("\nMemuat data dari %s...\n", filename);
//     load(filename, &Users, &Items);

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
