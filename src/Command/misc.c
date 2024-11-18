#include "../Header/misc.h"

IdxType IndexItemInShop(ArrayDinBarang array, char *str){
    for (int i = 0; i < array.Neff; i++){
        boolean exist = true;
        int j = 0;

        while (array.A[i].name[j] != '\0' && str[j] != '\0'){
            if (array.A[i].name[j] != str[j]){
                exist = false;
                break;
            }
            j++;
        }

        if (exist && array.A[i].name[j] == '\0' && str[j] == '\0'){
            return i;
        }
    }
    return -1;
}

IdxType IndexUserInFile(TabUser Users, char *str){
    for (int i = 0; i < NbElmt(Users); i++){
        boolean exist = true;
        int j = 0;

        while (Users.TC[i].name[j] != '\0' && str[j] != '\0'){
            if(Users.TC[i].name[j] != str[j]){
                exist = false;
                break;
            }
            j++;
        }

        if (exist && Users.TC[i].name[j] == '\0' &&  str[j] == '\0'){
            return i;
        }
    }
    return -1;
}

boolean isDone(char *input){
    char *done = "Purry";
    for (int i = 0; input[i] != '\0' && done[i] != '\0'; i++){
        if (input[i] != done[i]){
            return false;
        }
    }
    return true;
}

boolean isItemInShop(ArrayDinBarang array, char *str){
    for (int i = 0; i < array.Neff; i++){
        boolean exist = true;
        int j = 0;

        while (array.A[i].name[j] != '\0' && str[j] != '\0'){
            if (array.A[i].name[j] != str[j]){
                exist = false;
                break;
            }
            j++;
        }

        if (exist && array.A[i].name[j] == '\0' && str[j] == '\0'){
            return true;
        }
    }
    return false;
}

boolean isItemInQueue(Queue items_request, char *str){
    for (int i = 0; i < length(items_request); i++){
        boolean exist = true;
        int j = 0;

        while (items_request.buffer[i].name[j] != '\0' && str[j] != '\0'){
            if (items_request.buffer[i].name[j] != str[j]){
                exist = false;
                break;
            }
            j++;
        }

        if (exist && items_request.buffer[i].name[j] == '\0' && str[j] == '\0'){
            return true;
        }
    }
    return false;
}

boolean isUserInFile(TabUser Users, char *str){
    for (int i = 0; i < NbElmt(Users); i++){
        boolean exist = true;
        int j = 0;

        while (Users.TC[i].name[j] != '\0' && str[j] != '\0'){
            if(Users.TC[i].name[j] != str[j]){
                exist = false;
                break;
            }
            j++;
        }

        if (exist && Users.TC[i].name[j] == '\0' &&  str[j] == '\0'){
            return true;
        }
    }
    return false;
}

boolean isStrAllDigit (char *str){
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9'){
            return false;
        }
        i++;
    }
    return true;
}

int strLength(char *str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

boolean readInput(char *buffer, int maxLen){
    START("","");

    while (!IsEOP() && (GetCC() == ' ' || GetCC() == '\n')){
        ADV();
    }

    int i = 0;
    while (!IsEOP() && GetCC() != '\n' && i < maxLen-1){
        buffer[i++] = GetCC();
        ADV();
    }
    buffer[i] = '\0';

    if (!IsEOP() && GetCC() != '\n') {
        while (!IsEOP() && GetCC() != '\n') {
            ADV();
        }
        printf("Input terlalu panjang! (max %d karakter)\n", maxLen-1);
        return false;
    }
    
    return true;

}
