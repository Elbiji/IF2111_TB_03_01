#include "../Header/wishlist_show.h"

void wishlist_show(TabUser *user_wishlist, IdxType userid) {
    List wishlist = user_wishlist->TC[userid].wishlist;

    if (IsEmptyLDP(wishlist)) {
        printf("Wishlist kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi wishlist-mu:\n");
    int index = 1;
    addressDP current = First(wishlist);

    while (current != Kosong) { 
        printf("%d. %s\n", index++, Info(current));
        current = Next(current);
    }
}
