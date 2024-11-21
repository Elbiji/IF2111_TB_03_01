#include "../Header/quit.h"

void quit(TabUser *User, ArrayDinBarang *item) {
    char input[1];

    printf("\nApakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    do {
        if(!readInput(input, MAX_LEN)) continue;
        if (isStrEqual(input, "Y") || isStrEqual(input, "y")) {
            save(User, item);
            printf("\nKamu keluar dari PURRMART.\nDadah ^_^/\n");
            exit(0);
        } else if (isStrEqual(input, "N") || isStrEqual(input, "n")) {
            printf("\nKamu keluar dari PURRMART.\nDadah ^_^/\n");
            exit(0);
        } else if (input != '\n') {
            printf("Masukkan tidak valid. Harap pilih Y atau N: ");
        }
    } while (1);
}