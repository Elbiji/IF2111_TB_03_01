#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10
#define MAX_LEN 50
#define integer int

typedef struct {
  char name[MAX_LEN];
  integer price;
} Barang;

typedef int IdxType;
typedef int ElType;
typedef struct {
    Barang *A;
    int Capacity;
    int Neff;
} ArrayDinBarang;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
void MakeArrayDinBarang(ArrayDinBarang *array);

/**
 * Destruktor
 * I.S. ArrayDinBarang terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDinBarang(ArrayDinBarang *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDinBarang array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDinBarang array);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDinBarang array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertBarang(ArrayDinBarang *array, Barang el, IdxType i);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDinBarang
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDinBarang *array, IdxType i);

/**
 * Fungsi untuk menambah jumlah kapasitan array dinamis
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void GrowArray(ArrayDinBarang *array);

/**
 * Fungsi untuk mengurangi jumlah kapasitas array dinamis
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DecreaseArray(ArrayDinBarang *array);

#endif