#ifndef __WORDL399_H_
#define __WORDL399_H_

#define MAX_CHANCES 5
#define WORD_LENGTH 5
#define MAX_LEN 50
#define QUANTUM_WORD_COUNT 4
#define MAX_QUANTUM_CHANCES 9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../misc.h"
#include "../ADT/boolean/boolean.h"
#include "../ADT/array/array.h"

void play_quantum_wordl(TabUser *users, IdxType userIdx);
extern const char *valid_words[];
extern const int word_count;

#endif
