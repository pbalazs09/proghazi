#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "jatekmukodes.h"
#include <time.h>
#include "debugmalloc.h"
#ifdef _WIN32
#include <windows.h>
#endif


int main(void)
{
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    bool vege = false;
    while (!vege)
    {
        menukirajzol();

        printf(" Sorszám: ");
        int szam;
        scanf("%d", &szam);
        printf("\n");

        switch(szam)
        {
        case 1:
        {
            int idoeleje;
            int nyeremeny = 0;
            int penz = 1000;
            bool tovabb = false;
            idoeleje = time(0);
            Kerdesek *eleje = NULL;
            Kerdesek *mozgo = NULL;
            bool felhasznaltE = false;
            bool felhasznaltF = false;
            bool sikertelen = true;
            int x = 0;
            int meret = 0;
            eleje = beolvasas(&meret);
            if (eleje == NULL)
                return 1;
            printf(" Válasszon nehézségi szintet! 1 - 3: ");
            int nehezsegiszint;
            scanf("%d", &nehezsegiszint);
            printf("\n");
            srand(time(0));
            int kor = 0;
            int random;


            while (kor != 15)
            {
                printf(" %d. kérdés:\n\n", kor+1);
                mozgo = kerdeskivalaszt(eleje, nehezsegiszint, meret);
                kerdeskiir(mozgo);
                if (!felhasznaltE)
                {
                    printf(" E: Közönség segítsége\n");
                }
                if (!felhasznaltF)
                {
                    printf(" F: Felezés\n\n");
                }
                /*printf("%c\n\n", mozgo->valasz);*/
                printf(" Helyes válasz betűjele: ");
                char betu;
                scanf(" %c", &betu);
                printf("\n\n");
                if (betu == 'E' || betu == 'F')
                {
                    sikertelen = true;
                    x = 0;
                    while(sikertelen)
                    {
                        if (x != 0)
                        {
                            printf(" Felhasználtad már a segítséget!\n");
                            printf(" Új válasz: ");
                            scanf(" %c", &betu);
                        }
                        if ((betu == 'E') && !felhasznaltE)
                        {
                            betu = segitseg(betu, mozgo);
                            felhasznaltE = true;
                            sikertelen = false;
                        }
                        if ((betu == 'F') && !felhasznaltF)
                        {
                            betu = segitseg(betu, mozgo);
                            felhasznaltF = true;
                            sikertelen = false;
                        }
                        if (betu == 'A' || betu == 'B' || betu == 'C' || betu == 'D')
                        {
                            sikertelen = false;
                        }
                        ++x;
                    }
                }
                if (!helyes_e(betu, mozgo, &nyeremeny, &penz))
                {
                    printf(" Rossz válasz! Vége a játéknak!\n\n");
                    printf(" Ez volt a helyes válasz: ");
                    printf(" %c\n\n", mozgo->valasz);
                    jatekvege(idoeleje, nyeremeny, eleje);
                    tovabb = true;
                    kor = 15;
                }
                if (!tovabb)
                    ++kor;
            }
            if (!tovabb)
                jatekvege(idoeleje, nyeremeny, eleje);
        }
        break;
        case 2:
            szabalyok();
            break;
        case 3:
            dicsoseglista();
            break;
        case 4:
            return 0;
            break;
        default:
            return 1;
        }
    }
    return 0;
}
