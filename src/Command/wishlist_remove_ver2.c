#include "../Header/wishlist_remove_ver2.h"

void wishlist_remove2(List *user_wishlist){
    char perantara[50];
    info_barang barang_wishlist;
    printf("Ketik Purry untuk keluar\n");
    
    while(1){
        printf("Masukan nama barang yang akan dihapus: \n");
        if(!readInput(perantara, 50)) continue;

        if(isDone(perantara)) break;

        stringCopy(barang_wishlist, perantara);
        if(Search(*user_wishlist, barang_wishlist) == Kosong){
            printf("Barang tidak ada di wishlist!\n");
            continue;
        } else {
            DelP(user_wishlist, barang_wishlist);
        }
        PrintForward(*user_wishlist);
        break;
    }
     printf("Anda sudah keluar dari WISHLIST REMOVE!\n");
}