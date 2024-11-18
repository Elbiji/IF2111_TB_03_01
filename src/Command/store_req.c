#include "../Header/store_req.h"
// #include "../Header/start.h"
// #include "../ADT/array/array.h"
// #include "../ADT/arraydin/arraydin.h"
// #include "../ADT/queue/queue.h"

// ArrayDinBarang array;
// Queue items_request;

void store_request(Queue *items_request, ArrayDinBarang array){
    char requested_item[50];
    nama_barang item;

    if (isFull(*items_request)){
        printf("antrian penuh");
        return;

    } else {
        printf("======= [STORE REQUEST] =======\n");
        while(!isFull(*items_request)){
            printf("Nama barang yang diminta: \n");
            START("", "");
            while(!IsEOP() && (GetCC() == ' ' || GetCC() == '\n')){
                ADV();
            }

            int i = 0;
            while (!IsEOP() && GetCC() != '\n' && i < MAX_LEN-1){
                requested_item[i++] = GetCC();
                ADV();
            }
            requested_item[i] = '\0';

            if (!IsEOP() && GetCC() != '\n') {
                while (!IsEOP() && GetCC() != '\n') {
                    ADV();
                }
                printf("Input terlalu panjang! (max %d karakter)\n", MAX_LEN-1);
                continue;
            }

            if (isStrAllDigit(requested_item)){
                printf("Pastikan anda memasukkan nama berupa karakter\n");

            } else if (isItemInShop(array, requested_item)){
                printf("Barang sudah ada di toko!\n");

            } else {
                if (isItemInQueue(*items_request, requested_item))
                {
                    printf("Barang sudah berada di dalam antrian!\n");
                    
                } else {
                    int i;
                    for (i = 0; requested_item[i] != '\0' && i < 49; i++){
                        item.name[i] = requested_item[i];
                    }
                    item.name[i] = '\0';

                    enqueue(items_request, item);
                    printf("Barang berhasil dimasukkan ke dalam antrian\n");
                }   
            }   
        }   
    }
}

// int main() {
//     TabUser user;
//     ArrayDinBarang items;
//     Queue item_req;
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
    
//     store_request(&item_req, items);
//     displayQueue(item_req);

//     DeallocateArrayDinBarang(&items);
//     return 0;
// }