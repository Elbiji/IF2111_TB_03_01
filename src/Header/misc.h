#ifndef __MISC_H_
#define __MISC_H_

#include <stdlib.h>

#include "../ADT/array/array.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/queue/queue.h"
#include "../ADT/boolean/boolean.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"

// Mengembalikan index sebuah barang pada toko menggunakan traversal
IdxType IndexItemInShop(ArrayDinBarang array, char *str);

// Mengkonfirmasi apakah proses dalam store supply dan store remove di terminasi
boolean isDone(char *input);

// Mencari nama barang pada toko menggunakan traversal
boolean isItemInShop(ArrayDinBarang array, char *str);

// Mencari nama barang pada antrian dengan traversal
boolean isItemInQueue(Queue items_request, char *str);

// Memeriksa apakah input semuanya merupakan digit
boolean isStrAllDigit (char *str);

int strLength(char *str);

#endif