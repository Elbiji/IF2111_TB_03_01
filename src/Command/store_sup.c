#include "../Header/store_sup.h"

void store_sup(Queue *items_request, ArrayDinBarang *array, IdxType Iduser, TabUser *user){
    printf("======= [STORE  SUPPLY] =======\n");

    Barang barang_antrian;
    nama_barang antrian;
    int harga;
    char response[MAX_LEN];
    char *acc = "Terima";
    char *hld = "Tunda";
    char *rmv = "Tolak";

    while (!isEmpty(*items_request))
    {   
        boolean Accept = true;
        boolean Remove = true;
        boolean Hold = true;
        int itemindex = items_request->idxHead;
        printf("Apakah kamu ingin menambahkan barang %s? (Terima/Tolak/Tunda)\n", items_request->buffer[itemindex].name);

        
        if(!readInput(response, MAX_LEN)){
            continue;
        }


        if (!IsEOP() && GetCC() != '\n'){
            while (!IsEOP() && GetCC() != '\n'){
                ADV();
            }
            printf("Input terlalu panjang! (max %d karakter)\n", MAX_LEN-1);
            continue;
        }

        for (int i = 0; (i < 10 && acc[i] != '\0') || response[i] != '\0'; i++){
            if (response[i] != acc[i]){
                Accept = false;
                break;
            }
        }
        for (int i = 0; (i < 10 && hld[i] != '\0') || response[i] != '\0'; i++){
            if (response[i] != hld[i]){
                Hold = false;
                break;
            }
        }
        for (int i = 0; (i < 10 && rmv[i] != '\0') || response[i] != '\0'; i++){
            if (response[i] != rmv[i]){
                Remove = false;
                break;
            }
        }

        if (Accept) {
            dequeue(items_request, &antrian);
            while(1){       
                printf("Harga Barang : \n");
                
                START("","");
                while (!IsEOP() && (GetCC() == '\n' || GetCC() == ' ')) {
                    ADV();
                } // Clearing buffer
                int val = 0;
                boolean isvalid = true;

                while (!IsEOP() && GetCC() != '\n'){
                    if (GetCC() >= '0' && GetCC() <= '9'){
                        val = val * 10 + (GetCC() - '0'); // Parsing one by one
                    } else {
                        isvalid = false;
                    }
                    ADV();
                }

                if (user->TC[Iduser].money - val < 0){
                    printf("Uang kamu tidak mencukupi!\n");
                    continue;
                }

                if (!isvalid || val <= 0){
                    printf("Masukkan sebuah integer yang lebih besar dari 0!\n");
                    continue;
                }

                harga = val;
                user->TC[Iduser].money -= harga;
                printf("\n");
                
                break;
            } 
            
            IdxType index = array->Neff;
            barang_antrian.price = harga;
            int i;
            for (i = 0; items_request->buffer[itemindex].name[i] != '\0' && i < MAX_LEN-1; i++){
                barang_antrian.name[i] = items_request->buffer[itemindex].name[i];
            }
            barang_antrian.name[i] = '\0';
            user->TC[Iduser].money - harga;
            printf("%s dengan harga %d telah ditambahkan ke toko.\n", barang_antrian.name, harga);
            printf("Uangmu sekarang : Rp %d\n", user->TC[Iduser].money);
            InsertBarang(array, barang_antrian, index);

            // printf("\nLoaded Items:\n");
            // for (int i = 0; i < array->Neff; i++) {
            //     printf("Item %d: %s (Price: %d)\n", 
            //         i+1, array->A[i].name, array->A[i].price);
            // }

            // displayQueue(*items_request);
        } else if (Remove) {
            dequeue(items_request, &antrian);
            int i;
            for (i = 0; items_request->buffer[itemindex].name[i] != '\0' && i < MAX_LEN-1; i++){
                barang_antrian.name[i] = items_request->buffer[itemindex].name[i];
            }
            barang_antrian.name[i] = '\0';
            dequeue(items_request, &antrian);
            printf("%s dibuang dari antrian.\n", barang_antrian.name, harga);
            // displayQueue(*items_request);
        } else if (Hold) {
            int i;
            for (i = 0; items_request->buffer[itemindex].name[i] != '\0' && i < MAX_LEN-1; i++){
                barang_antrian.name[i] = items_request->buffer[itemindex].name[i];
            }
            barang_antrian.name[i] = '\0';
            dequeue(items_request, &antrian);
            printf("%s dikembalikan ke antrian.\n", barang_antrian.name, harga);
            enqueue(items_request, antrian);
            // displayQueue(*items_request);
        } else if(isDone(response)) {
            break;
        } else {
            printf("Masukkan perintah (Terima/Tolak/Tunda)\n");
        }   
    }

    if (isEmpty(*items_request)){
        printf("Tidak ada barang di antrian\n");
    } else {
        printf("Kamu keluar dari Store Supply!\n");
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
//     store_sup(&item_req, &items);
//     displayQueue(item_req);

//     DeallocateArrayDinBarang(&items);
//     return 0;
// }