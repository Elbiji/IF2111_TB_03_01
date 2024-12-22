#ifndef _QUANTUM_WORDL3_H_
#define _QUANTUM_WORDL3_H_

#define MAX_CHANCES 5
#define WORD_LENGTH 5
#define MAX_LEN 50
#define QUANTUM_WORD_COUNT 4
#define MAX_QUANTUM_CHANCES 9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/boolean/boolean.h"
#include "../ADT/array/array.h"
#include "../../misc.h"

//test
void play_quantum_wordl(TabUser *users, IdxType userIdx);
extern const char *quantum_valid_words[];
extern const int quantum_word_count;

#endif
