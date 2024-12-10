#include "map.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M){
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
    M->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M){
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
    return M.Count == Nil;
}

boolean IsFullMap(Map M){
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
    return M.Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype *k){
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
    int i = 0;
    boolean found = false;

    while (i < M.Count && !found){
        if (isStrEqualMap(*k, M.Elements[i].nama_barang_keranjang)){
            found = true;
        } else {
            i++;
        }
    }

    if (found){
        return M.Elements[i].jumlah_barang;
    } else {
        return Undefined;
    }
}

void Insert(Map *M, keytype *k, valuetype v){
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    int i = 0;
    boolean found = false;

    while (i < M->Count && !found){
        if (isStrEqualMap(*k, M->Elements[i].nama_barang_keranjang)){
            found = true;
            return;
        }
        i++;
    }

    if (!found){
        M->Elements[i].jumlah_barang = v;
        int j;
        for (j = 0; (*k)[j] != '\0' && j < 50-1; j++){
            M->Elements[i].nama_barang_keranjang[j] = (*k)[j];
        }
        M->Elements[i].nama_barang_keranjang[j] = '\0' ;
        M->Count++;
    }
}

void Delete(Map *M, keytype *k){
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
    boolean found = false;
    int pos = 0;

    while (pos < M->Count && !found){
        if (isStrEqualMap(*k, M->Elements[pos].nama_barang_keranjang)){
            found = true;
        } else {
            pos++;
        }
    }

    for (int i = pos; i < M->Count; i++){
        M->Elements[i] = M->Elements[i+1];
    }

    if (found){
        M->Count--;
    }
}

boolean IsMember(Map M, keytype *k){
/* Mengembalikan true jika k adalah member dari M */
    boolean found = false;
    int i = 0;

    while (i < M.Count && !found){
        if (isStrEqualMap(k, M.Elements[i].nama_barang_keranjang)){
            return true;
        } else {
            i++;
        }
    }
    return found;
}

boolean isStrEqualMap(char *str1, char *str2){
    if (strLengthMap(str1) != strLengthMap(str2)){
        return false;
    }
    int i;
    for (i = 0; i < strLengthMap(str2); i++){
        if (str1[i] != str2[i]){
            return false;
        }
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

int strLengthMap(char *str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}