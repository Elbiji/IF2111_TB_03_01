#include <stdio.h>
#include "mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"
#include "../mesinkarakter/mesinkarakter.c"
#include "mesinkata.c"

int main() {
    START("default.txt", "r");
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    printf("\n");
    STARTWORD("test.txt", "r");
    while (!EndWord) {
        printf("%s\n", CurrentWord);
        ADVWORD();
    }

}