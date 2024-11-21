#ifndef __SAVE_H__
#define __SAVE_H__

#include <stdlib.h>
#include "../../misc.h"
#include "../ADT/array/array.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"

// save file baru atau overwrite existing file
void save(const char *filename, TabUser *Users, ArrayDinBarang *array);

#endif