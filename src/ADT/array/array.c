#include <stdio.h>
#include "array.h"

// Konstruktor: create tabel kosong
void MakeEmpty (TabInt *T) {
    // Tidak diperlukan sebuah inisialisasi Tabint T; karena sudah terdefinisi
    T->Neff = 0;
}

// Banyaknya elemen
int NbElmt (TabInt T) {
    return T.Neff;
}

// Mengirimkan max elemen yang bisa disimpan
int MaxNbEl(TabInt T) {
    return IdxMax-IdxMin+1;
}

// Mendapatkan index elemen pertama 
IdxType GetFirstIdx (TabInt T) {
    return IdxMin;
}

// Mendapatkan index dari elemen terakhir
IdxType GetLastIdx (TabInt T) {
    return NbElmt(T);
}

// Mendapatkan nilai dari index tertentu
ElType GetElmt(TabInt T, IdxType i) {
    return T.TI[i-IdxMin];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab(TabInt Tin, TabInt *Tout) {
    *Tout=Tin;
}

// Set element
void SetEl(TabInt *T, IdxType i, ElType v) {
    T->TI[i-IdxMin] = v; // Set the value
    if (i > T->Neff) { // Check if index is effective
        T->Neff = i;
    }
}

// Mengeset nilai indeks elemen efektif sehingga bernilai N
void SetNeff (TabInt *T, IdxType N) {
    T->Neff = N;
}

// Mengecek apakah index itu berada di tabel yang terdefinisi
boolean IsIdxValid(TabInt T, IdxType i) {
    return (i >= IdxMin && i <= IdxMax);
}

// Mengecek apakah index itu berada di rentang Neff
boolean IsIdxEff(TabInt T, IdxType i) {
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

// Tes tabel kosong
boolean IsEmpty (TabInt T) {
    return (NbElmt(T) == 0);
}

// isFull
boolean IsFull(TabInt T) {
    return (NbElmt(T) == MaxNbEl(T));
}

// Print isi tabel
void TulisIsi (TabInt T) {
    if (IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else {
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            printf("%d:%d\n",i-IdxMin, GetElmt(T,i));
        }
    }
}

// Menjumlahkan tabel yang berukuran sama di index yang sama
TabInt PlusTab (TabInt T1, TabInt T2) {
    TabInt T;
    MakeEmpty(&T);
    for (int i = GetFirstIdx(T1);  i <= GetLastIdx(T1); i++) {
        SetEl(&T, i, GetElmt(T1,i) + GetElmt(T2,i));
    }
    return T;
}

// Mengurangi tabel yang berukuran sama di index yang sama
TabInt MinusTab (TabInt T1, TabInt T2) {
    TabInt T;
    MakeEmpty(&T);
    for (int i = GetFirstIdx(T1);  i <= GetLastIdx(T1); i++) {
        SetEl(&T, i, GetElmt(T1,i) - GetElmt(T2,i));
    }
    return T;
}

// Mengirimkan nilai elemen bernilai ekstrem
ElType ValMax(TabInt T) {
    ElType max = GetElmt(T, GetFirstIdx(T));
    for (IdxType i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (GetElmt(T,i) > max)
        {
            max = GetElmt(T,i);
        }
    }
    return max;
}

// Mengirimkan nilai elemen bernilai minimum
ElType ValMin(TabInt T) {
    ElType min = GetElmt(T, GetFirstIdx);
    for (IdxType i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (GetElmt(T,i) < min)
        {
            min = GetElmt(T,i);
        }
    }
    return min;
}

// Mengirimkan indeks elemen bernilai maksimum
IdxType IdxMaxTab(TabInt T) {
    IdxType idx = GetFirstIdx(T);
    ElType max = GetElmt(T,idx);
    for (IdxType i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (GetElmt(T,i) > max)
        {
            max = GetElmt(T,i);
            idx = i;
        }
    }
    return idx;
}

// Mengirimkan nilai indeks elemen bernilai minimum
IdxType IdxMinTab(TabInt T) {
    IdxType idx = GetFirstIdx(T);
    ElType min = GetElmt(T,idx);
    for (IdxType i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (GetElmt(T,i) < min)
        {
            min = GetElmt(T,i);
            idx = i;
        }
    }
    return idx;
}

// int main() {
    
//     TabInt T;
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



