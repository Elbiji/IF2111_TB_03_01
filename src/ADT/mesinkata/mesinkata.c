#include<stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
   while (GetCC() == BLANK){
        ADV();
   }
}

void IgnoreLines(){
/* Mengabaikan satu atau beberapa NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ NEWLINE atau currentChar = MARK */
   while (GetCC() == NEWLINE){
        ADV();
   }
}

void STARTWORD(char *path, char *type){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START(path, type);
    ADVWORD();
}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if (GetCC() == MARK){
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void ADVLINE(){
    IgnoreLines();
    int count = 0;
    ADVWORD();
    Word tempWord = CurrentWord;
    while (!IsEOP() && GetCC() != NEWLINE){
        ADVWORD();

    }
    if (count > 0){
        CurrentWord = tempWord;
    }
    IgnoreLines();
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while ((GetCC() != MARK) && (GetCC() != BLANK) && (i < NMax)){
        CurrentWord.TabWord[i] = GetCC();
        ADV();
        i++;
    }
    CurrentWord.Length = i;
}


