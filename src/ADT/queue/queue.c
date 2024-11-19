#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (q.idxHead == IDX_UNDEF) && (q.idxTail == IDX_UNDEF);
}

boolean isFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return (((q.idxTail + 1) % CAPACITY) == q.idxHead);
}

int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmpty(q)){
        return 0;
    } 

    if (q.idxTail >= q.idxHead){
        return q.idxTail - q.idxHead + 1;
    } else {
        return (CAPACITY - q.idxHead) + (q.idxTail + 1);
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, nama_barang val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q mungkin penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isEmpty(*q)){
        (*q).idxHead = 0;
        (*q).idxTail = 0;
    } else {
        (*q).idxTail = ((*q).idxTail + 1) % CAPACITY;
    }

    int i;
    for (i = 0; val.name[i] != '\0' && i < 49; i++){
        q->buffer[q->idxTail].name[i] = val.name[i];
    }
    q->buffer[q->idxTail].name[i] = '\0';
}

void dequeue(Queue *q, nama_barang *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    if (isEmpty(*q)){
        return;
    }
    
    int i;
    for (i = 0; q->buffer[q->idxHead].name[i] != '\0' && i < 49; i++){
        val->name[i] = q->buffer[q->idxHead].name[i];
    }
    val->name[i] = '\0';

    if ((*q).idxHead == (*q).idxTail){
        (*q).idxHead = IDX_UNDEF;
        (*q).idxTail = IDX_UNDEF;
    } else {
        (*q).idxHead = ((*q).idxHead + 1) % CAPACITY;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    if (isEmpty(q)){
        printf("[]\n");
        return;
    } 

    printf("[");
    int i = q.idxHead;

    while (true){
        printf("%s", q.buffer[i].name);

        if (i == q.idxTail) break;

        printf(",");
        i = (i+1) % CAPACITY;
    }
    printf("]\n");
}

