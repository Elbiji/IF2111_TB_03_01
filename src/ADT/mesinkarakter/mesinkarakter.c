#include <stdio.h>
#include "mesinkarakter.h"

int retval;
char currentChar;
boolean input;

FILE *pita;
FILE *pitaFile;


void START(char *path, char *type){
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
    if (path[0] == '\0' && type[0] == '\0'){ 
        input = true;
        pita = stdin;
        ADV();
    } else { // Jika input merupakan direktori
        input = false;
        pitaFile = fopen(path, type); 
        if (pitaFile != NULL){
            ADV();
        }
    }
}

void ADV(){
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
    retval = fscanf(input ? pita : pitaFile, "%c", &currentChar);
    if (IsEOP()){
        fclose(input ? pita : pitaFile);
    }
}

char GetCC(){
/* Mengirimkan currentChar */
    return currentChar;
}

boolean IsEOP(){
/* Mengirimkan true jika currentChar = MARK */
    return retval == EOF;
}

