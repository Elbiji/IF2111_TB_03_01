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
    if ( i >= array->Capacity) {
        GrowArray(array);
        if (i >= array->Capacity) {
            printf("Allocation failed\n");
            return;
        }
    }

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
    if (i < 0 || i >= array->Neff){
        return;
    }

    for (IdxType j = i; j < array->Neff - 1;j++){
        int k;
        for (k = 0; array->A[j+1].name[k] != '\0' && k < MAX_LEN-1; k++){
            array->A[j].name[k] = array->A[j+1].name[k];
        }
        array->A[j].name[k] = '\0';

        array->A[j].price = array->A[j+1].price;
    }

    array->A[array->Neff-1].name[0] = '\0';
    array->A[array->Neff-1].price = 0;

    array->Neff--;
}


/**
 * Fungsi untuk menambah jumlah kapasitan array dinamis
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void GrowArray(ArrayDinBarang *array){
    int newCapacity = array->Capacity*2;

    Barang *temp = (Barang*)realloc(array->A, newCapacity * sizeof(Barang));

    if (temp != NULL){
        array->A = temp;
        array->Capacity = newCapacity;

        for (int i = array->Neff; i < newCapacity; i++){
            array->A[i].price = 0;
            array->A[i].name[0] = '\0';
        }
    } else {
        printf("error\n");
    }
}

void DecreaseArray(ArrayDinBarang *array){
    if (array->Capacity <= InitialSize){
        return;
    }

    if (array->Neff > newCapacity){
        printf("Array still needs slot. Further decrease would lead to conflict!\n");
        return;
    }
    int newCapacity = array->Capacity/2;

    Barang *temp = (Barang*)realloc(array->A, newCapacity * sizeof(Barang));
    if (temp != NULL){
        array->A = temp;
        array->Capacity = newCapacity;
    }
}