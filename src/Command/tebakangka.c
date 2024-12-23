#include "../Header/tebakangka.h"

void tebakAngka(IdxType iduser, TabUser *Users){
    const int hadiahMax = 500;
    const int maxKesempatan = 10;

    srand(time(NULL));
    int target = rand() % 100 + 1; 
    int kesempatanTerpakai = 0;
    int hadiah = 0;

    printf("Mulai challenge Tebak Angka!\n");
    while (kesempatanTerpakai < maxKesempatan) {
        char Tebakan [3];
        if (!readInput(Tebakan, 4)) continue;
        if (!isStrAllDigit(Tebakan)) {
            printf("Masukkan sebuah integer dari 1-100!\n");
            continue;
        }
        int val = atoi(Tebakan);
        kesempatanTerpakai++;

        if (val == target) {
            hadiah = hadiahMax - (kesempatanTerpakai - 1) * 50;
            if (hadiah < 0) hadiah = 0;
            Users->TC[iduser].money += hadiah;
            printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke akun anda.\n", hadiah);
            return;
        } else if (val < target) {
            printf("Tebakanmu lebih kecil!\n");
        } else {
            printf("Tebakanmu lebih besar!\n");
        }
    }

    printf("Kesempatan habis! Angka yang benar adalah %d. Tidak ada hadiah.\n", target);
}

// int main() {
//     StaticListUser userList;
//     userList.count = 1; 
//     User *currentUser = &userList.users[0]; 

//     snprintf(currentUser->name, MAX_LEN, "Player1");
//     snprintf(currentUser->password, MAX_LEN, "password123");
//     currentUser->money = 1000; 

//     int pilihan;

//     do {
//         printf(">> WORK CHALLENGE\n\n");
//         printf("Daftar challenge yang tersedia:\n");
//         printf("1. Tebak Angka (biaya main=200)\n");
//         printf("2. Keluar\n");
//         printf("Masukkan pilihan: ");
//         scanf("%d", &pilihan);

//         switch (pilihan) {
//             case 1:
//                 tebakAngka(currentUser);
//                 break;
//             case 2:
//                 printf("Terima kasih telah bermain!\n");
//                 break;
//             default:
//                 printf("Pilihan tidak valid!\n");
//         }

//         printf("\nSaldo anda: %d rupiah\n", currentUser->money);
//     } while (pilihan != 2);

//     return 0;
// }