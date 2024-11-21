#include "../Header/main.h"

int main() {
    boolean isloggedin = false;
    char perintah[50];
    TabUser user;
    IdxType userid;
    ArrayDinBarang items;
    Queue item_req;
    MenuState current_menu = welcome_menu;
    MakeArrayDinBarang(&items);
    CreateQueue(&item_req);
    start(&user, &items);

    printf("Selamat datang di PURRMART. Untuk menjalankan program silahkan memasukkan perintah START atau LOAD\n");
    while(1){
        printf("Silahkan masukkan perintah yang sesuai\n");
        readInput(perintah, MAX_LEN);
        if (isStrEqual(perintah, "START")){
            if (isloggedin == false){
                printf(">>START\n");
                printf("STARTING PROGRAM . . .");
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
                printf("Untuk memulai sesi baru kamu diharuskan untuk logout terlebih dahulu\n");
            }
        }
        else if (isStrEqual(perintah, "QUIT")){
            break;
        }
        else if (isStrEqual(perintah, "LOAD")){
            if(isloggedin == false){
                printf(">>LOAD\n");
                printf("LOAD PROGRAM\n");
                load(&user, &items);
                printf("LOADING PROGRAM . . .");
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
                printf("Untuk memulai sesi baru kamu diharuskan untuk logout terlebih dahulu\n");
            }
        }
        else if (isStrEqual(perintah, "HELP")){
            help(&current_menu);
        }
        else if (isStrEqual(perintah, "LOGIN")){
            if (current_menu != login_menu){
                printf("Kamu diharuskan untuk memulai file konfigurasi terlebih dahulu!\n");
            } else {
                printf(">>LOGIN\n");
                login(user, &userid, &isloggedin);
                if (isloggedin == true){
                    change_menu(&current_menu, main_menu);
                }
            }
        }
        else if (isStrEqual(perintah, "REGISTER")){
            if (current_menu != login_menu || isloggedin == true){
                printf("Untuk registrasi diharuskan untuk keluar dari sesi sekarang!\n");
            } else {
                printf(">>REGISTER\n");
                registerUser(&user);
                isloggedin = false;
            }
        }
        else if (isStrEqual(perintah, "LOGOUT")){
            printf(">>LOGOUT\n");
            logout(&isloggedin, user, &userid);
            change_menu(&current_menu, login_menu);
        }
        else if (isStrEqual(perintah, "STORE REQUEST")){
            if (isloggedin == false){
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                printf(">>STORE REQUEST\n");
                store_request(&item_req, items);
            }
        }
        else if (isStrEqual(perintah, "STORE SUPPLY")){
            if (isloggedin == false){
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                printf(">>STORE SUPPLY\n");
                store_sup(&item_req, &items, userid, &user);
            }
        }
        else if (isStrEqual(perintah, "STORE REMOVE")){
            if (isloggedin == false){
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                printf(">>STORE REMOVE\n");
                store_rmv(&items);
            }
        }
        else if (isStrEqual(perintah, "STORE LIST")){
            if (isloggedin == false){
                printf("Perintah belum bisa dijalankan, karena anda belom LOGIN!\n");
            } else {
                printf(">>STORE LIST\n");
                DisplayStore(items);
            }
        }
    }
    


    
    // registerUser(&user);
    
    // printf("\nLoaded Users:\n");
    // for (int i = 0; i <  user.Neff; i++) {
    //     printf("User %d: %s (Money: %d)\n", 
    //            i+1, user.TC[i].name, user.TC[i].money);
    // }

    // if (isloggedin == false){
    //     login(user, &userid, &isloggedin);
    // }

    // login(user, &userid, &isloggedin);
    

    

    // printf("\nLoaded Users:\n");
    // for (int i = 0; i <  user.Neff; i++) {
    //     printf("User %d: %s (Money: %d)\n", 
    //            i+1, user.TC[i].name, user.TC[i].money);
    // }

    // store_request(&item_req, items);
    // displayQueue(item_req);
    // store_sup(&item_req, &items, userid, &user);
    // displayQueue(item_req);
    // store_rmv(&items);

    // printf("\nLoaded Items:\n");
    // for (int i = 0; i < items.Neff; i++) {
    //     printf("Item %d: %s (Price: %d)\n", 
    //            i+1, items.A[i].name, items.A[i].price);
    // }
    // displayQueue(item_req);

    // DisplayStore(items);
    // // DoWork(&user, userid);

    // // char namauser[50];
    // // printf("Masukkan sebuah nama user: \n");
    // // readInput(namauser, MAX_LEN);

    // // if (!isUserInFile(user, namauser)){
    // //     printf("Tidak ada user bernama %s\n", namauser);
    // //     printf("%d\n", IndexUserInFile(user, namauser));
    // // } else {
    // //     printf("Terdapat user bernama %s\n", namauser);
    // //     printf("%d\n", IndexUserInFile(user, namauser));
    // // }

    // displayQueue(item_req);
    // store_request(&item_req, items);
    // displayQueue(item_req);
    // store_sup(&item_req, &items, userid, &user);
    // displayQueue(item_req);
    // store_rmv(&items);

    // printf("\nLoaded Items:\n");
    // for (int i = 0; i < items.Neff; i++) {
    //     printf("Item %d: %s (Price: %d)\n", 
    //            i+1, items.A[i].name, items.A[i].price);
    // }

    // // while (1){
    // //     readInput(perintah, MAX_LEN);
    // //     if (isStrEqual(perintah, "START")){
    // //         printf("START PROGRAM! \n");
    // //     } else if (isStrEqual(perintah, "STOP")){
    // //         break;
    // //     } else {
    // //         printf("Tidak tedapat command tersebut!\n");
    // //     }
    // // }
    // tebakAngka(userid, &user);
    // load(&user, &items);
    
    
    // printf("\nLoaded Users:\n");
    // for (int i = 0; i <  user.Neff; i++) {
    //     printf("User %d: %s (Money: %d)\n", 
    //            i+1, user.TC[i].name, user.TC[i].money);
    // }
    
    // printf("\nLoaded Items:\n");
    // for (int i = 0; i < items.Neff; i++) {
    //     printf("Item %d: %s (Price: %d)\n", 
    //            i+1, items.A[i].name, items.A[i].price);
    // }

    

    // DeallocateArrayDinBarang(&items);
    // return 0;
}