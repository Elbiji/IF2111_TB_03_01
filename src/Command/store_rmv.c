#include "../Header/store_rmv.h"

void store_rmv(ArrayDinBarang *array){
    char barang_hapus[50];
    printf("=======  [STORE REMOVE] =======\n");

    while (!IsEmpty(* array)){
        printf("Items in Store:\n");
        for (int i = 0; i < array->Neff; i++) {
            printf("Item %d: %s (Price: %d)\n", 
                i+1, array->A[i].name, array->A[i].price);
        }

        printf("Nama barang yang dihapus: \n");
                // scanf(" %49[^\n]", barang_hapus);

        if(!readInput(barang_hapus, MAX_LEN)){
            continue;
        }

        if(isStrEqual(barang_hapus, "Purry")){
            break;
        }

        int id_item_in_shop = IndexItemInShop(*array, barang_hapus);
        if (isStrAllDigit(barang_hapus)){
            printf("Pastikan anda memasukkan nama berupa karakter\n");

        } else if (id_item_in_shop < 0){
            printf("Barang tidak ada di toko!\n");

        } else {
            printf("Barang berhasil dihilangkan.\n");
            DeleteAt(array, id_item_in_shop);
            DecreaseArray(array);
            // for (int i = 0; i < array->Neff; i++) {
            // printf("Item %d: %s (Price: %d)\n", 
            //     i+1, array->A[i].name, array->A[i].price);
            // }
        }
    }
    if (IsEmpty(*array)){
        printf("Tidak terdapat barang di toko!\n");
    } else {
        printf("Anda telah keluar dari STORE REMOVE\n");
    }
}


