#include <stdio.h>
#include <stdlib.h>
#include "dplinkedlist.h"

boolean isStrEqualLDP(info_barang str1, info_barang str2){
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLDP (List L) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return (First(L) == Kosong && Last(L) == Kosong);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLDP (List *L) {
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = Kosong;
    Last(*L) = Kosong;
}

/****************** Manajemen Memori ******************/
addressDP Alokasi (info_barang X) {
/* Mengirimkan addressDP hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressDP tidak Kosong. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Kosong, Prev(P)=Kosong */
/* Jika alokasi gagal, mengirimkan Kosong. */
    addressDP P = (addressDP) malloc(sizeof(wishlist_item));
    if (P != Kosong){
        int i = 0;
        while (X[i] != '\0') {
            Info(P)[i] = X[i];
            i++;
        }
        Info(P)[i] = '\0';  
        Next(P) = Kosong;
        Prev(P) = Kosong;
    }
    printf("debug alokasi %s\n", Info(P));
    return P;
}

void Dealokasi (addressDP P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressDP P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressDP Search (List L, info_barang X) {
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressDP elemen tersebut. */
/* Jika tidak ada, mengirimkan Kosong */
    addressDP P = First(L);
    while (P != Kosong){
        // printf("aa\n");
        if (isStrEqualLDP(X, Info(P))){
            return P;
        } else {
            P = Next(P);
        }
    }
    return Kosong;
}

/****************** PRIMITIF BERDASARKAN KosongAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, info_barang X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Kosongai X jika alokasi berhasil */
    addressDP P = Alokasi(X);
    if (P != Kosong){
        Next(P) = First(*L);
        if (!IsEmptyLDP(*L)) {
            Prev(First(*L)) = P;
        } else {
            Last(*L) = P;
        }
        First(*L) = P;
    }
}
void InsVLast (List *L, info_barang X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berKosongai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    addressDP P = Alokasi(X);
    if (P != Kosong) {
        if (!IsEmptyLDP(*L)) {
            Prev(P) = Last(*L);
            Next(Last(*L)) = P;
        } else {
            First(*L) = P;
        }
        Last(*L) = P;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, info_barang *X) {
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Kosongai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    addressDP P = First(*L);
    int i = 0;
    while (Info(P)[i] != '\0' && i < 49) {
        (*X)[i] = Info(P)[i];
        i++;
    }
    (*X)[i] = '\0'; 
    if (First(*L) == Last(*L)) {
        Last(*L) = Kosong;
    } else {
        Prev(Next(First(*L))) = Kosong;
    }
    First(*L) = Next(First(*L));
    free(P);
}

void DelVLast (List *L, info_barang *X) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: Kosongai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    addressDP P = Last(*L);
    int i = 0;
    while (Info(P)[i] != '\0' && i < 49) {
        (*X)[i] = Info(P)[i];
        i++;
    }
    (*X)[i] = '\0'; 
    if (First(*L) == Last(*L)) {
        First(*L) = Kosong;
    } else {
        Next(Prev(Last(*L))) = Kosong;
    }
    Last(*L) = Prev(Last(*L));
    free(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressDP P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressDP P sebagai elemen pertama */
    Next(P) = First(*L);
    if (!IsEmptyLDP(*L)) {
        Prev(First(*L)) = P;
    } else {
        Last(*L) = P;
    }
    First(*L) = P;
}
void InsertLast (List *L, addressDP P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    Prev(P) = Last(*L);
    if (!IsEmptyLDP(*L)) {
        Next(Last(*L)) = P;
    } else {
        First(*L) = P;
    }
    Last(*L) = P;
}
void InsertAfter (List *L, addressDP P, addressDP Prec) {
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    if (Prec == Last(*L)) {
        Next(P) = Next(Prec);
        Prev(Next(Prec)) = P;
        Next(Prec) = P;
        Prev(P) = Prec;
    } else {
        InsertLast(L,P);
    }
}

void InsertBefore (List *L, addressDP P, addressDP Succ) {
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    if (Prev(Succ) != Kosong) {
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Prev(Succ) = P;
        Next(P) = Succ;
    } else {
        InsertFirst(L,P);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressDP *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    if (First(*L) == Last(*L)) {
        First(*L) = Kosong;
        Last(*L) = Kosong;
    } else {
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Kosong;
        Next(*P) = Kosong;
        Prev(*P) = Kosong;
    }
}

void DelLast (List *L, addressDP *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    *P = Last(*L);
    if (First(*L) == Last(*L)) {
        First(*L) = Kosong;
        Last(*L) = Kosong;
    } else {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Kosong;
        Next(*P) = Kosong;
        Prev(*P) = Kosong;
    }
}

void DelP (List *L, info_barang X) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressDP P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    addressDP P;
    boolean found = false;

    P = First(*L);
    while (!found && P != Kosong) {
        if (isStrEqualLDP(Info(P), X)) {
            found = true;
        } else {
            P = Next(P);
        }
    }

    if (found) {
        if (P == First(*L)) {
            DelFirst(L,&P);
        } else if (P == Last(*L)) {
            DelLast(L,&P);
        } else {
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
        }
    }
    Dealokasi(P);
}

void DelAfter (List *L, addressDP *Pdel, addressDP Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Prev(Next(*Pdel)) = Prec;
    Next(*Pdel) = Kosong;
    Prev(*Pdel) = Kosong;
    free(*Pdel);
}

void DelBefore (List *L, addressDP *Pdel, addressDP Succ) {
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Prev(Succ);
    Next(Prev(*Pdel)) = Succ;
    Prev(Succ) = Prev(*Pdel);
    Next(*Pdel) = Kosong;
    Prev(*Pdel) = Kosong;
    free(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berKosongai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
/* Terdapat newline di akhir setelah tutup kurung */
    addressDP P = First(L);

    int i = 1;
    while (P != Kosong) {
        printf("%d. %s\n", i, Info(P));
        P = Next(P);
        i++;
    }
}

void PrintBackward (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen berKosongai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
/* Terdapat newline di akhir setelah tutup kurung */
    addressDP P = Last(L);

    printf("[");
    while (P != Kosong) {
        printf("%s", Info(P));
        if (P != First(L)) {
            printf(",");
        }
        P = Prev(P);
    }
    printf("]\n");
}

void ResetDP(List *L){
    addressDP currentNode = First(*L);
    addressDP temp;

    while (currentNode != Kosong){
        temp = currentNode;
        currentNode = Next(currentNode);
        free(temp);
    }

    First(*L) = Kosong;
    Last(*L) = Kosong;
}

int CountElmt(List L){
    int ctr = 0;
    if (First(L) == Kosong && Last(L) == Kosong){
        return 0;
    } else {
        addressDP currentNode = First(L); 
        while (currentNode != Kosong){
            currentNode = Next(currentNode);
            ctr++;
        }
        return ctr; 
    }
}