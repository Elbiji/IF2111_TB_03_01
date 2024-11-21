#include "../Header/quit.h"

extern TabUser userList;        // Data pengguna global
extern ArrayDinBarang itemList; // Data barang global

void quit() {
    char input;
    char filename[256] = "savefile.txt"; // Nama default file penyimpanan

    printf("\nApakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    do {
        input = getchar();
        if (input == 'Y' || input == 'y') {
            save(filename, &userList, &itemList);
            printf("\nKamu keluar dari PURRMART.\nDadah ^_^/\n");
            exit(0);
        } else if (input == 'N' || input == 'n') {
            printf("\nKamu keluar dari PURRMART.\nDadah ^_^/\n");
            exit(0);
        } else if (input != '\n') {
            printf("Masukkan tidak valid. Harap pilih Y atau N: ");
        }
    } while (1);
}