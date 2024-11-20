#include "../Header/main.h"

int main() {
    boolean isloggedin = false;
    char perintah[50];
    TabUser user;
    IdxType userid;
    ArrayDinBarang items;
    Queue item_req;
    MakeArrayDinBarang(&items);
    CreateQueue(&item_req);
    start(&user, &items);
    
    // Print results to verify
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

    // Print results to verify
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
    
    registerUser(&user);
    
    printf("\nLoaded Users:\n");
    for (int i = 0; i <  user.Neff; i++) {
        printf("User %d: %s (Money: %d)\n", 
               i+1, user.TC[i].name, user.TC[i].money);
    }

    if (isloggedin == false){
        login(user, &userid, &isloggedin);
    }

    login(user, &userid, &isloggedin);
    

    // login(user,);

    printf("\nLoaded Users:\n");
    for (int i = 0; i <  user.Neff; i++) {
        printf("User %d: %s (Money: %d)\n", 
               i+1, user.TC[i].name, user.TC[i].money);
    }

    store_request(&item_req, items);
    displayQueue(item_req);
    store_sup(&item_req, &items, userid, &user);
    displayQueue(item_req);
    store_rmv(&items);

    printf("\nLoaded Items:\n");
    for (int i = 0; i < items.Neff; i++) {
        printf("Item %d: %s (Price: %d)\n", 
               i+1, items.A[i].name, items.A[i].price);
    }
    displayQueue(item_req);

    DisplayStore(items);
    // DoWork(&user, userid);

    // char namauser[50];
    // printf("Masukkan sebuah nama user: \n");
    // readInput(namauser, MAX_LEN);

    // if (!isUserInFile(user, namauser)){
    //     printf("Tidak ada user bernama %s\n", namauser);
    //     printf("%d\n", IndexUserInFile(user, namauser));
    // } else {
    //     printf("Terdapat user bernama %s\n", namauser);
    //     printf("%d\n", IndexUserInFile(user, namauser));
    // }

    displayQueue(item_req);
    store_request(&item_req, items);
    displayQueue(item_req);
    store_sup(&item_req, &items, userid, &user);
    displayQueue(item_req);
    store_rmv(&items);

    printf("\nLoaded Items:\n");
    for (int i = 0; i < items.Neff; i++) {
        printf("Item %d: %s (Price: %d)\n", 
               i+1, items.A[i].name, items.A[i].price);
    }

    // while (1){
    //     readInput(perintah, MAX_LEN);
    //     if (isStrEqual(perintah, "START")){
    //         printf("START PROGRAM! \n");
    //     } else if (isStrEqual(perintah, "STOP")){
    //         break;
    //     } else {
    //         printf("Tidak tedapat command tersebut!\n");
    //     }
    // }
    tebakAngka(userid, &user);
    load(&user, &items);
    
    
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

    

    DeallocateArrayDinBarang(&items);
    return 0;
}