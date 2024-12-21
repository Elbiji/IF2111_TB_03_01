#include "wordl399.h"

const char *valid_words[] = {"kotak", "katak", "demon", "dokja", "tapir", "kocak"};
const int word_count = sizeof(valid_words) / sizeof(valid_words[0]);

// pilih kata acak
void pick_random(char *word) {
    srand(time(NULL));
    int random_index = rand() % word_count;
    copystrng(word, valid_words[random_index]);
}

void play_wordl(TabUser *users, IdxType userIdx) {
    char target_word[WORD_LENGTH + 1];
    char guess[WORD_LENGTH + 1];
    char feedback[WORD_LENGTH + 1];
    int chances = MAX_CHANCES;
    int success = 0;

    pick_random(target_word);

    printf("\nWELCOME TO W0RDL3! YOU HAVE %d CHANCES TO GUESS THE WORD!\n", MAX_CHANCES);
    for (int i = 0; i < MAX_CHANCES; i++) {
        printf("_ _ _ _ _\n");
    }

    while (chances > 0) {
        printf("\nMasukkan kata tebakan Anda (input dalam lowercase): ");
        if (!readInput(guess, WORD_LENGTH + 1)) {
            printf("Input tidak valid! Pastikan input terdiri dari 5 huruf.\n");
            continue;
        }

        if (strLength(guess) != WORD_LENGTH) {
            printf("Kata tebakan harus terdiri dari %d huruf.\n", WORD_LENGTH);
            continue;
        }

        // periksa tebakan
        check_guess(guess, target_word, feedback);

        // tampilkan hasil
        printf("Hasil:\n");
        print_feedback(guess, feedback);

        // periksa menang 
        if (isStrEqual(guess, target_word)) {
            success = 1;
            break;
        }

        chances--;
    }

    if (success) {
        printf("\nSelamat, Anda menang!\n");
        users->TC[userIdx].money += 1500;
        printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
    } else {
        printf("\nBoo! Anda kalah. Kata yang benar adalah: %s\n", target_word);
    }
}
