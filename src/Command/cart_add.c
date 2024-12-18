#include "../Header/cart_add.h"

boolean isInputCartAdd(char *input, int *amount, char *nama_barang){
    const char *command = "CART ADD";
    int j;
    int i = 0;
    int last_space = -1;

    while (command[i] != '\0'){
        if (input[i] != command[i]){
            return false;
        }
        i++;
    }

    while (input[i] == ' '){
        i++;
    }

    int current = i;
    while(input[current] != '\0'){
        if (input[current] == ' '){
            last_space = current;
        }
        current++;
    }

    char num1[10];
    int amount_start = last_space + 1;
    j = 0;
    while (input[amount_start] >= '0' && input[amount_start] <= '9' && j < 9){
        num1[j++] = input[amount_start++];
    }
    num1[j] = '\0';
    *amount = atoi(num1);

    int name_start = i;
    int name_end = last_space - 1;

    while (name_end >= name_start && input[name_end] == ' '){
        name_end--;
    }

    int name_length = name_end - name_start + 1; // Add + 1 so counts both start and end
    j = 0; 
    while(j < name_length && j < (MAX_LEN-1)){
        nama_barang[j++] = input[name_start++];
    }
    nama_barang[j] = '\0';

    if (*amount > 0){
        return true;
    }
    else{
        printf("Pastikan anda masukkan angka yang valid untuk melakukan CART ADD!\n");
        printf("e.g. CART ADD <nama> <i> dengan i  merupakan jumlah barang anda! (integer positive)\n");
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
