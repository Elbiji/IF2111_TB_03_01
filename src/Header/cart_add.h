#ifndef __CARD_ADD_H_
#define __CARD_ADD_H_

#include <stdio.h>
#include <stdlib.h>

#include "../../misc.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/setmap/map.h"

// Fungsi untuk memastikan input pengguna merupakan
// CART ADD sebelum diproses ke prosedur CART ADD
boolean isInputCartAdd(char *input, int *amount, char *nama_barang);

// Fungsi untuk menambahkan barang ke keranjang
// Menerima masukkan nama barang dan kuantitas barang yang ingin ditambahkan ke keranjang
void cart_add(Map *keranjang, ArrayDinBarang shop, char *nama_barang_keranjang, int jumlah_barang);

#endif




