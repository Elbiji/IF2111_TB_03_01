#include<stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;

void Ignore(){
/* Mengabaikan satu atau beberapa NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ NEWLINE atau currentChar = MARK */
   while (GetCC() == NEWLINE || GetCC() == BLANK){
        ADV();
   }
}

void STARTWORD(char *path, char *type){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START(path, type);
    Ignore();
    if (IsEOP()){
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    Ignore();
    if (IsEOP()){
        EndWord = true;
    } else {
        CopyWord();
        EndWord = false;
    }
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while (!IsEOP() && GetCC() != BLANK && GetCC() != MARK ){
        if (i < NMax)
        {
            CurrentWord.TabWord[i] = GetCC();
            i++;
        }   
        ADV();
    }
    CurrentWord.Length = i;
    CurrentWord.TabWord[i] = '\0';
}



