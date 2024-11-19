#include "../Header/store_list.h"

// nampilin daftar barang
void DisplayStore(ArrayDinBarang store) {
    if (IsEmpty(store)) {
        printf("TOKO KOSONG\n");
    } else {
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < Length(store); i++) {
            printf("- %s\n", store.A[i].name);
        }
    }
}

// Fungsi utama
int main() {
    ArrayDinBarang store;
    // Tampilkan daftar barang di store
    printf(">> STORE LIST\n");
    DisplayStore(store);
    return 0;
}