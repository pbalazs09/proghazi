#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "jatekmukodes.h"
#include "debugmalloc.h"
#include "beolvasas.h"
#ifdef _WIN32
#include <windows.h>
#endif

void menukirajzol(void) {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    printf(" Legyen Ön is milliomos!\n");
    printf(" 1 - Játék indítása\n");
    printf(" 2 - Szabályok\n");
    printf(" 3 - Dicsõséglista\n");
    printf(" 4 - Kilépés\n\n");
    }
