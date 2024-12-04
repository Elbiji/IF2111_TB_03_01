#include <stdio.h>
#include "mesinkata.h"
#include "../../../misc.h"

void testMesinKata() {
    char path[50];
    char type[2];

    FILE *dummyFile = fopen("dummy.txt", "w");
    if (dummyFile != NULL) {
        fprintf(dummyFile, "HI! Welcome to my dummy gummy file.\n");
        fclose(dummyFile);
        printf("Dummy file 'dummy.txt' has been created.\n");
    } else {
        printf("Failed to create dummy file!\n");
        return;
    }

    printf("--- Testing Mesin Kata  ---\n");
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
        printf("Enter file mode: ");
        readInput(type, 2);

        if (type[0] != 'r' || type[1] != '\0') {
            printf("Invalid file mode. Only 'r' mode is supported.\n");
            return;
        }
        printf("Starting the machine...\n");
        STARTWORD(path, type); 
        printf("Reading words:\n");
        while (!EndWord) {
            printf("%s\n", CurrentWord.TabWord);
            ADVWORD();
        }
        printf("\nEnd of input reached.\n");

    } else if (choice == 2) {
        printf("Enter file path: ");
        readInput(path, 50);
        printf("Enter file mode: ");
        readInput(type, 2);

        if (type[0] != 'w' || type[1] != '\0') {
            printf("Invalid file mode. Only 'w' mode is supported.\n");
            return;
        }
        printf("Starting the machine for writing...\n");
        STARTWORD(path, type);
        printf("Writing to file...\n");

        char word[100];
        while (1) {
            printf("Enter a word ('.' to stop): ");
            readInput(word, 100);
            if (word[0] == '.') {
                break;
            }
            fprintf(pitaFile, "%s ", word); 
        }
        fclose(pitaFile);
        printf("Writing complete.\n");

    } else {
        printf("Invalid input mode.\n");
        return;
    }
}

int main() {
    testMesinKata();
    return 0;
}