#include "../Header/wishlist_remove_ver1.h"

boolean isInputWishlistRemove(char *input,int *posisi1){
    const char *command = "WISHLIST REMOVE";
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

    if (*posisi1 > 0 ){
        return true;
    }
    else{
        return false;
    }

    return true;
}

void wishlist_remove1(List *user_wishlist, int pos1, int tot_wishlist){
    if (tot_wishlist == 1 && pos1 == 1){
        DelP(user_wishlist, user_wishlist->First->info);
    } else if (tot_wishlist > 1){
        if (pos1 == 1){
            DelP(user_wishlist, user_wishlist->First->info); 
        } else if (pos1 == tot_wishlist){
            DelP(user_wishlist, user_wishlist->Last->info);
        } else {
            addressDP P = First(*user_wishlist);
            for (int i = 1; i < pos1;i++){
                P = Next(P);
            }
            DelP(user_wishlist, P->info);
        }
    }
}