#ifndef HISTORY_H
#define HISTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../ADT/stack/stack.h"

#define MAX_NAME_LENGTH 50

typedef struct Purchase {
    char itemName[MAX_NAME_LENGTH];
    int quantity;
    struct Purchase *next;
} Purchase;

typedef struct {
    Purchase *head;
    int count;
} History;

History *createHistory();
void addPurchase(History *history, char *itemName, int quantity);
void displayHistory(History *history, int n);
void freeHistory(History *history);

#endif