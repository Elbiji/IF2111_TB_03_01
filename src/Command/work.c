#include "../Header/work.h"

//fungsi untuk menampilkan daftar pekerjaan
void DisplayJobs() {
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < totaljob; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n",
               i + 1, listjob[i].name,
               listjob[i].income,
               listjob[i].duration);
    }
}

int ChooseJob() {
    char jobname[50];
    int jobIdx;

    do {
        printf("Masukkan nama pekerjaan yang dipilih: ");
        if (!readInput(jobname, 50)) {
            printf("Input tidak valid. Silakan coba lagi.\n");
            continue;
        }
        if (isStrAllDigit(jobname)) {
            printf("Pastikan Anda memasukkan nama pekerjaan berupa karakter.\n");
            continue;
        }
        jobIdx = IndexJobInList(listjob, totaljob, jobname);
        if (jobIdx == -1) {
            printf("Pekerjaan tidak ditemukan. Silakan coba lagi.\n");
        }
    } while (jobIdx == -1);

    return jobIdx; // Mengembalikan indeks pekerjaan yang valid
}

//fungsi untuk menunggu dengan durasi sesuai pekerjaan
void Wait(int seconds) {
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < seconds);
}

//fungsi untuk melakukan pekerjaan
void DoWork(TabUser *users, IdxType userIdx) {
    DisplayJobs(); //nampilin daftar pekerjaan
    int jobIdx = ChooseJob(); //pilih pekerjaan berdasarkan nama
    printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", listjob[jobIdx].name);

    Wait(listjob[jobIdx].duration); //waktu kerja

    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", listjob[jobIdx].income);

    //hitung saldo baru
    users->TC[userIdx].money += listjob[jobIdx].income;
}