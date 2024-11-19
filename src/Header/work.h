#ifndef __WORK_H_
#define __WORK_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "misc.h"

#include "../ADT/boolean/boolean.h"
#include "../ADT/array/array.h"


//fungsi untuk menampilkan daftar pekerjaan
void DisplayJobs();

// fungsi yang mengembalikan indeks pekerjaan
int ChooseJob();

//fungsi untuk menunggu dengan durasi sesuai pekerjaan
void Wait(int seconds);

// Main fungsi untuk melakukan pekerjaan yang dipanggil
void DoWork(TabUser *users, IdxType userIdx) ;

#endif