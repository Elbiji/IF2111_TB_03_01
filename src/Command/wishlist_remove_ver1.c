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
        DelFirst(user_wishlist, &(user_wishlist->First));
    } else if (tot_wishlist > 1){
        if (pos1 == 1){
            DelFirst(user_wishlist,  &(user_wishlist->First)); 
        } else if (pos1 == tot_wishlist){
            DelLast (user_wishlist,  &(user_wishlist->Last));
        } else {
            addressDP P = user_wishlist->First;
            addressDP Pdel;
            int ctr = 1;
            while (ctr != pos1-1){
                P = Next(P);
                ctr++;
            }
            Pdel = Next(P);
            DelAfter(user_wishlist, &Pdel, P);
        }
    }
}