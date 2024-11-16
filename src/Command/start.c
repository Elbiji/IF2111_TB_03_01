#include "../Header/start.h"
#include "../ADT/array/array.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/arraydin/arraydin.h"
#include "../ADT/array/array.c"
#include "../ADT/arraydin/arraydin.c"
#include "../ADT/mesinkarakter/mesinkarakter.c"
#include "../ADT/mesinkata/mesinkata.c"


int totalinventory;
int totalbarang_per_inventory;
int totaluser;
Barang inventory;
ArrayDinBarang array;

void start(TabUser *Users, ArrayDinBarang *array){
    MakeEmpty(Users);
    //STARTWORD("../../save/default.txt", "r");
    STARTWORD("2.txt", "r");

    totalinventory = atoi(CurrentWord.TabWord);

    // Setup items
    for (int i = 0; i < totalinventory; i++){
        ADVWORD();
        inventory.price = atoi(CurrentWord.TabWord);

        ADVWORD();
        int nameindex = 0;

        for (int j = 0; j < CurrentWord.Length; j++){
            inventory.name[nameindex++] = CurrentWord.TabWord[j];
        }

        while(GetCC() == ' '){
            inventory.name[nameindex++] = ' ';
            ADVWORD();

            for (int j = 0; j < CurrentWord.Length; j++){
                inventory.name[nameindex++] = CurrentWord.TabWord[j];
            }
        }

        inventory.name[nameindex] = '\0';
        printf("Adding item: %s, price: %d\n", inventory.name, inventory.price);
        InsertBarang(array, inventory, i);
    }

    ADVWORD();
    totaluser = atoi(CurrentWord.TabWord);

    for (int i = 0; i < totaluser; i++) {
        ADVWORD();
        Users->TC[i].money = atoi(CurrentWord.TabWord);
        
        ADVWORD();
        for (int j = 0; j < CurrentWord.Length; j++) {
            Users->TC[i].name[j] = CurrentWord.TabWord[j];
        }
        Users->TC[i].name[CurrentWord.Length] = '\0';
        
        ADVWORD();
        for (int j = 0; j < CurrentWord.Length; j++) {
            Users->TC[i].password[j] = CurrentWord.TabWord[j];
        }
        Users->TC[i].password[CurrentWord.Length] = '\0';
    }

    for (int i = 0; i < totaluser; i++){
        printf("%d : %s\n", Users->TC[i].money, Users->TC[i].name, Users->TC[i].password);
    }  

    for (int i = 0; i < totalinventory; i++){
        printf("%d : %s\n", array->A[i].price, array->A[i].name);
    } 
    
}    


int main(){
    TabUser user;
    ArrayDinBarang items;
    MakeArrayDinBarang(&items);

    start(&user, &items);
    DeallocateArrayDinBarang(&items);
    return 0;
}