#ifndef _WISHLIST_SWAP__
#define _WISHLIST_SWAP__

#include <stdio.h>
#include "../../misc.h"
#include "../ADT/listlinier/dplinkedlist.h"

// Menerima masukkan berupa tabuser, arraydin, serta id user untuk memasukkan
// barang ke daftar wishlist pengguna
void wishlist_swap (TabUser *user_wishlist, IdxType userid, int pos1, int pos2);

#endif