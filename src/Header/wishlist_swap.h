#ifndef _WISHLIST_SWAP__
#define _WISHLIST_SWAP__

#include <stdio.h>
#include "../../misc.h"
#include "../ADT/listlinier/dplinkedlist.h"

// Memeriksa input pengguna yang berhubungan dengan
// wishlist_remove <i> dan wishlist swap <i> <j>
boolean isInputWishlistSwap (char *input, int *posisi1, int *posisi2);

// Menerima masukkan berupa tabuser, arraydin, serta id user untuk memasukkan
// barang ke daftar wishlist pengguna
void wishlist_swap (List *user_wishlist, int pos1, int pos2);

#endif