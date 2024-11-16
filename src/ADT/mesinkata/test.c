#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.c"
#include "mesinkata.c"

int main() {
    START("default.txt", "r");
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    return 0;
}