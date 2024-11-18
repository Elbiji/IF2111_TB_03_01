#include "../Header/store_rmv.h"

IdxType IndexItemInShop(ArrayDinBarang array, char *str){
    for (int i = 0; i < array.Neff; i++){
        boolean exist = true;
        int j = 0;

        while (array.A[i].name[j] != '\0' && str[j] != '\0'){
            if (array.A[i].name[j] != str[j]){
                exist = false;
                break;
            }
            j++;
        }

        if (exist && array.A[i].name[j] == '\0' && str[j] == '\0'){
            return i;
        }
    }
    return -1;
}

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
                scanf(" %[^\n]", barang_hapus);

        if (isStrAllDigit(barang_hapus)){
            printf("Pastikan anda memasukkan nama berupa karakter\n");

        } else if (!IndexItemInShop(nama_barang) < 0){
            printf("Barang tidak ada di toko!\n");

        } else {
            printf("Barang berhasil dihilangkan.\n");
            DeleteAt(array, IndexItemInShop(nama_barang));
            for (int i = 0; i < array->Neff; i++) {
            printf("Item %d: %s (Price: %d)\n", 
                i+1, array->A[i].name, array->A[i].price);
            }
        }
    }  
}


int main() {
    TabUser user;
    ArrayDinBarang items;
    Queue item_req;
    MakeArrayDinBarang(&items);
    start(&user, &items, &item_req);
    
    // Print results to verify
    printf("\nLoaded Users:\n");
    for (int i = 0; i <  user.Neff; i++) {
        printf("User %d: %s (Money: %d)\n", 
               i+1, user.TC[i].name, user.TC[i].money);
    }
    
    printf("\nLoaded Items:\n");
    for (int i = 0; i < items.Neff; i++) {
        printf("Item %d: %s (Price: %d)\n", 
               i+1, items.A[i].name, items.A[i].price);
    }
    
    store_request(&item_req, items);
    store_sup(&item_req, &items);
    displayQueue(item_req);

    DeallocateArrayDinBarang(&items);
    return 0;
}