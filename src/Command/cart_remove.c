#include "../Header/cart_remove.h"

boolean isInputCartRemove(char *input, int *amount, char *nama_barang){
    const char *command = "CART REMOVE";
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
        printf("Pastikan anda masukkan angka yang valid untuk melakukan CART ADD!\n");
        printf("e.g. CART REMOVE <nama> <i> dengan i  merupakan jumlah barang anda! (integer positive)\n");
        return false;
    }

    return true;
}

void cart_remove(Map *keranjang, char *nama_barang_keranjang, int jumlah_barang) {
    // Variabel sementara untuk menyimpan nama barang dan jumlah barang
    infotype informasi_barang;
    valuetype jumlah_barang_current;

    stringCopy(informasi_barang.nama_barang_keranjang, nama_barang_keranjang);
    informasi_barang.jumlah_barang = jumlah_barang;

    if (!IsMember(*keranjang, &informasi_barang.nama_barang_keranjang)){
        printf("Tidak ada barang dengan nama %s dalam keranjang anda!\n", informasi_barang.nama_barang_keranjang);
    } else {
        jumlah_barang_current = Value(*keranjang, &informasi_barang.nama_barang_keranjang);
        if (informasi_barang.jumlah_barang > jumlah_barang_current){
            printf("Angka yang anda masukkan melebihi jumlah barang saat ini!\n");
            printf("Pengurangan gagal dilakukan!\n");
            return;
        } else {
            if (informasi_barang.jumlah_barang == jumlah_barang_current){
                Delete(keranjang, &informasi_barang.nama_barang_keranjang);
            } else {
                SubtractAmount(keranjang, &informasi_barang.nama_barang_keranjang, informasi_barang.jumlah_barang);
                printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", informasi_barang.jumlah_barang ,informasi_barang.nama_barang_keranjang);
            }
        }
    }
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
