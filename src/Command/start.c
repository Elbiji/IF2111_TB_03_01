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
    MakeArrayDinBarang(array);

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

    printf("\nTrying to read user count...\n");
    ADVWORD();
    if (!EndWord) {
        printf("Found user count: %s\n", CurrentWord.TabWord);
        totaluser = atoi(CurrentWord.TabWord);
        
        // Process users
        for (int i = 0; i < totaluser; i++) {
            ADVWORD();
            printf("Reading money: %s\n", CurrentWord.TabWord);
            Users->TC[i].money = atoi(CurrentWord.TabWord);
            
            ADVWORD();
            printf("Reading username: %s\n", CurrentWord.TabWord);
            for (int j = 0; j < CurrentWord.Length; j++) {
                Users->TC[i].name[j] = CurrentWord.TabWord[j];
            }
            Users->TC[i].name[CurrentWord.Length] = '\0';
            
            ADVWORD();
            printf("Reading password: %s\n", CurrentWord.TabWord);
            for (int j = 0; j < CurrentWord.Length; j++) {
                Users->TC[i].password[j] = CurrentWord.TabWord[j];
            }
            Users->TC[i].password[CurrentWord.Length] = '\0';
        }
    } else {
        printf("Failed to read user count - EndWord reached\n");
    }
}    


int main(){
    TabUser user;
    ArrayDinBarang items;
    start(&user, &items);
    return 0;
}