#include "../Header/start.h"
#include "../ADT/array/array.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/array/array.c"
#include "../ADT/mesinkarakter/mesinkarakter.c"
#include "../ADT/mesinkata/mesinkata.c"

int totalinventory;
int totaluser;

void start(TabUser *Users){
    MakeEmpty(Users);
    //STARTWORD("../../save/default.txt", "r");
    STARTWORD("2.txt", "r");
    totaluser = atoi(CurrentWord.TabWord);

    for (int i = 0; i < totaluser; i++){
        ADVWORD();
        Users->TC[i].money = atoi(CurrentWord.TabWord);

        ADVWORD();
        for (int j = 0; j < CurrentWord.Length; j++){
            Users->TC[i].name[j] = CurrentWord.TabWord[j];
        }
        Users->TC[i].name[CurrentWord.Length] = '\0';

        ADVWORD();
        for (int j = 0; j < CurrentWord.Length; j++){
            Users->TC[i].password[j] = CurrentWord.TabWord[j];
        }
        Users->TC[i].password[CurrentWord.Length] = '\0';
    }
    
    for (int i = 0; i < totaluser; i++)
    {
        printf("%s : %d\n", Users->TC[i].name, Users->TC[i].money);
    }
    
}
    




int main(){
    TabUser user;
    start(&user);
}