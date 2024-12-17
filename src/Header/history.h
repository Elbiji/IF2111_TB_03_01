#ifndef HISTORY_H
#define HISTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../ADT/stack/stack.h"

boolean isInputHistory(char *input,int *posisi1);
void displayHistory(Stack *user_history, int n);


#endif