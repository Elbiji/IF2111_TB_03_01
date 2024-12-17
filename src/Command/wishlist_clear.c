#include "../Header/wishlist_clear.h"

void wishlist_clear(TabUser *user_wishlist, IdxType userid) {
    List *wishlist = &(user_wishlist->TC[userid].wishlist);
    info_barang temp; 

    while (!IsEmptyLDP(*wishlist)) {
        DelVFirst(wishlist, &temp);
    }

    printf("Wishlist telah dikosongkan.\n");
}
