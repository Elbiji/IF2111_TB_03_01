#include "../Header/quantum_wordl3.h"

const char *quantum_valid_words[] = {"maria", "katak", "demon", "dokja", "tapir", "ivana", "bagas", "kocak", "aziza", "aulia"};
const int quantum_word_count = sizeof(quantum_valid_words) / sizeof(quantum_valid_words[0]);

void pick_random_words(char words[QUANTUM_WORD_COUNT][WORD_LENGTH + 1]) {
    srand(time(NULL));
    for (int i = 0; i < QUANTUM_WORD_COUNT; i++) {
        int random_index = rand() % quantum_word_count;
        copystrng(words[i], quantum_valid_words[random_index]);

        // pastiin katanya berbeda
        for (int j = 0; j < i; j++) {
            if (isStrEqual(words[i], words[j])) {
                i--; // pilih ulang jika duplikat
                break;
            }
        }
    }
}

void check_quantum_guess(const char guesses[QUANTUM_WORD_COUNT][WORD_LENGTH + 1], const char targets[QUANTUM_WORD_COUNT][WORD_LENGTH + 1], char feedbacks[QUANTUM_WORD_COUNT][WORD_LENGTH + 1]) {
    for (int i = 0; i < QUANTUM_WORD_COUNT; i++) {
        check_guess(guesses[i], targets[i], feedbacks[i]);
    }
}

void print_quantum_feedback(const char guesses[QUANTUM_WORD_COUNT][WORD_LENGTH + 1], const char feedbacks[QUANTUM_WORD_COUNT][WORD_LENGTH + 1]) {
    for (int i = 0; i < QUANTUM_WORD_COUNT; i++) {
        printf("Tebakan %d: ", i + 1);
        print_feedback(guesses[i], feedbacks[i]);
    }
}

void play_quantum_wordl(TabUser *users, IdxType userIdx) {
    char target_words[QUANTUM_WORD_COUNT][WORD_LENGTH + 1];
    char guesses[QUANTUM_WORD_COUNT][WORD_LENGTH + 1];
    char feedbacks[QUANTUM_WORD_COUNT][WORD_LENGTH + 1];
    int chances = MAX_QUANTUM_CHANCES;
    int success = 0;

    pick_random_words(target_words);

    printf("\nWELCOME TO QUANTUM W0RDL3! YOU HAVE %d CHANCES TO GUESS FOUR WORDS!\n", MAX_QUANTUM_CHANCES);
    for (int i = 0; i < MAX_QUANTUM_CHANCES; i++) {
        printf("_ _ _ _ _     _ _ _ _ _     _ _ _ _ _     _ _ _ _ _\n");
    }

    while (chances > 0) {
        printf("\nMasukkan empat kata tebakan Anda (pisahkan dengan spasi): ");
        char input[WORD_LENGTH * QUANTUM_WORD_COUNT + QUANTUM_WORD_COUNT];
        if (!readInput(input, sizeof(input))) {
            printf("Input tidak valid! Pastikan memasukkan tepat 4 kata, masing-masing 5 huruf.\n");
            continue;
        }

        // pisah input menjadi empat kata
        int valid = 1;
        int start = 0, end = 0, guess_index = 0;
        while (input[end] != '\0' && guess_index < QUANTUM_WORD_COUNT) {
            if (input[end] == ' ' || input[end + 1] == '\0') {

                // kalo kata terakhir buat penyesuaian di ekstrak bagian substring
                if (input[end + 1] == '\0') {
                    end++; 
                }       

                int length = end-start;
                if (length != WORD_LENGTH) {
                    valid = 0;
                    break;
                }
                substring(input, start, end-1, guesses[guess_index]);
                // printf("Extracted word %d: '%s'\n", guess_index + 1, guesses[guess_index]); // Debug

                if (input[end] == ' ') {
                    end++;
                }

                start = end;
                guess_index++;
            }
            end++;
        }

        if (!valid || guess_index != QUANTUM_WORD_COUNT) {
            printf("Input tidak valid! Pastikan setiap kata memiliki 5 huruf dan terdapat 4 kata.\n");
            continue;
        }

        // periksa tebakan
        check_quantum_guess(guesses, target_words, feedbacks);

        // nampil hasil
        printf("Hasil:\n");
        print_quantum_feedback(guesses, feedbacks);

        // periksa menang
        success = 1;
        for (int i = 0; i < QUANTUM_WORD_COUNT; i++) {
            // printf("guess : %s target: %s\n",guesses[i], target_words[i]);
            if (!isStrEqual(guesses[i], target_words[i])) {
                success = 0;
                break;
            }
        }

        if (success) {
            break;
        }

        chances--;
    }

    if (success) {
        printf("\nSelamat, Anda menang Quantum W0RDL3!\n");
        users->TC[userIdx].money += 10000;
        printf("+10000 rupiah telah ditambahkan ke akun Anda ⪩⑅⪨.\n");
    } else {
        printf("\nBoo! Anda kalah [•.•ิ]. Kata-kata yang benar adalah:\n");
        for (int i = 0; i < QUANTUM_WORD_COUNT; i++) {
            printf("%s\n", target_words[i]);
        }
    }
}
