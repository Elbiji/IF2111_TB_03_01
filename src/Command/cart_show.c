#include "../Header/cart_show.h"

void cart_show(Map *keranjang, ArrayDinBarang *barang_array) {
    printf(">> CART SHOW\n");

    // Periksa apakah keranjang kosong
    if (keranjang->Count == 0) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    // Header tabel
    printf("Berikut adalah isi keranjangmu.\n");
    printf("%-10s%-50s%-10s\n", "Kuantitas", "Nama", "Total");

    int total_biaya = 0;

    // Iterasi melalui elemen keranjang
    for (address i = 0; i < keranjang->Count; i++) {
        char *nama_barang = keranjang->Elements[i].Key;
        int kuantitas = keranjang->Elements[i].Value;
        int harga_satuan = 0;

        // Cari harga barang di barang_array
        for (int j = 0; j < barang_array->Neff; j++) {
            if (isStrEqual(barang_array->A[j].name, nama_barang)) {
                harga_satuan = barang_array->A[j].price;
                break;
            }
        }

        if (harga_satuan == 0) {
            printf("Barang %s tidak ditemukan dalam daftar harga!\n", nama_barang);
            continue;
        }

        int total_harga = kuantitas * harga_satuan;

        // Tampilkan setiap item di keranjang
        printf("%-10d%-50s%-10d\n", kuantitas, nama_barang, total_harga);

        // Tambahkan ke total biaya
        total_biaya += total_harga;
    }

    // Tampilkan total biaya
    printf("Total biaya yang harus dikeluarkan adalah %d.\n", total_biaya);

    printf("Ketik Purry untuk keluar\n");

    while (1) {
        char nama_barang_copy[50];
        printf("Masukkan nama barang untuk melihat detail atau ketik Purry untuk keluar: \n");
        if (!readInput(nama_barang_copy, 50)) continue; // Validasi input

        if (isDone(nama_barang_copy)) {
            printf("Anda telah keluar dari CART SHOW.\n");
            break;
        }

        // Cek apakah barang ada di keranjang
        if (!IsMember(*keranjang, nama_barang_copy)) {
            printf("Barang tidak ada di keranjang belanja!\n");
            continue;
        }

        // Ambil kuantitas barang
        int jumlah_barang_copy = Value(*keranjang, nama_barang_copy);
        printf("%s memiliki jumlah %d di keranjang.\n", nama_barang_copy, jumlah_barang_copy);
    }

    printf("Anda sudah keluar dari CART SHOW!\n");
}


// int main() {
//     // Inisialisasi keranjang belanja
//     Map keranjang;
//     CreateEmptyMap(&keranjang);

//     // Inisialisasi daftar barang dengan harga
//     ArrayDinBarang barang_array;
//     MakeArrayDinBarang(&barang_array);

//     // Tambahkan barang ke daftar barang
//     Barang apel = {"Apel", 5000};
//     Barang pisang = {"Pisang", 3000};
//     Barang jeruk = {"Jeruk", 4000};
//     Barang anggur = {"Anggur", 7000};

//     InsertBarang(&barang_array, apel, 0);
//     InsertBarang(&barang_array, pisang, 1);
//     InsertBarang(&barang_array, jeruk, 2);
//     InsertBarang(&barang_array, anggur, 3);

//     // Tambahkan barang ke keranjang
//     Insert(&keranjang, "Apel", 2);
//     Insert(&keranjang, "Pisang", 1);
//     Insert(&keranjang, "Jeruk", 5);

//     // Panggil fungsi cart_show untuk menampilkan isi keranjang
//     cart_show(&keranjang, &barang_array);

//     // Dealokasi memori
//     DeallocateArrayDinBarang(&barang_array);

//     return 0;
// }
