#include "../Header/cart_add.h"

boolean isInputCartAdd(char *input, int *amount, char *nama_barang){
    const char *command = "CART ADD";
    int j;
    int i = 0;

    while (command[i] != '\0'){
        if (input[i] != command[i]){
            return false;
        }
        i++;
    }

    while (input[i] == ' '){
        i++;
    }

   j = 0;
    while (input[i] != ' ' && input[i] != '\0'){
        nama_barang[j++] = input[i++];
    }
    nama_barang[j] = '\0';

    while (input[i] == ' '){
        i++;
    }

    char num1[10];
    j = 0;
    while (input[i] >= '0' && input[i] <= '9' && j < 9){
        num1[j++] = input[i++];
    }
    num1[j] = '\0';
    *amount = atoi(num1);

    if (*amount > 0){
        return true;
    }
    else{
        return false;
    }

    return true;
}

void cart_add(Map *keranjang, ArrayDinBarang shop, char *nama_barang_keranjang, int jumlah_barang) {
    // Variabel sementara untuk menyimpan nama barang dan jumlah barang
    infotype informasi_barang;

    // Cek apakah barang ada di toko (shop)
    if (!isItemInShop(shop, nama_barang_keranjang)) {
        printf("Barang tidak ada di toko!\n");
        return;
    }

    // Validasi jumlah barang
    if (jumlah_barang <= 0) {
        printf("Jumlah barang tidak valid.\n");
        return;
    }

    // Salin nama barang ke variabel sementara
    stringCopy(informasi_barang.nama_barang_keranjang, nama_barang_keranjang);

    // Salin jumlah barang ke variabel sementara
    informasi_barang.jumlah_barang = jumlah_barang;

    // Tambahkan ke keranjang
    if (IsMember(*keranjang, &informasi_barang.nama_barang_keranjang)) {
        // Jika barang sudah ada di keranjang, tambahkan jumlahnya
        for (address i = 0; i < keranjang->Count; i++) {
            if (isStrEqualMap(keranjang->Elements[i].nama_barang_keranjang, informasi_barang.nama_barang_keranjang)) {
                keranjang->Elements[i].jumlah_barang += informasi_barang.jumlah_barang;
                break;
            }
        }
    } else {
        // Jika barang belum ada di keranjang, tambahkan barang baru
        Insert(keranjang, &informasi_barang.nama_barang_keranjang, informasi_barang.jumlah_barang);
    }
    printf("%s sebanyak %d telah ditambahkan ke keranjang.\n", informasi_barang.nama_barang_keranjang, informasi_barang.jumlah_barang);
}
