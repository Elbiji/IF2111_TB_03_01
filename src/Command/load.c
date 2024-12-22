#include "../Header/Load.h"

// #include "../Header/misc.h"
// #include "../ADT/array_load/array_load.h"
// #include "../ADT/mesinkarakter/mesinkarakter.h"
// #include "../ADT/mesinkata/mesinkata.h"
// #include "../ADT/arraydin/arraydin.h"
// #include "../ADT/array_load/array_load.c"
// #include "../ADT/arraydin/arraydin.c"
// #include "../ADT/mesinkarakter/mesinkarakter.c"
// #include "../ADT/mesinkata/mesinkata.c"

#include <stdio.h>
#include <stdlib.h>


int totalinventory_load;
int totalhistory_load;
int totalwishlist_load;
int totaluser_load;
info_barang barang_wishlist_load;
history barang_riwayat_load;
Barang inventory_load;
ArrayDinBarang array_load;

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


void load(TabUser *Users, ArrayDinBarang *array_load) {
    // Inisialisasi ulang struktur data
    Barang inventory_load;
    char filename[MAX_LEN];
    
    // Avoids system to access unauthorized memory so dont remove this part
    if(!IsUserEmpty){
        ResetTabUser(Users);
    }

    DeallocateArrayDinBarang(array_load);
    MakeArrayDinBarang(array_load);

    // Membuat path file lengkap

    while (1) {
        printf("Masukkan nama file yang akan di load :\n");
        char dest[MAX_LEN] = "save/";
        if (!readInput(filename, MAX_LEN)){
            continue;
        }
        customStrcat(dest, filename);
  


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

        totalinventory_load = atoi(CurrentWord.TabWord);

        // Setup items
        for (int i = 0; i < totalinventory_load; i++){
            ADVWORD();
            inventory_load.price = atoi(CurrentWord.TabWord);

            ADVWORD();
            int nameindex = 0;

            for (int j = 0; j < CurrentWord.Length; j++){
                inventory_load.name[nameindex++] = CurrentWord.TabWord[j];
            }

            while(GetCC() == ' '){
                inventory_load.name[nameindex++] = ' ';
                ADVWORD();

                for (int j = 0; j < CurrentWord.Length; j++){
                    inventory_load.name[nameindex++] = CurrentWord.TabWord[j];
                }
            }

            inventory_load.name[nameindex] = '\0';
            // printf("Adding item: %s, price: %d\n", inventory_load.name, inventory_load.price);
            InsertBarang(array_load, inventory_load, i);
        }

        // Setup users
        ADVWORD();
        totaluser_load = atoi(CurrentWord.TabWord);
        Users->Neff = totaluser_load;
        int ctr = 0;
        while (ctr < totaluser_load){
            CreateEmpty(&(Users->TC[ctr].keranjang));
            ADVWORD();
            Users->TC[ctr].money = atoi(CurrentWord.TabWord);
            
            ADVWORD();
            for (int j = 0; j < CurrentWord.Length; j++) {
                Users->TC[ctr].name[j] = CurrentWord.TabWord[j];
            }
            Users->TC[ctr].name[CurrentWord.Length] = '\0';
            
            ADVWORD();
            for (int j = 0; j < CurrentWord.Length; j++) {
                Users->TC[ctr].password[j] = CurrentWord.TabWord[j];
            }
            Users->TC[ctr].password[CurrentWord.Length] = '\0';

            ADVWORD();
            totalhistory_load = atoi(CurrentWord.TabWord);
            CreateEmptyStack(&(Users->TC[ctr].riwayat_pembelian));

            for (int i = 0; i < totalhistory_load; i++){
                ADVWORD();
                barang_riwayat_load.total_price = atoi(CurrentWord.TabWord);

                ADVWORD();
                int nameindex = 0;

                for (int j = 0; j < CurrentWord.Length; j++){
                    barang_riwayat_load.nama_barang[nameindex++] = CurrentWord.TabWord[j];
                }

                while(GetCC() == ' '){
                    barang_riwayat_load.nama_barang[nameindex++] = ' ';
                    ADVWORD();

                    for (int j = 0; j < CurrentWord.Length; j++){
                        barang_riwayat_load.nama_barang[nameindex++] = CurrentWord.TabWord[j];
                    }
                }

                barang_riwayat_load.nama_barang[nameindex] = '\0';
                
                Push(&(Users->TC[ctr].riwayat_pembelian), barang_riwayat_load);
            }

            ADVWORD();
            totalwishlist_load = atoi(CurrentWord.TabWord);
            CreateEmptyLDP(&(Users->TC[ctr].wishlist));

            for (int i = 0; i < totalwishlist_load; i++){
                ADVWORD();
                int nameindex = 0;

                for (int j = 0; j < CurrentWord.Length; j++){
                    barang_wishlist_load[nameindex++] = CurrentWord.TabWord[j];
                }

                while(GetCC() == ' '){
                    barang_wishlist_load[nameindex++] = ' ';
                    ADVWORD();

                    for (int j = 0; j < CurrentWord.Length; j++){
                        barang_wishlist_load[nameindex++] = CurrentWord.TabWord[j];
                    }
                }
                barang_wishlist_load[nameindex] = '\0';
                // printf("Debug %s\n", barang_wishlist_load);
                InsVLast(&(Users->TC[ctr].wishlist), barang_wishlist_load);
            }
            PrintForward(Users->TC[ctr].wishlist);
            ctr++;
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
