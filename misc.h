#ifndef __MISC_H_
#define __MISC_H_

#define MAX_CHANCES 5
#define WORD_LENGTH 5
#define MAX_LEN 50

#include <stdlib.h>
#include "src/Header/load.h"
// #include "../ADT/array/array.h"
// #include "../ADT/arraydin/arraydin.h"
// #include "../ADT/queue/queue.h"
// #include "../ADT/boolean/boolean.h"
// #include "../ADT/mesinkarakter/mesinkarakter.h"
// #include "../ADT/mesinkata/mesinkata.h"
#include "src/ADT/array/array.h"
#include "src/ADT/arraydin/arraydin.h"
#include "src/ADT/queue/queue.h"
#include "src/ADT/boolean/boolean.h"
#include "src/ADT/mesinkarakter/mesinkarakter.h"
#include "src/ADT/mesinkata/mesinkata.h"


// Mengembalikan index sebuah barang pada toko menggunakan traversal
// menerima parameter array dinamis dan string
IdxType IndexItemInShop(ArrayDinBarang array, char *str);

// Mengembalikan index sebuah user pada konfigurasi file menggunakan traversal
// menerima parameter Tabuser dan string
IdxType IndexUserInFile(TabUser Users, char *str);

// Mengembalikan index sebuah job pada konfigurasi file menggunakan traversal
// menerima parameter job, total job dan string
IdxType IndexJobInList(job listjob[], int totaljob, char *str);

// Mengkonfirmasi apakah proses dalam store supply dan store remove di terminasi
// menerima parameter string
boolean isDone(char *input);

// Mencari nama barang pada toko menggunakan traversal
// menerima parameter array dinamis dan string
boolean isItemInShop(ArrayDinBarang array, char *str);

// Mencari nama barang pada antrian dengan traversal
// menerima parameter queue dan string
boolean isItemInQueue(Queue items_request, char *str);


// Mencari nama user pada file dengan traversal
// menerima parameter Tabuser dan string
boolean isUserInFile(TabUser Users, char *str);

// Memeriksa apakah input semuanya merupakan digit
// menerima parameter string
boolean isStrAllDigit (char *str);

// Memeriksa antara dua string apakah sama
// menerima parameter word dari mesin kata dan string 
boolean isStrEqual(char *str1, char *str2);

// Mengembalikan panjang string 
// menerima parameter string
int strLength(char *str);

// Fungsi menyalin isi dari string sumber ke string tujuan
// menerima parameter tujuan dan sumber
void copystrng(char *dest, const char *src);

// Validasi input agar tidak melebihi batas 49 Karakter menggunakan mesin kata
// menerima parameter buffer dan panjang maksimal
boolean readInput(char *buffer, int maxLen);

// Validasi command agar tidak melebihi batas 49 Karakter menggunakan mesin kata
// menerima parameter buffer dan panjang maksimal serta nama command
boolean readCommand(char *buffer, int maxLen);

// Memeriksa apakah input mempunyai spasi
boolean containsSpace(const char *str);

// Menerima input untuk dirubah ke integer
int strToInteger ();

// Periksa tebakan
void check_guess(const char *guess, const char *target, char *feedback);

// Cetak hasil
void print_feedback(const char *guess, const char *feedback);

// memecah input yang berisi beberapa kata menjadi satu kata
void substring(const char *src, int start, int end, char *dest);

// visual
void visual(char* path);

// Untuk menyalin sebuah string
void stringCopy(char *dest, const char *src);

#endif