#include "../Header/save.h"

// #include "../Header/Load.h"
// #include "../Header/misc.h"
// #include <stdio.h>
// #include <stdlib.h>

// Fungsi untuk menyimpan data ke dalam file
void save(TabUser *Users, ArrayDinBarang *array) {
    char filename[MAX_LEN];
    
    while (1){
        printf("Masukkan nama file untuk SAVE state program: \n");
        char dest[MAX_LEN] = "save/";
        if (!readInput(filename, MAX_LEN)){
            continue;
        }
        customStrcat(dest, filename);
        printf("%s\n",dest); 

        FILE *file = fopen(dest, "w");
        fprintf(file,"%d\n", array->Neff);
        for (int i = 0; i < array->Neff; i++){
            fprintf(file, "%d %s\n", array->A[i].price, array->A[i].name);
        }

        fprintf(file,"%d\n", Users->Neff);
        for (int i = 0; i < Users->Neff; i++){
            if (i == Users->Neff-1){
                fprintf(file, "%d %s %s", Users->TC[i].money, Users->TC[i].name, Users->TC[i].password);
            } else {
                fprintf(file, "%d %s %s\n", Users->TC[i].money, Users->TC[i].name, Users->TC[i].password);
            }
        }
        fclose(file);
        printf("Save file berhasil disimpan\n");
        break;
    }
}


// int main() {
//     // Misalnya ada TabUser dan ArrayDinBarang yang sudah terisi sebelumnya
//     TabUser Users;
//     ArrayDinBarang Items;
    
//     // Memastikan data telah dimuat ke dalam Users dan Items (misalnya dengan fungsi load sebelumnya)

//     // Nama file untuk menyimpan data
//     char filename[256] = "savefile.txt";  // Nama file yang ingin disimpan

//     // Panggil fungsi save untuk menyimpan data
//     save(filename, &Users, &Items);

//     return 0;
// }