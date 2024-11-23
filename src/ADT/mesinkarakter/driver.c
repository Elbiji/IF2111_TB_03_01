#include <stdio.h>
#include "mesinkarakter.h"
#include "../../misc.h" 

void testMesinKarakter() {
    char path[50];
    char type[2];

    printf("--- Testing Mesin Karakter  ---\n");

    // nulis dummy file
    FILE *dummyFile = fopen("dummy.txt", "w");
    if (dummyFile != NULL) {
        fprintf(dummyFile, "HI! Welcome to my dummy gummy file.\n");
        fclose(dummyFile);
        printf("Dummy file 'dummy.txt' has been created.\n");
    } else {
        printf("Failed to create dummy file!\n");
        return;
    }

    // pilih mode input
    printf("Choose input mode:\n");
    printf("1. Read from file (dummy.txt)\n");
    printf("2. Write to file (dummy.txt)\n");
    printf("Enter your choice: ");
    char input[2];
    readInput(input, 2);
    int choice = atoi(input);

    if (choice == 1) {
        printf("Enter file path: ");
        readInput(path, 50);
        printf("Enter file mode (r): ");
        readInput(type, 2);

        if (type[0] != 'r' || type[1] != '\0') {
            printf("Invalid file mode. Only 'r' mode is supported.\n");
            return;
        }
        printf("Starting the machine...\n");
        START(path, type);
        printf("Reading characters until EOF:\n");
        while (!IsEOP()) {
            printf("%c", GetCC());
            ADV();
        }
        printf("\nEnd of input reached.\n");

    } else if (choice == 2) {
        printf("Enter file path: ");
        readInput(path, 50);
        printf("Enter file mode (w): ");
        readInput(type, 2);

        if (type[0] != 'w' || type[1] != '\0') {
            printf("Invalid file mode. Only 'w' mode is supported.\n");
            return;
        }
        printf("Starting the machine for writing...\n");
        START(path, type);
        printf("Writing to file...\n");
        char ch;

        while (1) {
            printf("Enter a character ('.' to stop): ");
            readInput(&ch, 2);
            if (ch == '.') {
                break;
            }
            fprintf(pitaFile, "%c", ch);
        }
        fclose(pitaFile);
        printf("Writing complete.\n");
    } else {
        printf("Invalid input mode.\n");
        return;
    }
}

int main() {
    testMesinKarakter();
    return 0;
}