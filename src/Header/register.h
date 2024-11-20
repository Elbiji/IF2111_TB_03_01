#ifndef REGISTER_H
#define REGISTER_H

#include "login.h" // Gunakan login.h untuk akses struktur User dan TabUser

// Deklarasi fungsi registrasi
int registerUser(TabUser *list, char *username, char *password, int money);

#endif
