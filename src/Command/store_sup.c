#include "../Header/store_sup.h"

boolean isDone(char *input){
    char *done = "Purry";
    for (int i = 0; input[i] != '\0' && done[i] != '\0'; i++){
        if (input[i] != done[i]){
            return false;
        }
    }
    return true;
}


void store_sup(Queue *items_request, ArrayDinBarang *array){
    printf("======= [STORE  SUPPLY] =======\n");

    Barang barang_antrian;
    nama_barang antrian;
    int harga;
    char response[10];
    char *acc = "Terima";
    char *hld = "Tunda";
    char *rmv = "Tolak";

    while (1 || !isEmpty(*items_request))
    {   
        boolean Accept = true;
        boolean Remove = true;
        boolean Hold = true;
        int itemindex = items_request->idxHead;
        printf("Apakah kamu ingin menambahkan barang %s? (Terima/Tolak/Tunda)\n", items_request->buffer[itemindex].name);

        scanf("%s", response);

        for (int i = 0; i < 10 && acc[i] != '\0'; i++){
            if (response[i] != acc[i]){
                Accept = false;
                break;
            }
        }
        for (int i = 0; i < 10 && hld[i] != '\0'; i++){
            if (response[i] != hld[i]){
                Hold = false;
                break;
            }
        }
        for (int i = 0; i < 10 && rmv[i] != '\0'; i++){
            if (response[i] != rmv[i]){
                Remove = false;
                break;
            }
        }

        if (Accept) {
            dequeue(items_request, &antrian);
            printf("Harga Barang : ");
            scanf("%d", &harga);
            while (getchar() != '\n'); // clear buffer
            while (harga == 0){
                printf("Masukkan sebuah angka yang lebih besar dari 0 atau Masukkan sebuah angka bukan karakter!\n");
                printf("Harga Barang : ");
                scanf("%d", &harga);
                if (harga > 0) break;
                while (getchar() != '\n'); // clear buffer
            }
            IdxType index = array->Neff;
            barang_antrian.price = harga;
            int i;
            for (i = 0; items_request->buffer[itemindex].name[i] != '\0' && i < MAX_LEN-1; i++){
                barang_antrian.name[i] = items_request->buffer[itemindex].name[i];
            }
            barang_antrian.name[i] = '\0';
            InsertBarang(array, barang_antrian, index);

            printf("\nLoaded Items:\n");
            for (int i = 0; i < array->Neff; i++) {
                printf("Item %d: %s (Price: %d)\n", 
                    i+1, array->A[i].name, array->A[i].price);
            }

            displayQueue(*items_request);
        } else if (Remove) {
            dequeue(items_request, &antrian);
            displayQueue(*items_request);
        } else if (Hold) {
            dequeue(items_request, &antrian);
            enqueue(items_request, antrian);
            displayQueue(*items_request);
        } else if(isDone(response)) {
            break;
        } else {
            printf("Masukkan perintah (Terima/Tolak/Tunda)\n");
        }   
    }

    if (isEmpty(*items_request)){
        printf("Tidak ada barang di antrian");
    } else {
        printf("Kamu keluar dari Store Supply!");
    }
}

int main() {
    TabUser user;
    ArrayDinBarang items;
    Queue item_req;
    MakeArrayDinBarang(&items);
    start(&user, &items, &item_req);
    
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
    
    store_request(&item_req, items);
    store_sup(&item_req, &items);
    displayQueue(item_req);

    DeallocateArrayDinBarang(&items);
    return 0;
}