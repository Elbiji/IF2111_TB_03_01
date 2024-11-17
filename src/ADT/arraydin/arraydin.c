#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDinBarang kosong dengan ukuran InitialSize
 */
void MakeArrayDinBarang(ArrayDinBarang *array){
    array->A = (Barang*)malloc(InitialSize * sizeof(Barang));
    if (array->A == NULL){
        printf("Memory allocation failed\n");
        return;
    } 

    for (int i = 0; i < InitialSize; i++){
        array->A[i].price = 0;
        for (int j = 0; j < MAX_LEN; j++){
            array->A[i].name[j] = '\0';
        }
    }

    array->Capacity = InitialSize;
    array->Neff = 0;
}

/**
 * Destruktor
 * I.S. ArrayDinBarang terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDinBarang(ArrayDinBarang *array){
    free(array->A);
    array->Capacity = 0;
    array->Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDinBarang array){
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDinBarang array){
    if (IsEmpty(array)){
        return 0;
    }
    return array.Neff;
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDinBarang array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertBarang(ArrayDinBarang *array, Barang el, IdxType i){
    for (int j = 0; j < MAX_LEN; j++){
        array->A[i].name[j] = '\0';
    }

    int j;
    for (j = 0; el.name[j] != '\0' && j < MAX_LEN - 1; j++){
        array->A[i].name[j] = el.name[j];
    }
    array->A[i].name[MAX_LEN - 1] = '\0';
    array->A[i].price = el.price;

    if (i >= array->Neff){
         array->Neff = i+1;
    }
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDinBarang
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDinBarang *array, IdxType i){
    for (IdxType i = 0; i < array->Neff; i++){
        array->A[i] = array->A[i+1];
    }
    array->Neff--;
}

