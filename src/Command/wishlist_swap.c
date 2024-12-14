#include "../Header/wishlist_swap.h"

void wishlist_swap (List *user_wishlist, int pos1, int pos2){
    addressDP P1 = First(*user_wishlist);
    addressDP P2 = First(*user_wishlist);
    info_barang temp;
    int ctr;
    ctr = 1;
    while (ctr != pos1) {
        P1 = Next(P1);
        ctr++;
    }
    // printf("n\n");
    // printf("%s\n", P1->info);
    ctr = 1;
    while (ctr != pos2) {
        P2 = Next(P2);
        ctr++;
    }
    // printf("n\n");
    // printf("%s\n", P2->info);

    stringCopy(temp,P1->info);
    stringCopy(P1->info, P2->info);
    stringCopy(P2->info, temp);

    printf("Berhasil menukar %s dengan %s pada wishlist!\n", temp, P1->info);
}