#ifndef __HELP_H_
#define __HELP_H_

#include <stdio.h>
#include "../../misc.h"

typedef enum {
    welcome_menu,
    login_menu,
    main_menu
} MenuState;

//fungsi untuk menampilkan HELP sesuai menu aktif
void help(MenuState *current_menu);
//fungsi ganti menu
void change_menu(MenuState *current_menu, MenuState new_menu);
#endif