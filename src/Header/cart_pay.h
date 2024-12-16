#ifndef _CART_PAY_
#define _CART_PAY_

#include <stdio.h>
#include <stdlib.h>
#include "../../misc.h"
#include "../ADT/setmap/map.h"
#include "../ADT/stack/stack.h"
#include "../ADT/array/array.h"

void CartPay(TabUser *T, IdxType userIdx, Map *cart, Stack *history);

#endif