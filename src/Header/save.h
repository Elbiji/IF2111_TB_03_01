#ifndef __SAVE_H__
#define __SAVE_H__

#include "load.h"
#include <stdlib.h>
#include "../../misc.h"
#include "../ADT/array/array.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/listlinier/dplinkedlist.h"
#include "../ADT/stack/stack.h"

// save file baru atau overwrite existing file
void save(TabUser *Users, ArrayDinBarang *array);

#endif