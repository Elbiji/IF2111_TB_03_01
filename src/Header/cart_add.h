#ifndef __CARD_ADD_H_
#define __CARD_ADD_H_

#include <stdio.h>
#include <stdlib.h>

#include "../../misc.h"
#include "../ADT/array/array.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/queue/queue.h"
#include "../ADT/boolean/boolean.h"
#include "../ADT/setmap/map.h"

char nama_barang_keranjang[50];
int jumlah_barang;

// Fungsi untuk menambahkan barang ke keranjang
// Menerima masukkan nama barang dan kuantitas barang yang ingin ditambahkan ke keranjang
void cart_add(Map *keranjang, Map *shop, char *nama_barang_keranjang, int jumlah_barang);

#endif




