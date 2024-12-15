#include "../Header/cart_add.h"

void cart_add(Map *keranjang, Map *shop, char *nama_barang_keranjang, int jumlah_barang) {
    // Variabel sementara untuk menyimpan nama barang dan jumlah barang
    char nama_barang_copy[50];
    valuetype jumlah_barang_copy;
    printf("Ketik Purry untuk keluar\n");

    // Cek apakah barang ada di toko (shop)
    if (!IsMember(*shop, nama_barang_keranjang)) {
        printf("Barang tidak ada di toko!\n");
        return;
    }

    // Validasi jumlah barang
    if (jumlah_barang <= 0) {
        printf("Jumlah barang tidak valid.\n");
        return;
    }

    // Salin nama barang ke variabel sementara
    stringCopy(nama_barang_copy, nama_barang_keranjang);

    // Salin jumlah barang ke variabel sementara
    jumlah_barang_copy = jumlah_barang;

    // Tambahkan ke keranjang
    if (IsMember(*keranjang, nama_barang_copy)) {
        // Jika barang sudah ada di keranjang, tambahkan jumlahnya
        for (int i = 0; i < keranjang->Count; i++) {
            if (isStrEqualMap(keranjang->Elements[i].nama_barang_keranjang, nama_barang_copy)) {
                keranjang->Elements[i].jumlah_barang += jumlah_barang_copy;
                break;
            }
        }
    } else {
        // Jika barang belum ada di keranjang, tambahkan barang baru
        Insert(keranjang, &nama_barang_copy, jumlah_barang_copy);
    }
    printf("Berhasil menambah %d %s ke keranjang belanja!.\n", jumlah_barang_copy, nama_barang_copy);
}

