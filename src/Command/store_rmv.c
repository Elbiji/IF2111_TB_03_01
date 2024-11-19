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
    char perintah[50];
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

    char namauser[50];
    printf("Masukkan sebuah nama user: \n");
    readInput(namauser, MAX_LEN);

    if (!isUserInFile(user, namauser)){
        printf("Tidak ada user bernama %s\n", namauser);
        printf("%d\n", IndexUserInFile(user, namauser));
    } else {
        printf("Terdapat user bernama %s\n", namauser);
        printf("%d\n", IndexUserInFile(user, namauser));
    }

    while (1){
        readCommand(perintah, MAX_LEN);
        if (isStrEqual(perintah, "START")){
            printf("START PROGRAM! \n");
        } else if (isStrEqual(perintah, "STOP")){
            break;
        } else {
            printf("Tidak tedapat command tersebut!\n");
        }
    }
    

    DeallocateArrayDinBarang(&items);
    return 0;
}