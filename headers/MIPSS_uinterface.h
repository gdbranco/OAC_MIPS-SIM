#ifndef MIPSS_UI_H
#define MIPSS_UI_H
#include <iostream>
#include <cstdlib>
#include "./MIPSS_filectrl.h"
#include "./MIPSS_flowctrl.h"

#if defined(_WIN32)
    #define COMMAND "cls"
#else
    #define COMMAND "clear"
#endif

#define wipe() {system(COMMAND);}

void menu();
void menu_step();
void menu_dump_mem();
void menu_dump_regs();
#endif // MIPSS_UI_H
