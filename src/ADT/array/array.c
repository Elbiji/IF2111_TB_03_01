#include <stdio.h>
#include "array.h"

job listjob[] = {
    {"Evil Lab Assistant", 100, 14},
    {"OWCA Hiring Manager", 4200, 21},
    {"Cikapundunginator Caretaker", 7000, 30},
    {"Mewing Specialist", 10000, 22},
    {"Inator Connoisseur", 997, 15}
};
int totaljob = 5;

// Konstruktor: create tabel kosong
void MakeEmpty (TabUser *T) {
    // Tidak diperlukan sebuah inisialisasi TabUser T; karena sudah terdefinisi
    T->Neff = 0;
}

void ResetTabUser (TabUser *T) {
    T->Neff = 0;

    for (int i = IdxMin; i <= IdxMax; i++){
        for (int j = 0; j < IdxMax; j++) {
            T->TC[i - IdxMin].name[j] = '\0';
        }

        for (int j = 0; j < IdxMax; j++){
            T->TC[i-IdxMin].password[j] = '\0';
        }

        T->TC[i-IdxMin].money = 0;
    }
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

// Mendapatkan nama dari index tertentu
char* GetUserName(TabUser T, IdxType i) {
    char* username = T.TC[i-IdxMin].name;
    return username;
}

// Mendapatkan uang dari index tertentu
int GetMoney(TabUser T, IdxType i) {
    return T.TC[i-IdxMin].money;
}

// Mendapatkan password dari index tertentu
char* GetPassword(TabUser T, IdxType i) {
    char* password = T.TC[i-IdxMin].password;
    return password;
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
    if (IsUserEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else {
        for (int i = GetFirstIdx(T)-1; i < GetLastIdx(T); i++) {
            printf("%s : %d\n", T.TC[i].name, T.TC[i].money);
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



