#ifndef __LOAD_H__
#define __LOAD_H__

#include <stdlib.h>

#include "../../misc.h"
#include "../ADT/array/array.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"

// Load file baru
void load(TabUser *Users, ArrayDinBarang *array);


// customStrcat("save/", filename);
void customStrcat(char *dest, char *src);

#endif
