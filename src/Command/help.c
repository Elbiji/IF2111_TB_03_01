#include "../Header/help.h"

MenuState current_menu = welcome_menu;

//fungsi untuk menampilkan HELP sesuai menu aktif
void help(MenuState *current_menu) {
    if (*current_menu == welcome_menu) {
        printf("=====[ Welcome Menu Help PURRMART ]=====\n");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("3. QUIT -> Untuk keluar dari program\n");
    } else if (*current_menu == login_menu) {
        printf("=====[ Login Menu Help PURRMART ]=====\n");
        printf("1. REGISTER -> Untuk melakukan pendaftaran akun baru\n");
        printf("2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("3. QUIT -> Untuk keluar dari program\n");
    } else if (*current_menu == main_menu) {
        printf("=====[ Menu Help PURRMART ]=====\n");
        printf("1. PROFILE -> Untuk melihat informasi akun\n");
        printf("2. WORK -> Untuk bekerja\n");
        printf("3. WORK CHALLENGE -> Untuk mengerjakan challenge\n");
        printf("4. STORE LIST -> Untuk melihat barang-barang di toko\n");
        printf("5. STORE REQUEST -> Untuk meminta penambahan barang\n");
        printf("6. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
        printf("7. STORE REMOVE -> Untuk menghapus barang\n");
        printf("8. CART ADD <nama> <i>-> Untuk menambah barang ke keranjang\n");
        printf("9. CART REMOVE <nama> <i>-> Untuk menghapus barang dari keranjang\n");
        printf("10. CART SHOW -> Untuk melihat isi keranjang\n");
        printf("11. CART PAY -> Untuk melakukan pembayaran\n");
        printf("12. HISTORY -> Untuk melihat riwayat transaksi\n");
        printf("13. WISHLIST ADD -> Untuk menambah barang ke wishlist\n");
        printf("14. WISHLIST SWAP <i> <j>-> Untuk menukar barang di wishlist\n");
        printf("15. WISHLIST REMOVE <i> -> Untuk menghapus barang dengan posisi ke-i dari wishlist\n");
        printf("16. WISHLIST REMOVE -> Untuk menghapus barang berdasarkan nama barang dari wishlist\n");
        printf("17. WISHLIST SHOW -> Untuk melihat wishlist\n");
        printf("18. WISHLIST CLEAR -> Untuk membersihkan wishlist\n");
        printf("19. LOGOUT -> Untuk keluar dari sesi\n");
        printf("20. SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("21. QUIT -> Untuk keluar dari program\n");
        printf("22. QUANTUM WORDL3 -> main game dulu bozz\n");
    }
}

//fungsi ganti menu
void change_menu(MenuState *current_menu, MenuState new_menu) {
    *current_menu = new_menu;
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