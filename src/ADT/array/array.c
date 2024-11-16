#include <stdio.h>
#include "array.h"

// Konstruktor: create tabel kosong
void MakeEmpty (TabUser *T) {
    // Tidak diperlukan sebuah inisialisasi TabUser T; karena sudah terdefinisi
    T->Neff = 0;
}

// Banyaknya elemen
int NbElmt (TabUser T) {
    return T.Neff;
}

// Mengirimkan max elemen yang bisa disimpan
int MaxNbEl(TabUser T) {
    return IdxMax-IdxMin+1;
}

// Mendapatkan index elemen pertama 
IdxType GetFirstIdx (TabUser T) {
    return IdxMin;
}

// Mendapatkan index dari elemen terakhir
IdxType GetLastIdx (TabUser T) {
    return NbElmt(T);
}

// Mendapatkan nilai dari index tertentu
char* GetUserName(TabUser T, IdxType i) {
    return T.TC[i-IdxMin].name;
}

// Mendapatkan nilai dari index tertentu
int GetMoney(TabUser T, IdxType i) {
    return T.TC[i-IdxMin].money;
}

// Mendapatkan nilai dari index tertentu
char* GetPassword(TabUser T, IdxType i) {
    return T.TC[i-IdxMin].password;
}

// Memasukkan value ke uang
void SetMoney(TabUser *T, IdxType i, int val){
    T->TC[i - IdxMin].money = val;
}


// Mengecek apakah index itu berada di tabel yang terdefinisi
boolean IsIdxValid(TabUser T, IdxType i) {
    return (i >= IdxMin && i <= IdxMax);
}

// Mengecek apakah index itu berada di rentang Neff
boolean IsIdxEff(TabUser T, IdxType i) {
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

// Tes tabel kosong
boolean IsUserEmpty (TabUser T) {
    return (NbElmt(T) == 0);
}

// isFull
boolean IsFull(TabUser T) {
    return (NbElmt(T) == MaxNbEl(T));
}

// Print isi tabel
void TulisIsi (TabUser T) {
    if (IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else {
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            printf("%s : %d", T.TC[i].name, T.TC[i].money);
        }
    }
}



// int main() {
    
//     TabUser T;
//     T.TI[0] = 1;
//     T.TI[1] = 2;
//     T.TI[2] = 0;
//     T.TI[3] = 3;
//     T.TI[4] = 1;
//     T.Neff = 5;
//     return 0;
//     printf("ahhaha");
//     printf("%d\n", IdxMinTab(T));
// }



