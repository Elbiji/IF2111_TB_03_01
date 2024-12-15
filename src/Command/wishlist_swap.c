#include "../Header/wishlist_swap.h"

boolean isInputWishlistSwap(char *input,int *posisi1, int *posisi2){
    const char *command = "WISHLIST SWAP";
    int i = 0;

    while (command[i] != '\0'){
        if (input[i] != command[i]){
            return false;
        }
        i++;
    }

    while (input[i] == ' '){
        i++;
    }

    char num1[10];
    int j = 0;
    while (input[i] >= '0' && input[i] <= '9' && j < 9){
        num1[j++] = input[i++];
    }
    num1[j] = '\0';
    *posisi1 = atoi(num1);

    while (input[i] == ' '){
        i++;
    }

    char num2[10];
    j = 0;
    while (input[i] >= '0' && input[i] <= '9' && j < 9){
        num2[j++] = input[i++];
    }
    num2[j] = '\0';
    *posisi2 = atoi(num2);


    while (input[i] != '\0') {
        if (input[i] != ' ') {
            return false;
        }
        i++;
    }

    if (*posisi1 > 0 && *posisi2 > 0){
        return true;
    }
    else{
        return false;
    }

    return true;
}

void wishlist_swap (List *user_wishlist, int pos1, int pos2){
    addressDP P1 = First(*user_wishlist);
    addressDP P2 = First(*user_wishlist);
    info_barang temp;
    int ctr;
    ctr = 1;
    while (ctr != pos1) {
        P1 = Next(P1);
        ctr++;
    }
    // printf("n\n");
    // printf("%s\n", P1->info);
    ctr = 1;
    while (ctr != pos2) {
        P2 = Next(P2);
        ctr++;
    }
    // printf("n\n");
    // printf("%s\n", P2->info);

    stringCopy(temp,P1->info);
    stringCopy(P1->info, P2->info);
    stringCopy(P2->info, temp);

    printf("Berhasil menukar %s dengan %s pada wishlist!\n", temp, P1->info);
}