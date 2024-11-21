#ifndef __STORE_SUP_H_
#define __STORE_SUP_H_

#include <stdlib.h>

// #include "start.h"
// #include "store_req.h"
#include "../../misc.h"
#include "../ADT/array/array.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/queue/queue.h"
#include "../ADT/boolean/boolean.h"

// Menvalidasi antrian dimasukkan atau tidak
void store_sup(Queue *items_request, ArrayDinBarang *array, IdxType Iduser, TabUser *user);

#endif