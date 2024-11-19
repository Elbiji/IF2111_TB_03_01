#ifndef __STORE_RMV_H__
#define __STORE_RMV_H__

#include <stdlib.h>

#include "store_req.h"
#include "store_sup.h"
#include "misc.h"
#include "../ADT/array/array.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/queue/queue.h"
#include "../ADT/boolean/boolean.h"

// Menghapuskan barang dalam shop berdasarkan nama
void store_rmv(ArrayDinBarang *array);

#endif