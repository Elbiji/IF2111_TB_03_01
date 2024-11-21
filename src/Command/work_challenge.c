#include "work_challenge.h"

void work_challenge(TabUser *users, IdxType userIdx) {
    boolean status; 
    char perintah[MAX_LEN]; 

    while (1) {
        printf("\n>> WORK CHALLENGE\n");
        printf("\nDaftar challenge yang tersedia:\n");
        printf("1. Tebak Angka (biaya main=200)\n");
        printf("2. W0RDL3 (biaya main=500)\n");
        printf("\nMasukan challenge yang hendak dimainkan (1/2): ");
        
        if (!readInput(perintah, MAX_LEN)) {
            printf("Input tidak valid!\n");
            continue;
        }

        // periksa apakah input valid (1 / 2)
        if (strLength(perintah) == 1 && perintah[0] >= '1' && perintah[0] <= '2') {
            int choice = perintah[0] - '0';  // konversi karakter '1' / '2' menjadi integer

            if (choice == 2) {
                if (users->TC[userIdx].money < 500) {
                    printf("Saldo tidak mencukupi untuk memainkan challenge ini.\n");
                    continue;
                }
                users->TC[userIdx].money -= 500;
                play_wordl(users, userIdx);
            } else if (choice == 1) {
                if (users->TC[userIdx].money < 200) {
                    printf("Saldo tidak mencukupi untuk memainkan challenge ini.\n");
                    continue;
                }
                users->TC[userIdx].money -= 200;
                tebakAngka(userIdx, users);
            }
        } else {
            printf("Input tidak valid! Pilihan harus berupa angka 1 atau 2.\n");
            continue;
        }

        // tanya apakah ingin melanjutkan
        printf("Apakah kamu ingin bekerja kembali? (YA/Purry)\n");
        while (1) {
            if (!readInput(perintah, MAX_LEN)) {
                printf("Input tidak valid! (YA/Purry)\n");
                continue;
            }
            if (isStrEqual(perintah, "YA")) {
                status = true;
                break;
            } else if (isStrEqual(perintah, "Purry")) {
                status = false;
                break;
            } else {
                printf("Input tidak valid! (YA/Purry)\n");
                continue;
            }
        }
        if (status) {
            continue;
        } else {
            break;
        }
    }
    printf("Kamu sudah keluar dari WORK!\n");
}

//int main() {
//    TabUser users; 
//    IdxType userIdx = 0;
//    srand(time(NULL));
//    printf("Saldo awal Anda: %d\n", users.TC[userIdx].money);
//    work_challenge(&users, userIdx);
//
//    return 0;
//}
