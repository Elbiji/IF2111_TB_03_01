#include "misc.h"

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

IdxType IndexJobInList(job listjob[], int totaljob, char *str) {
    for (int i = 0; i < totaljob; i++) {
        boolean exist = true; 
        int j = 0;

        while (listjob[i].name[j] != '\0' && str[j] != '\0') { 
            if (listjob[i].name[j] != str[j]) { 
                exist = false;
                break;
            }
            j++;
        }

        if (exist && listjob[i].name[j] == '\0' && str[j] == '\0') {
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
    int i = items_request.idxHead;
    while (true){
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

        if (i == items_request.idxTail){
            break;
        }
        i = (i+1) % CAPACITY;
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

boolean isStrEqual(char *str1, char *str2){
    if (strLength(str1) != strLength(str2)){
        return false;
    }
    int i;
    for (i = 0; i < strLength(str2); i++){
        if (str1[i] != str2[i]){
            return false;
        }
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

int strLength(char *str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

void copystrng(char *dest, const char *src) {
    while (*src) {      
        *dest = *src;    
        dest++;          
        src++;          
    }
    *dest = '\0';       
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

boolean containsSpace(const char *str){
    while (*str) {
        if (*str == ' ') return true;
        str++;
    }
    return false;
}

int strToInteger (){
    START("","");
    while (!IsEOP() && (GetCC() == '\n' || GetCC() == ' ')) {
        ADV();
    } // Clearing buffer
    int val = 0;

    while (!IsEOP() && GetCC() != '\n'){
        if (GetCC() >= '0' && GetCC() <= '9'){
            val = val * 10 + (GetCC() - '0'); // Parsing one by one
        } else {
            return -1;
        }
        ADV();
    }
    return val;
}

boolean readCommand(char *buffer, int maxLen){
    START("","");

    while (!IsEOP() && (GetCC() == ' ' || GetCC() == '\n')){
        ADV();
    }

    int i = 0;
    while (!IsEOP() && GetCC() != '\n' && i < maxLen-1 && GetCC() != ' '){
        buffer[i++] = GetCC();
        ADV();
    }
    buffer[i] = '\0';

    if (!IsEOP() && GetCC() != '\n' && GetCC() != ' ') {
        while (!IsEOP() && GetCC() != '\n') {
            ADV();
        }
        printf("Command terlalu panjang! (max %d karakter)\n", maxLen-1);
        return false;
    }

    while (!IsEOP() && GetCC() != '\n'){
        ADV();
    }
    // printf("Tidak terdapat command tersebut dalam program!\n");
    return false;
}
// int main(){
//     START("","");
//     if (!isStrEqual(CurrentWord, "START")){
//         printf("Kata beda\n");
//     } else {
//         printf("Kata sama\n");
//     }
// }
