#include "../Header/help.h"
MenuState current_menu = WELCOME_MENU;

// Fungsi untuk menampilkan HELP berdasarkan menu aktif
void help() {
    if (current_menu == WELCOME_MENU) {
        printf("=====[ Welcome Menu Help PURRMART ]=====\n");
        printf("1. START → Untuk masuk sesi baru\n");
        printf("2. LOAD → Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("3. QUIT → Untuk keluar dari program\n");
    } else if (current_menu == LOGIN_MENU) {
        printf("=====[ Login Menu Help PURRMART ]=====\n");
        printf("1. REGISTER → Untuk melakukan pendaftaran akun baru\n");
        printf("2. LOGIN → Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("3. QUIT → Untuk keluar dari program\n");
    } else if (current_menu == MAIN_MENU) {
        printf("=====[ Menu Help PURRMART ]=====\n");
        printf("1. WORK → Untuk bekerja\n");
        printf("2. WORK CHALLENGE → Untuk mengerjakan challenge\n");
        printf("3. STORE LIST → Untuk melihat barang-barang di toko\n");
        printf("4. STORE REQUEST → Untuk meminta penambahan barang\n");
        printf("5. STORE SUPPLY → Untuk menambahkan barang dari permintaan\n");
        printf("6. STORE REMOVE → Untuk menghapus barang\n");
        printf("7. LOGOUT → Untuk keluar dari sesi\n");
        printf("8. SAVE → Untuk menyimpan state ke dalam file\n");
        printf("9. QUIT → Untuk keluar dari program\n");
    }
}

// Fungsi untuk mengganti menu
void change_menu(MenuState new_menu) {
    current_menu = new_menu;
}

int main() {
    char command[MAX_LEN];

    printf("Welcome to PURRMART!\n");
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "HELP") == 0) {
            help();
        } else if (strcmp(command, "START") == 0) {
            printf("START command executed.\n");
            change_menu(LOGIN_MENU);  // Pindah ke LOGIN_MENU setelah START
        } else if (strcmp(command, "QUIT") == 0) {
            printf("Exiting PURRMART. Goodbye!\n");
            break;
        } else if (strcmp(command, "LOGIN") == 0 && current_menu == LOGIN_MENU) {
            printf("LOGIN command executed.\n");
            change_menu(MAIN_MENU);  // Pindah ke MAIN_MENU setelah LOGIN
        } else if (strcmp(command, "LOGOUT") == 0 && current_menu == MAIN_MENU) {
            printf("LOGOUT command executed.\n");
            change_menu(WELCOME_MENU);  // Kembali ke WELCOME_MENU setelah LOGOUT
        } else {
            printf("Unknown command. Type HELP for available commands.\n");
        }
    }

    return 0;
}
