#ifndef __STORE_REQ_H_
#define __STORE_REQ_H_

#include <stdlib.h>

// #include "start.h"
#include "misc.h"
#include "../ADT/array/array.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/queue/queue.h"
#include "../ADT/boolean/boolean.h"

// Menambahkan barang ke dalam antrian
void store_request(Queue *items_request, ArrayDinBarang array);

#endif