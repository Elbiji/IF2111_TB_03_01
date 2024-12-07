#include "../Header/start.h"
// #include "../ADT/array/array.h"
// #include "../ADT/mesinkarakter/mesinkarakter.h"
// #include "../ADT/mesinkata/mesinkata.h"
// #include "../ADT/arraydin/arraydin.h"
// #include "../ADT/array/array.c"
// #include "../ADT/arraydin/arraydin.c"
// #include "../ADT/mesinkarakter/mesinkarakter.c"
// #include "../ADT/mesinkata/mesinkata.c"

int totalinventory;
int totalhistory;
int totalwishlist;
int totalbarang_per_inventory;
int totaluser;
info_barang barang_wishlist;
history barang_riwayat;
Barang inventory;
ArrayDinBarang array;
Queue items_request;

void start(TabUser *Users, ArrayDinBarang *array){
    STARTWORD("save/default.txt", "r");
    // STARTWORD("2.txt", "r");
    
    totalinventory = atoi(CurrentWord.TabWord);

    // Setup items
    for (int i = 0; i < totalinventory; i++){
        ADVWORD();
        inventory.price = atoi(CurrentWord.TabWord);

        ADVWORD();
        int nameindex = 0;

        for (int j = 0; j < CurrentWord.Length; j++){
            inventory.name[nameindex++] = CurrentWord.TabWord[j];
        }

        while(GetCC() == ' '){
            inventory.name[nameindex++] = ' ';
            ADVWORD();

            for (int j = 0; j < CurrentWord.Length; j++){
                inventory.name[nameindex++] = CurrentWord.TabWord[j];
            }
        }

        inventory.name[nameindex] = '\0';
        // printf("Adding item: %s, price: %d\n", inventory.name, inventory.price);
        InsertBarang(array, inventory, i);
    }

    // Setup users
    ADVWORD();
    totaluser = atoi(CurrentWord.TabWord);
    Users->Neff = totaluser;
    int ctr = 0;
    while (ctr < totaluser){
        ADVWORD();
        Users->TC[ctr].money = atoi(CurrentWord.TabWord);
        
        ADVWORD();
        for (int j = 0; j < CurrentWord.Length; j++) {
            Users->TC[ctr].name[j] = CurrentWord.TabWord[j];
        }
        Users->TC[ctr].name[CurrentWord.Length] = '\0';
        
        ADVWORD();
        for (int j = 0; j < CurrentWord.Length; j++) {
            Users->TC[ctr].password[j] = CurrentWord.TabWord[j];
        }
        Users->TC[ctr].password[CurrentWord.Length] = '\0';

        ADVWORD();
        totalhistory = atoi(CurrentWord.TabWord);
        CreateEmptyStack(Users->TC[ctr].riwayat_pembelian);

        for (int i = 0; i < totalhistory; i++){
            ADVWORD();
            barang_riwayat.total_price = atoi(CurrentWord.TabWord);

            ADVWORD();
            int nameindex = 0;

            for (int j = 0; j < CurrentWord.Length; j++){
                barang_riwayat.nama_barang[nameindex++] = CurrentWord.TabWord[j];
            }

            while(GetCC() == ' '){
                barang_riwayat.nama_barang[nameindex++] = ' ';
                ADVWORD();

                for (int j = 0; j < CurrentWord.Length; j++){
                    barang_riwayat.nama_barang[nameindex++] = CurrentWord.TabWord[j];
                }
            }

            barang_riwayat.nama_barang[nameindex] = '\0';
            Push(Users->TC[ctr].riwayat_pembelian, barang_riwayat);
        }

        ADVWORD();
        totalwishlist = atoi(CurrentWord.TabWord);
        CreateEmptyList(Users->TC[ctr].wishlist);

        for (int i = 0; i < totalwishlist; i++){
            ADVWORD();
            int nameindex = 0;

            for (int j = 0; j < CurrentWord.Length; j++){
                barang_wishlist[nameindex++] = CurrentWord.TabWord[j];
            }

            while(GetCC() == ' '){
                barang_wishlist[nameindex++] = ' ';
                ADVWORD();

                for (int j = 0; j < CurrentWord.Length; j++){
                    barang_wishlist[nameindex++] = CurrentWord.TabWord[j];
                }
            }

            barang_wishlist[nameindex] = '\0';
            
            Alokasi(barang_wishlist);
            InsVLast(Users->TC[ctr].wishlist);
        }
    }

    // for (int i = 0; i < totaluser; i++){
    //     printf("%d : %s\n", Users->TC[i].money, Users->TC[i].name);
    // }  

    // for (int i = 0; i < totalinventory; i++){
    //     printf("%d : %s\n", array->A[i].price, array->A[i].name);
    // } 
}    

// int main(){
//     TabUser user;
//     ArrayDinBarang items;
//     MakeArrayDinBarang(&items);

//     start(&user, &items);
//     DeallocateArrayDinBarang(&items);
//     return 0;
// }