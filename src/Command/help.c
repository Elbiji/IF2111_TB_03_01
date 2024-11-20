#include "../Header/help.h"

MenuState current_menu = welcome_menu;

//fungsi untuk menampilkan HELP sesuai menu aktif
void help() {
    if (current_menu == welcome_menu) {
        printf("=====[ Welcome Menu Help PURRMART ]=====\n");
        printf("1. START → Untuk masuk sesi baru\n");
        printf("2. LOAD → Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("3. QUIT → Untuk keluar dari program\n");
    } else if (current_menu == login_menu) {
        printf("=====[ Login Menu Help PURRMART ]=====\n");
        printf("1. REGISTER → Untuk melakukan pendaftaran akun baru\n");
        printf("2. LOGIN → Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("3. QUIT → Untuk keluar dari program\n");
    } else if (current_menu == main_menu) {
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

//fungsi ganti menu
void change_menu(MenuState new_menu) {
    current_menu = new_menu;
}

//fungsi utama
// int main() {
//     char command[MAX_LEN];

//     printf("Welcome to PURRMART!\n");
//     while (1) {
//         printf("Enter command: ");
//         if (!readInput(command, MAX_LEN)) {
//             printf("Input tidak valid, silakan coba lagi.\n");
//             continue;
//         }

//         if (isStrEqual(command, "HELP")) {
//             help();
//         } else if (isStrEqual(command, "START")) {
//             printf("START command executed.\n");
//             change_menu(login_menu); //pindah ke login_menu setelah START
//         } else if (isStrEqual(command, "QUIT")) {
//             printf("Exiting PURRMART. Goodbye!\n");
//             break;
//         } else if (isStrEqual(command, "LOGIN") && current_menu == login_menu) {
//             printf("LOGIN command executed.\n");
//             change_menu(main_menu); //pindah ke main_menu setelah LOGIN
//         } else if (isStrEqual(command, "LOGOUT") && current_menu == main_menu) {
//             printf("LOGOUT command executed.\n");
//             change_menu(welcome_menu); //kembali ke welcome_menu setelah LOGOUT
//         } else {
//             printf("Unknown command. Type HELP for available commands.\n");
//         }
//     }

//     return 0;
// }