#include <stdio.h>
#include <stdlib.h>
#include "beolvasas.h"
#include "menu.h"
#include "jatekmukodes.h"
#ifdef _WIN32
#include <windows.h>
#endif

void menukirajzol(void) {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    printf("Legyen �n is milliomos!\n");
    printf(" 1 - J�t�k ind�t�sa\n");
    printf(" 2 - Szab�lyok\n");
    printf(" 3 - Dics�s�glista\n");
    printf(" 4 - Kil�p�s\n");
    }
