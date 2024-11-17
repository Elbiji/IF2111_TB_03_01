#include "../Header/store_req.h"
// #include "../Header/start.h"
// #include "../ADT/array/array.h"
// #include "../ADT/arraydin/arraydin.h"
// #include "../ADT/queue/queue.h"

int main() {
    TabUser user;
    ArrayDinBarang items;
    
    MakeArrayDinBarang(&items);
    start(&user, &items);
    
    // Print results to verify
    printf("\nLoaded Users:\n");
    for (int i = 0; i <  user.Neff; i++) {
        printf("User %d: %s (Money: %d)\n", 
               i+1, user.TC[i].name, user.TC[i].money);
    }
    
    printf("\nLoaded Items:\n");
    for (int i = 0; i < items.Neff; i++) {
        printf("Item %d: %s (Price: %d)\n", 
               i+1, items.A[i].name, items.A[i].price);
    }
    
    DeallocateArrayDinBarang(&items);
    return 0;
}