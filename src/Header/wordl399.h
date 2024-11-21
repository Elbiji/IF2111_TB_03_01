#ifndef __WORDL399_H_
#define __WORDL399_H_

#define MAX_CHANCES 5
#define WORD_LENGTH 5
#define MAX_LEN 50

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "misc.h"

#include "../ADT/boolean/boolean.h"
#include "../ADT/array/array.h"

// daftar kata valid
const char *valid_words[] = {"kotak", "katak", "demon", "dokja"};
const int word_count = sizeof(valid_words) / sizeof(valid_words[0]);

#endif