#ifndef __WORDL399_H_
#define __WORDL399_H_

#define MAX_CHANCES 5
#define WORD_LENGTH 5
#define MAX_LEN 50

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../misc.h"

#include "../ADT/boolean/boolean.h"
#include "../ADT/array/array.h"

// daftar kata valid

void play_wordl(TabUser *users, IdxType userIdx);
extern const char *valid_words[];
extern const int word_count;

// void pick_random(char *word);
// boolean check_word(const char *word);


#endif
