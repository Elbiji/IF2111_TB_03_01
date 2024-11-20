#include <stdio.h>
#include "../Header/logout.h"

// Fungsi Logout
void logout(boolean *isLogged, TabUser list, IdxType *iduser) {
    if (*isLogged == false) {
        printf("Anda belum login.\n");
    } else {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", list.TC[iduser].name);
        *isLogged = false;
        *iduser = IdxUndef;
    }
}
