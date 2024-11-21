#include <stdio.h>
#include "../Header/login.h"


// Fungsi Login
void login(TabUser list, IdxType *userid, boolean *islogged) { // Login pengguna dengan loop untuk input ulang
    char username[50], password[50];
    IdxType index;
    int ctr = 0;

    if (*islogged == true){
        printf("Kamu sudah sudah masuk sebagai %s.\n", list.TC[*userid].name);
        return;
    }

    while (ctr < 5) {
        // Input username
        printf("Masukkan username: ");
        if (!readInput(username, 50)) continue; // Ulang jika input gagal

        while (1){
            // Input password
            printf("Masukkan password: ");
            if (!readInput(password, 20)) continue; // Ulang jika input gagal
            ctr++;
            break;
        }
        
        // Validasi username dan password
        index = IndexUserInFile(list, username);
        if (isUserInFile(list, username) && isStrEqual(list.TC[index].password, password)) {
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
            *islogged = true;
            *userid = index;
            return; 
        } else {
            printf("Username atau password salah. Coba lagi.\n");
            continue;
        }
        ctr++;
    }
    printf("Sudah terlalu banyak percobaan, anda akan dikembalikan ke laman utama!\n");
    *islogged = false;
}