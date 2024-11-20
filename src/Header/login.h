#ifndef LOGIN_H
#define LOGIN_H

#include "../ADT/boolean/boolean.h"
#include "../Header/misc.h"
#include "../ADT/array/array.h"

// Batasan panjang username dan password
#define MAX_USERNAME_LEN 49
#define MIN_PASSWORD_LEN 6
#define MAX_PASSWORD_LEN 12


// Fungsi login
int login(TabUser list, User *currentUser);

#endif
