#include "../Header/cart_pay.h"

int compareStrings(const char *str1, const char *str2) {
    // Bandingkan dua string secara manual
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 > *str2) {
            return 1; // str1 lebih besar
        } else if (*str1 < *str2) {
            return -1; // str2 lebih besar
        }
        str1++;
        str2++;
    }

    // Jika salah satu string lebih pendek tetapi sama sebelumnya, string yang lebih panjang lebih besar
    if (*str1 == '\0' && *str2 != '\0') {
        return -1; // str2 lebih besar
    } else if (*str2 == '\0' && *str1 != '\0') {
        return 1; // str1 lebih besar
    }

    return 0; // Kedua string sama
}


void cart_pay(TabUser *T, IdxType userIdx, Map *cart, Stack *riwayat, ArrayDinBarang informasi_barang) {
    // Jika keranjang kosong
    if (IsEmptyMap(*cart)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    // Menampilkan isi keranjang
    printf("Berikut adalah isi keranjangmu.\n");
    // Header tabel dengan lebar kolom yang ditentukan
    printf("%-10s%-50s%-10s\n", "Kuantitas", "Nama", "Total");


    int totalCost = 0;
    char mostExpensiveName[50] = "";
    int mostExpensiveValue = 0;

    for (int i = 0; i < cart->Count; i++) {
        int quantity = cart->Elements[i].jumlah_barang;
        char *name = cart->Elements[i].nama_barang_keranjang;
        IdxType index_barang = IndexItemInShop(informasi_barang, name);
        int price = informasi_barang.A[index_barang].price; // Harga barang dari keranjang
        int totalPrice = quantity * price;

        // Cetak baris dengan format yang rapi
        printf("%-10d%-50s%-10d\n", quantity, name, totalPrice);

        totalCost += totalPrice;

        // Cari barang dengan total harga terbesar
        if (totalPrice > mostExpensiveValue || (totalPrice == mostExpensiveValue && compareStrings(name, mostExpensiveName) > 0)) {
            mostExpensiveValue = totalPrice;
            for (int j = 0; j < 50 - 1 && name[j] != '\0'; j++) {
                mostExpensiveName[j] = name[j];
                mostExpensiveName[j + 1] = '\0';
            }
        }
    }

    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalCost);
    char response[10];

    while (1){
        if(!readInput(response, 10)){
            printf("Masukkan perintah yang valid!(Ya/Purry)\n");
            continue;
        }
        break;
    }

    // Cek respon pengguna
    if (isStrEqual(response, "Purry")) {
        printf("Anda telah keluar dari CART PAY.\n");
        return;
    } else if (isStrEqual(response, "Ya")) {
        int userMoney = T->TC[userIdx].money;

        if (userMoney >= totalCost) {
            // Kurangi uang pengguna
            T->TC[userIdx].money -= totalCost;

            // Tambahkan riwayat pembelian ke stack history yang sudah ada
            history topHistory;
            topHistory.total_price = mostExpensiveValue;

            for (int j = 0; j < 50 - 1 && mostExpensiveName[j] != '\0'; j++) {
                topHistory.nama_barang[j] = mostExpensiveName[j];
                topHistory.nama_barang[j + 1] = '\0';
            }

            Push(riwayat, topHistory);

            printf("Selamat kamu telah membeli barang-barang tersebut!\n");
            CreateEmpty(cart);
            return;
        } else {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", userMoney);
        }
    } else {
        printf("Pembelian dibatalkan anda dikeluarkan dari CART PAY!\n");
    }
}
