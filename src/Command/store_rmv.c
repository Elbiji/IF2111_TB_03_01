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
                // scanf(" %49[^\n]", barang_hapus);

        START("", "");
        while (!IsEOP() && (GetCC() == ' ' || GetCC == '\n')){
            ADV();
        } // Clearing buffer

        int i = 0;
        while (!IsEOP() && GetCC() != '\n' && i < MAX_LEN-1){
            barang_hapus[i++] = GetCC();
            ADV();
        }
        barang_hapus[i] = '\0';

        if (!IsEOP() && GetCC() != '\n') {
            while (!IsEOP() && GetCC() != '\n') {
                ADV();
            }
            printf("Input terlalu panjang! (max %d karakter)\n", MAX_LEN-1);
            continue;
        }

        int id_item_in_shop = IndexItemInShop(*array, barang_hapus);
        if (isStrAllDigit(barang_hapus)){
            printf("Pastikan anda memasukkan nama berupa karakter\n");

        } else if (id_item_in_shop < 0){
            printf("Barang tidak ada di toko!\n");

        } else {
            printf("Barang berhasil dihilangkan.\n");
            DeleteAt(array, id_item_in_shop);
            // for (int i = 0; i < array->Neff; i++) {
            // printf("Item %d: %s (Price: %d)\n", 
            //     i+1, array->A[i].name, array->A[i].price);
            // }
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
    store_rmv(&items);

    printf("\nLoaded Items:\n");
    for (int i = 0; i < items.Neff; i++) {
        printf("Item %d: %s (Price: %d)\n", 
               i+1, items.A[i].name, items.A[i].price);
    }
    displayQueue(item_req);

    DeallocateArrayDinBarang(&items);
    return 0;
}