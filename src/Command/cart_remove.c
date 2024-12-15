#include "cart_remove.h"

void cart_remove(Map *keranjang) {
    char buffer[50];
    printf("Ketik Purry untuk keluar\n");

    while (1) {
        printf("Masukkan nama barang yang akan dihapus: \n");
        if (!readInput(buffer, 50)) continue;  // Jika input terlalu panjang atau tidak valid, ulangi

        // Cek apakah pengguna ingin keluar
        if (isDone(buffer)) {
            printf("Anda telah keluar dari CART REMOVE.\n");
            break;
        }

        // Cari item dalam keranjang
        valuetype currentQuantity = Value(*keranjang, buffer);
        if (currentQuantity == Undefined) {
            printf("Barang tidak ada di keranjang belanja!\n");
            continue;
        }

        printf("Masukkan jumlah yang akan dikurangi: \n");
        int quantity = strToInteger();

        if (quantity == -1 || quantity <= 0) {
            printf("Jumlah tidak valid! Masukkan angka positif.\n");
            continue;
        }

        // Validasi jumlah barang
        if (currentQuantity < quantity) {
            printf("Tidak berhasil mengurangi, hanya terdapat %d ", currentQuantity);
            for (int i = 0; buffer[i] != '\0'; i++) {
                putchar(buffer[i]);
            }
            printf(" pada keranjang!\n");
            continue;
        }

        // Kurangi jumlah barang
        if (currentQuantity == quantity) {
            Delete(keranjang, buffer);
        } else {
            Insert(keranjang, buffer, currentQuantity - quantity);
        }

        printf("Berhasil mengurangi %d ", quantity);
        for (int i = 0; buffer[i] != '\0'; i++) {
            putchar(buffer[i]);
        }
        printf(" dari keranjang belanja!\n");

        break;  // Keluar setelah berhasil mengurangi barang
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
//     PrintMap(keranjang);  // Asumsi ada fungsi untuk mencetak isi map/keranjang

//     // Test fungsi cart_remove
//     printf("\nMenghapus barang dari keranjang:\n");
//     cart_remove(&keranjang);

//     // Tampilkan isi keranjang setelah penghapusan
//     printf("\nKeranjang belanja setelah penghapusan:\n");
//     PrintMap(keranjang);  // Asumsi ada fungsi untuk mencetak isi map/keranjang

//     // Clean up jika perlu (misalnya delete map atau sejenisnya)
//     // FreeMap(&keranjang);

//     return 0;
// }
