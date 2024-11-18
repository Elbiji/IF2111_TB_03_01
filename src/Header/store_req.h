#ifndef __STORE_REQ_H_
#define __STORE_REQ_H_

#include <stdlib.h>

#include "start.h"
#include "../ADT/array/array.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/queue/queue.h"
#include "../ADT/boolean/boolean.h"

// Menambahkan barang ke dalam antrian
void store_request(Queue *items_request, ArrayDinBarang array);

// Mengecek apakah barang ada di toko
boolean isItemInShop(ArrayDinBarang array, char *str);

// Memeriksa panjang string
int strLength(char *str);

// Memeriksa apakah input merupakan angka semua
boolean isStrAllDigit (char *str);

#endif