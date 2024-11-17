#include "../Header/store_req.h"
// #include "../Header/start.h"
// #include "../ADT/array/array.h"
// #include "../ADT/arraydin/arraydin.h"
// #include "../ADT/queue/queue.h"

int main(){
    TabUser user;
    ArrayDinBarang items;
    MakeArrayDinBarang(&items);

    start(&user, &items);
    DeallocateArrayDinBarang(&items);
    return 0;
}