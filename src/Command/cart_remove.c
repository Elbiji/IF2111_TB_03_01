#include "cart_remove.h"

void cart_remove(Map *keranjang) {
    // Variabel sementara untuk menyimpan nama barang dan jumlah barang
    char nama_barang_copy[50];
    valuetype jumlah_barang_copy;
    printf("Ketik Purry untuk keluar\n");

    while (1) {
        printf("Masukkan nama barang yang akan dihapus: \n");
        if (!readInput(nama_barang_copy, 50)) continue; // Validasi input nama barang

        // Cek apakah pengguna ingin keluar
        if (isDone(nama_barang_copy)) {
            printf("Anda telah keluar dari CART REMOVE.\n");
            break;
        }

        // Cek apakah barang ada di keranjang
        if (!IsMember(*keranjang, nama_barang_copy)) {
            printf("Barang tidak ada di keranjang belanja!\n");
            continue;
        }

        // Ambil jumlah barang saat ini di keranjang
        jumlah_barang_copy = Value(*keranjang, nama_barang_copy);

        printf("Masukkan jumlah yang akan dikurangi: \n");
        int jumlah_dikurangi = strToInteger();

        if (jumlah_dikurangi == -1 || jumlah_dikurangi <= 0) {
            printf("Jumlah tidak valid! Masukkan angka positif.\n");
            continue;
        }

        // Validasi jumlah barang yang akan dikurangi
        if (jumlah_barang_copy < jumlah_dikurangi) {
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", jumlah_barang_copy, nama_barang_copy);
            continue;
        }

        // Kurangi jumlah barang atau hapus jika jumlah menjadi nol
        if (jumlah_barang_copy == jumlah_dikurangi) {
            Delete(keranjang, nama_barang_copy);
        } else {
            Insert(keranjang, nama_barang_copy, jumlah_barang_copy - jumlah_dikurangi);
        }

        printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", jumlah_dikurangi, nama_barang_copy);

        break; // Keluar setelah berhasil mengurangi barang
    }

    printf("Anda sudah keluar dari CART REMOVE!\n");
}




// int main() {
//     // Misalkan kita memiliki map untuk keranjang belanja
//     Map keranjang;
    
//     // Inisialisasi keranjang belanja
//     CreateEmpty(&keranjang);

//     // Menambahkan beberapa barang ke keranjang
//     Insert(&keranjang, "Apel", 10);
//     Insert(&keranjang, "Jeruk", 5);
//     Insert(&keranjang, "Pisang", 8);

//     // Tampilkan isi keranjang sebelum penghapusan
//     printf("Keranjang belanja sebelum penghapusan:\n");
//     PrintMap(keranjang);  

//     // Test fungsi cart_remove
//     printf("\nMenghapus barang dari keranjang:\n");
//     cart_remove(&keranjang);

//     // Tampilkan isi keranjang setelah penghapusan
//     printf("\nKeranjang belanja setelah penghapusan:\n");
//     PrintMap(keranjang);  

//     return 0;
// }
