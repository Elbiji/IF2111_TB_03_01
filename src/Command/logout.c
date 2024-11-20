#include <stdio.h>
#include "../Header/logout.h"

// Implementasi logout pengguna
void logout(User **currentUser) {
    if (*currentUser == NULL) {
        printf("Anda belum login.\n");
    } else {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", (*currentUser)->name);
        *currentUser = NULL;
    }
}
