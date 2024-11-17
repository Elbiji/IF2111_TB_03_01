#include "../Header/store_req.h"
// #include "../Header/start.h"
// #include "../ADT/array/array.h"
// #include "../ADT/arraydin/arraydin.h"
// #include "../ADT/queue/queue.h"

ArrayDinBarang array;
Queue items_request;

void store_request(Queue *items_request, ArrayDinBarang array){
    char requested_item[50];

    
    printf("Nama barang yang diminta: ");
    scanf("%49s", requested_item);
}

// int main() {
//     TabUser user;
//     ArrayDinBarang items;
//     Queue item_req:
//     MakeArrayDinBarang(&items);
//     start(&user, &items, &item_req);
    
//     // Print results to verify
//     printf("\nLoaded Users:\n");
//     for (int i = 0; i <  user.Neff; i++) {
//         printf("User %d: %s (Money: %d)\n", 
//                i+1, user.TC[i].name, user.TC[i].money);
//     }
    
//     printf("\nLoaded Items:\n");
//     for (int i = 0; i < items.Neff; i++) {
//         printf("Item %d: %s (Price: %d)\n", 
//                i+1, items.A[i].name, items.A[i].price);
//     }
    
//     DeallocateArrayDinBarang(&items);
//     return 0;
// }