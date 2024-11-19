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

//fungsi mencari pekerjaan berdasarkan nama
int FindJobByName(char *jobname) {
    for (int i = 0; i < totaljob; i++) {
        if (strcmp(listjob[i].name, jobname) == 0) {
            return i; //kembalikan indeks yang sesuai
        }
    }
    return -1; //kalau tidak ada, kembalikan -1
}

//fungsi meminta input nama pekerjaan
int ChooseJob() {
    char jobname[50];
    int jobIdx;

    do {
        printf("Masukkan nama pekerjaan yang dipilih: ");
        scanf(" %[^\n]", jobname); //baca input string pakai spasi
        jobIdx = FindJobByName(jobname);
        if (jobIdx == -1) {
            printf("Pekerjaan tidak ditemukan. Silakan coba lagi.\n");
        }
    } while (jobIdx == -1);

    return jobIdx; //mengembalikan indeks pekerjaan yang valid
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
    int newBalance = users->TC[userIdx].money + listjob[jobIdx].income;

    //perbarui saldo pakai SetMoney
    SetMoney(users, userIdx + 1, newBalance); //userIdx ke-0 diubah ke indeks ADT (dimulai dari 1)
}