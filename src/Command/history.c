#include "../Header/history.h"

boolean isInputHistory(char *input,int *posisi1){
    const char *command = "HISTORY";
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

void displayHistory(Stack *user_history, int n) {
    history temp;
    Stack temp_stack;
    CreateEmptyStack(&temp_stack);
    int count = 0;

    while (!IsEmptyStack(*user_history)){
        Pop(user_history,&temp);
        Push(&temp_stack, temp);
        count++;
    } 
    int ctr = 0;
    int index = 1;
    if (n < count){
        printf("Riwayat pembelian barang:\n");
        while (ctr != n){
            Pop(&temp_stack, &temp);
            printf("%d. %s %d\n", index, temp.nama_barang, temp.total_price);
            Push(user_history, temp);
            ctr++;
            index++;
        }
    } else {
        printf("Riwayat pembelian barang:\n");
        while (!IsEmptyStack(temp_stack)){
            Pop(&temp_stack, &temp);
            printf("%d. %s %d\n", index, temp.nama_barang, temp.total_price);
            Push(user_history, temp);
            index++;
        }
    }   

    while (!IsEmptyStack(temp_stack)){
            Pop(&temp_stack, &temp);
            Push(user_history, temp);
    }
}
