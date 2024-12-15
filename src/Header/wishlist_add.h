#ifndef _WISHLIST_ADD_
#define _WISHLIST_ADD_

#include <stdio.h>
#include "../../misc.h"
#include "../ADT/listlinier/dplinkedlist.h"

// Menerima masukkan berupa tabuser, arraydin, serta id user untuk memasukkan
// barang ke daftar wishlist pengguna
void wishlist_add (TabUser *user_wishlist, ArrayDinBarang item_shop, IdxType userid);

#endif