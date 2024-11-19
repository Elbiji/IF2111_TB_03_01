#include "../Header/work.h"

// Fungsi untuk menampilkan daftar pekerjaan
void DisplayJobs() {
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < totaljob; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n",
               i + 1, listjob[i].name,
               listjob[i].income,
               listjob[i].duration);
    }
}

// Fungsi untuk mencari pekerjaan berdasarkan nama
int FindJobByName(char *jobname) {
    for (int i = 0; i < totaljob; i++) {
        if (strcmp(listjob[i].name, jobname) == 0) {
            return i; // Kembalikan indeks pekerjaan yang cocok
        }
    }
    return -1; // Jika tidak ditemukan
}

// Fungsi untuk meminta input nama pekerjaan
int ChooseJob() {
    char jobname[50];
    int jobIdx;

    do {
        printf("Masukkan nama pekerjaan yang dipilih: ");
        scanf(" %[^\n]", jobname); // Membaca input string dengan spasi
        jobIdx = FindJobByName(jobname);
        if (jobIdx == -1) {
            printf("Pekerjaan tidak ditemukan. Silakan coba lagi.\n");
        }
    } while (jobIdx == -1);

    return jobIdx; // Mengembalikan indeks pekerjaan yang valid
}

// Fungsi untuk menunggu dengan durasi tertentu menggunakan time.h
void Wait(int seconds) {
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < seconds);
}

// Fungsi untuk melakukan pekerjaan
void DoWork(TabUser *users, IdxType userIdx) {
    DisplayJobs(); // Tampilkan daftar pekerjaan
    int jobIdx = ChooseJob(); // Pilih pekerjaan berdasarkan nama
    printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", listjob[jobIdx].name);

    Wait(listjob[jobIdx].duration); // Simulasi waktu kerja

    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", listjob[jobIdx].income);

    // Hitung saldo baru
    int newBalance = users->TC[userIdx].money + listjob[jobIdx].income;

    // Perbarui saldo menggunakan SetMoney
    SetMoney(users, userIdx + 1, newBalance); // userIdx ke-0 diubah ke indeks ADT (dimulai dari 1)
}