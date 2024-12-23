#include "../Header/main.h"

int main() {
    boolean isloggedin = false;
    char perintah[50];
    char nama_barang[50];
    TabUser user;
    IdxType userid;
    ArrayDinBarang items;
    Queue item_req;
    MenuState current_menu = welcome_menu;
    MakeArrayDinBarang(&items);
    CreateQueue(&item_req);
    visual("welcome.txt");
    MakeEmpty(&user);
    printf("\n");
    int posisi1 = 0, posisi2 = 0, amount = 0;

    while(1){
        // printf("Silahkan masukkan perintah yang sesuai\n");
        readInput(perintah, MAX_LEN);
        if (isStrEqual(perintah, "START")){
            if (isloggedin == false){
                printf(">> START\n");
                printf("STARTING PROGRAM . . .\n");
                start(&user, &items);
                printf("\nLoaded Users:\n");
                for (int i = 0; i <  user.Neff; i++) {
                printf("User %d: %s (Money: %d)\n", 
                    i+1, user.TC[i].name, user.TC[i].money);
                }
                
                printf("\nLoaded Items:\n");
                for (int i = 0; i < items.Neff; i++) {
                printf("Item %d: %s (Price: %d)\n", 
                    i+1, items.A[i].name, items.A[i].price);
                }
                change_menu(&current_menu, login_menu);
            } else {
                printf("Untuk memulai sesi baru kamu diharuskan untuk LOGOUT terlebih dahulu\n");
            }
        }
        else if (isStrEqual(perintah, "QUIT")){
            if(user.Neff == 0){
                break;
            } else {
                quit(&user, &items);
                break;
            }
        }
        else if (isStrEqual(perintah, "PROFILE")){
            if (isloggedin == false){
                printf("Perintah belum bisa dijalankan, karena anda belum LOGIN!\n");
            } else {
                printf(">> PROFILE\n");
                profile(isloggedin, user, userid);
            }
        }
        else if (isStrEqual(perintah, "LOAD")){
            if(isloggedin == false){
                printf(">> LOAD\n");
                printf("LOAD PROGRAM\n");
                load(&user, &items);
                printf("LOADING PROGRAM . . .");
                printf("\nLoaded Users:\n");
                for (int i = 0; i <  user.Neff; i++) {
                printf("User %d: %s (Money: %d)\n", 
                    i+1, user.TC[i].name, user.TC[i].money);
                }
        
                printf("\nLoaded Items:\n");
                for (int i = 0; i < items.Neff; i++) {
                printf("Item %d: %s (Price: %d)\n", 
                    i+1, items.A[i].name, items.A[i].price);
                }
                change_menu(&current_menu, login_menu);
            } else {
                printf("Untuk memulai sesi baru kamu diharuskan untuk LOGOUT terlebih dahulu\n");
            }
        }
        else if (isStrEqual(perintah, "SAVE")){
            if (isloggedin == false){
                printf("Belum ada sesi yang dapat disimpan!\n");
            } else {
                save(&user, &items);
            }
        }
        else if (isStrEqual(perintah, "HELP")){
            help(&current_menu);
        }
        else if (isStrEqual(perintah, "LOGIN")){
            if (user.Neff == 0){
                printf("Kamu diharuskan untuk memulai file konfigurasi terlebih dahulu!\n");
            } else if (isloggedin){
                printf("Anda masih berada di sesi %s, silahkan logout terlebih dahulu!\n", user.TC[userid].name);
            } else {
                printf(">>LOGIN\n");
                login(user, &userid, &isloggedin);
                if (isloggedin == true){
                    change_menu(&current_menu, main_menu);
                }
            }
        }
        else if (isStrEqual(perintah, "REGISTER")){
            if (user.Neff == 0 || isloggedin){
                printf("Untuk registrasi diharuskan untuk memulai file konfigurasi terlebih dahulu atau anda diharuskan untuk keluar dari sesi user lain!\n");
            } else {
                printf(">> REGISTER\n");
                registerUser(&user);
                isloggedin = false;
            }
        }
        else if (isStrEqual(perintah, "LOGOUT")){
            if (isloggedin){
                printf(">> LOGOUT\n");
                logout(&isloggedin, user, &userid);
                change_menu(&current_menu, login_menu);
            } else {
                printf("Anda tidak berada di suatu sesi!\n");
            }
        }
        else if (isStrEqual(perintah, "STORE REQUEST")){
            if (isloggedin == false){
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                visual("storerequest.txt");
                if (isFull(item_req)){
                    printf("Antrian penuh, harap hilangkan atau masukkan beberapa barang dari antrian.\n");
                } else {
                    printf("\n");
                    printf(">> STORE REQUEST\n");
                    store_request(&item_req, items);
                }
            }
        }
        else if (isStrEqual(perintah, "STORE SUPPLY")){
            if (isloggedin == false){
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                visual("storesupply.txt");
                printf("\n");
                printf(">> STORE SUPPLY\n");
                store_sup(&item_req, &items, userid, &user);
            }
        }
        else if (isStrEqual(perintah, "STORE REMOVE")){
            if (isloggedin == false){
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                visual("storeremove.txt");
                printf("\n");
                printf(">>STORE REMOVE\n");
                store_rmv(&items);
            }
        }
        else if (isStrEqual(perintah, "STORE LIST")){
            if (isloggedin == false){
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                printf(">> STORE LIST\n");
                printf("\n");
                DisplayStore(items);
            }
        }
        else if (isStrEqual(perintah, "WORK CHALLENGE")){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                work_challenge(&user, userid);
            }
        }
        else if (isStrEqual(perintah, "WORK")){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                printf(">> WORK\n");
                DoWork(&user, userid);
            }
        }
        else if (isStrEqual(perintah, "WISHLIST ADD")){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                printf(">>> WISHLIST ADD\n");
                wishlist_add(&user, items, userid);
            }
        }
        else if (isStrEqual(perintah, "WISHLIST REMOVE")){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                if (IsEmptyLDP(user.TC[userid].wishlist)){
                    printf("Wishlist anda kosong!\n");
                } else {
                    wishlist_remove2(&(user.TC[userid].wishlist));
                }
            }
        }
        else if (isStrEqual(perintah, "WISHLIST SHOW")){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                printf(">> WISHLIST SHOW\n");
                wishlist_show(&user, userid);
            }
        }
        else if (isStrEqual(perintah, "WISHLIST CLEAR")){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                printf(">> WISHLIST CLEAR\n");
                wishlist_clear(&user.TC[userid].wishlist);
                printf("Wishlist berhasil dikosongkan!\n");
            }
        }
        else if (isStrEqual(perintah, "CART SHOW")){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                if (IsEmptyMap(user.TC[userid].keranjang)){
                    printf("Keranjang anda kosong!\n");
                    printf("Perintah tidak dijalankan!\n");
                } else {
                    cart_show(&(user.TC[userid].keranjang), &items);
                }
            }
        }
        else if (isStrEqual(perintah, "CART PAY")){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                if (IsEmptyMap(user.TC[userid].keranjang)){
                    printf("Keranjang anda kosong!\n");
                    printf("Perintah tidak dijalankan!\n");
                } else {
                    cart_pay(&user,userid, &(user.TC[userid].keranjang), &(user.TC[userid].riwayat_pembelian), items);
                }
            }
        }
        else if (isInputWishlistSwap(perintah, &posisi1, &posisi2)){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                int tot_wishlist = CountElmt(user.TC[userid].wishlist);
                if (tot_wishlist == 0){
                    printf("wishlist anda kosong!\n");
                } else if (tot_wishlist == 1){
                    printf("Hanya terdapat satu element dalam wishlist anda!\n");
                } else if (posisi1 == posisi2 || posisi1 > tot_wishlist || posisi2 > tot_wishlist || posisi1 == 0 || posisi2 == 0){
                    printf("Pastikan anda masukkan angka yang valid untuk melakukan swap!\n");
                    printf("e.g. WISHLIST SWAP <i> <j> dengan i dan j merupakan angka yang valid dalam wishlist anda! (integer positive dan tidak sama)\n");
                } else {
                    printf(">> WISHLIST SWAP %d %d\n", posisi1, posisi2);
                    // printf("sebelum SWAP\n");
                    // PrintForward(user.TC[userid].wishlist);
                    wishlist_swap(&(user.TC[userid].wishlist), posisi1, posisi2);
                    // printf("sesudah SWAP\n");
                    // PrintForward(user.TC[userid].wishlist);
                }
            }
        }
        else if (isInputWishlistRemove(perintah, &posisi1)){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                int tot_wishlist = CountElmt(user.TC[userid].wishlist);
                if (tot_wishlist == 0){
                    printf("wishlist anda kosong!\n");
                } else if (posisi1 > tot_wishlist){
                    printf("Pastikan anda masukkan angka yang valid untuk melakukan remove!\n");
                    printf("e.g. WISHLIST REMOVE <i> dengan i  merupakan angka yang valid dalam wishlist anda! (integer positive dan didalam indeks efektif)\n");
                } else {
                    printf(">> WISHLIST REMOVE %d\n", posisi1);
                    // PrintForward(user.TC[userid].wishlist);
                    wishlist_remove1(&(user.TC[userid].wishlist), posisi1, tot_wishlist);
                    // PrintForward(user.TC[userid].wishlist);
                    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", posisi1);
                }
            }
        }
        else if (isInputCartAdd(perintah, &amount, nama_barang)){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                if (IsFullMap(user.TC[userid].keranjang)){
                    printf("Keranjang anda penuh!\n");
                    printf("Perintah tidak dijalankan!\n");
                } else {
                    printf(">> CART ADD %s %d\n", nama_barang ,amount);
                    cart_add(&(user.TC[userid].keranjang), items, nama_barang ,amount);
                    // printf("%s : %d\n", user.TC[userid].keranjang.Elements[0].nama_barang_keranjang, user.TC[userid].keranjang.Elements[0].jumlah_barang);
                }
            }
        }
        else if (isInputCartRemove(perintah, &amount, nama_barang)){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                if (IsEmptyMap(user.TC[userid].keranjang)){
                    printf("Keranjang anda kosong!\n");
                    printf("Perintah tidak dijalankan!\n");
                } else {
                    printf(">> CART REMOVE %s %d\n", nama_barang ,amount);
                    cart_remove(&(user.TC[userid].keranjang), nama_barang, amount);
                    // printf("%s : %d\n", user.TC[userid].keranjang.Elements[0].nama_barang_keranjang, user.TC[userid].keranjang.Elements[0].jumlah_barang);
                }
            }
        }
        else if (isInputHistory(perintah, &amount)){
            if (isloggedin == false) {
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                if(IsEmptyStack(user.TC[userid].riwayat_pembelian)){
                    printf("Tidak ada riwayat pembelian!\n");
                } else {
                    printf(">> HISTORY %d\n", amount);
                    displayHistory(&user.TC[userid].riwayat_pembelian, amount);
                    printf("Penampilan riwayat selesai!\n");
                }
            }
        }
        else {
            printf("Perintah tidak valid!\n");
        }
    }
    visual("exit.txt");

    printf("\nLoaded Users:\n");
    for (int i = 0; i <  user.Neff; i++) {
    printf("User %d: %s (Money: %d)\n", 
        i+1, user.TC[i].name, user.TC[i].money);
    }
}
