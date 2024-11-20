#include "../Header/save.h"

// #include "../Header/Load.h"
// #include "../Header/misc.h"
// #include <stdio.h>
// #include <stdlib.h>

// Fungsi untuk menyimpan data ke dalam file
void save(const char *filename, TabUser *Users, ArrayDinBarang *array) {
    FILE *file;
    char filepath[256] = "save/";  // Folder save
    int i, j;

    // Membuka file untuk menulis
    // Gabungkan folder "save/" dengan nama file
    i = 0;
    while (filename[i] != '\0') {
        filepath[5 + i] = filename[i];  // Menggabungkan dengan nama file
        i++;
    }
    filepath[5 + i] = '\0';  // Akhiri string

    // Mengecek apakah folder "save" ada dengan mencoba membuka file sementara
    file = fopen(filepath, "w");  // Mencoba membuka file untuk menulis
    if (file == NULL) {
        printf("Folder 'save' belum ada, membuat folder...\n");
        system("mkdir save");  // Perintah sistem untuk membuat folder "save"
        
        // Coba buka lagi setelah folder dibuat
        file = fopen(filepath, "w");
        if (file == NULL) {
            printf("Gagal membuka file untuk menulis.\n");
            return;
        }
    }

    // Menyimpan jumlah barang
    fprintf(file, "%d\n", array->Neff);  // Menyimpan jumlah barang

    // Menyimpan data barang
    for (i = 0; i < array->Neff; i++) {
        fprintf(file, "%d %s\n", array->A[i].price, array->A[i].name);  // Menyimpan harga dan nama barang
    }

    // Menyimpan jumlah pengguna
    fprintf(file, "%d\n", Users->Neff);  // Menyimpan jumlah pengguna

    // Menyimpan data pengguna
    for (i = 0; i < Users->Neff; i++) {
        fprintf(file, "%d %s %s\n", Users->TC[i].money, Users->TC[i].name, Users->TC[i].password);
    }

    // Menutup file setelah selesai menulis
    fclose(file);

    // Memberikan feedback bahwa file telah disimpan
    printf("Save file berhasil disimpan.\n");
    printf("File disimpan pada %s\n", filepath);  // Menampilkan path lengkap file yang disimpan
}

// int main() {
//     // Misalnya ada TabUser dan ArrayDinBarang yang sudah terisi sebelumnya
//     TabUser Users;
//     ArrayDinBarang Items;
    
//     // Memastikan data telah dimuat ke dalam Users dan Items (misalnya dengan fungsi load sebelumnya)

//     // Nama file untuk menyimpan data
//     char filename[256] = "savefile.txt";  // Nama file yang ingin disimpan

//     // Panggil fungsi save untuk menyimpan data
//     save(filename, &Users, &Items);

//     return 0;
// }