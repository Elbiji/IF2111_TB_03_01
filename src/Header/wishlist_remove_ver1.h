#ifndef _WISHLIST_REMOVE_1_
#define _WISHLIST_REMOVE_1_

#include <stdio.h>
#include "../../misc.h"
#include "../ADT/listlinier/dplinkedlist.h"

// Memeriksa format input Remove <i>
boolean isInputWishlistRemove(char *input,int *posisi1);

void wishlist_remove1(List *user_wishlist, int pos1, int tot_wishlist);

#endif