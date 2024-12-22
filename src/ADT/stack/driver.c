#include <stdio.h>
#include "stack.h"
#include "../../misc.h"


void printHistory(history h) {
    printf("Nama Barang: %s\n", h.nama_barang);
    printf("Total Price: %d\n", h.total_price);
}

// int main() {
//     Stack S;
//     history h1, h2, h3;

//     CreateEmptyStack(&S);
//     printf("Stack created. Is the stack empty? %s\n", IsEmptyStack(S) ? "Yes" : "No");

//     printf("\nPushing first item to the stack...\n");
//     h1.total_price = 100;
//     printf("Enter name for first item: ");
//     readInput(h1.nama_barang, sizeof(h1.nama_barang));  
//     Push(&S, h1);

//     printf("\nPushing second item to the stack...\n");
//     h2.total_price = 200;
//     printf("Enter name for second item: ");
//     readInput(h2.nama_barang, sizeof(h2.nama_barang));  

//     Push(&S, h2);

//     printf("\nPushing third item to the stack...\n");
//     h3.total_price = 300;
//     printf("Enter name for third item: ");
//     readInput(h3.nama_barang, sizeof(h3.nama_barang)); 

//     Push(&S, h3);

//     printf("\nIs the stack full? %s\n", IsFullStack(S) ? "Yes" : "No");
//     printf("Current number of elements in stack: %d\n", CountStack(S));

//     printf("\nTop item in the stack:\n");
//     printHistory(InfoTop(S));

//     printf("\nPopping an item from the stack...\n");
//     history poppedHistory;
//     Pop(&S, &poppedHistory);
//     printf("Popped item:\n");
//     printHistory(poppedHistory);

//     printf("\nAfter popping, is the stack empty? %s\n", IsEmptyStack(S) ? "Yes" : "No");
//     printf("Current number of elements in stack: %d\n", CountStack(S));

//     printf("\nNew top item in the stack:\n");
//     printHistory(InfoTop(S));

//     return 0;
// }