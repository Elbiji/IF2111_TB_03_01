#include <stdio.h>
#include "../Header/profile.h"

// Fungsi Profile
void profile(boolean isLogged, TabUser list, IdxType iduser) {
    if (isLogged == false) {
        printf("Anda belum login.\n");
    } else {
        printf("Nama: %s\n", list.TC[iduser].name);
        printf("Username: %s\n", list.TC[iduser].name);
        printf("Saldo: %d\n", list.TC[iduser].money);
    }
}
