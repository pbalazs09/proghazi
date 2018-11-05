#include <stdio.h>
#include <stdlib.h>
#include "beolvasas.h"
#include "menu.h"
#include "jatekmukodes.h"
#ifdef _WIN32
#include <windows.h>
#endif


int main(void)
{
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif


    menukirajzol();

    printf("Sorszám: ");
    int szam;
    scanf("%d", &szam);

    switch(szam)
    {
    case 1:
        jatekindit();
        break;
    /*case 2:
        szabalyok();
        break;
    case 3:
        dicsoseglista();
        break;
    case 4:
        kilepes();
        break;
    default: return 1;
    /*helyes_e(betu);*/
    }
}
