#include "../Header/wishlist_add.h"

void wishlist_add (TabUser *user_wishlist, ArrayDinBarang item_shop, IdxType userid){
    char perantara[50];
    info_barang barang_wishlist;
    printf("Ketik Purry untuk keluar\n");
    
    while(1){
        printf("Masukan nama barang wishlist: \n");
        if(!readInput(perantara, 50)) continue;

        if(isDone(perantara)) break;

        stringCopy(barang_wishlist, perantara);
        if(Search(user_wishlist->TC[userid].wishlist, barang_wishlist) != Kosong){
            printf("Barang sudah ada di dalam wishlist!\n");
            continue;
        } else if (IndexItemInShop(item_shop, perantara) < 0){
            printf("Tidak ada barang tersebut di dalam toko!\n");
            continue;
        }

        InsVFirst(&(user_wishlist->TC[userid].wishlist), barang_wishlist);
        // PrintForward(user_wishlist->TC[userid].wishlist);
        break;
    }
    printf("Anda sudah keluar dari WISHLIST ADD!\n");
}