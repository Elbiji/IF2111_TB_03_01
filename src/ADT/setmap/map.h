#ifndef map_H
#define map_H
#include <stdio.h>
#include "../boolean/boolean.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define MaxElMap 20
#define Undefined -999

// typedef int bool;
typedef char keytype[50];
typedef int valuetype;
typedef int address;

typedef struct {
	keytype nama_barang_keranjang;
	valuetype jumlah_barang;
} infotype;

typedef struct {
	infotype Elements[MaxElMap];
	address Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElMap */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxElMap */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype *k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype *k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype *k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype *k);
/* Mengembalikan true jika k adalah member dari M */
/* I.S. M terdefinisi */
/* F.S. Mengembalikan true jika k adalah member dari M */

boolean isStrEqualMap(char *str1, char *str2);
/* Mengembalikan true jika str1 sama dengan str2 */
/* Menggunakan perbandingan karakter satu per satu. */
/* I.S. str1 dan str2 terdefinisi */
/* F.S. Mengembalikan true jika str1 sama dengan str2*/

int strLengthMap(char *str);
/* Mengembalikan panjang string str */
/* I.S. str terdefinisi */
/* F.S. Mengembalikan panjang string str*/

void SubtractAmount(Map *M, keytype *k, valuetype val);
/* Mengurangi jumlah barang dengan val pada Map M. */
/* I.S. M terdefinisi */
/* F.S. Mengurangi jumlah barang dengan val pada Map M. */

#endif