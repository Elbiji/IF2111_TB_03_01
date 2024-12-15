#ifndef _CART_REMOVE_
#define _CART_REMOVE_

#include <stdio.h>
#include "../../misc.h"
#include "../ADT/setmap/map.h"

boolean isInputCartRemove(char *input, int *amount, char *nama_barang);

void cart_remove(Map *keranjang, char *nama_barang_keranjang, int jumlah_barang);

#endif
