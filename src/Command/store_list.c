#include "../Header/store_list.h"

//nampilin daftar barang
void DisplayStore(ArrayDinBarang store) {
    if (IsEmpty(store)) {
        printf("TOKO KOSONG\n");
        printf("Anda telah keluar dari STORE LIST\n");
    } else {
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < Length(store); i++) {
            printf("- %s - Harga - %d\n", store.A[i].name, store.A[i].price);
        }
    }
}

// //fungsi utama
// int main() {
//     ArrayDinBarang store;
//     //nampilin daftar barang di store
//     printf(">> STORE LIST\n");
//     DisplayStore(store);
//     return 0;
// }