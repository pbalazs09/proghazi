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
        char menupont;
        scanf(" %c", &menupont);
        printf("\n");

        switch(menupont)
        {
        case '1':
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
            char nehezsegiszint = 0;
            scanf(" %c", &nehezsegiszint);
            while (nehezsegiszint != '1' && nehezsegiszint != '2' && nehezsegiszint != '3')
            {
                printf(" Kérem 1 és 3 között adjon meg egy számot!\n\n");
                scanf(" %c", &nehezsegiszint);
            }

            printf("\n");
            srand(time(0));
            int kor = 0;
            int random;
            bool korvege = false;
            bool helytelenvalasz = false;

            while (kor != 15 && !helytelenvalasz)
            {
                korvege = false;
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

                while (!korvege)
                {
                    printf(" Kérem adja meg a választott opciót: \n");
                    char betu;
                    scanf(" %c", &betu);
                    printf("\n\n");

                    if (betu == 'e' || betu == 'E' || betu == 'f' || betu == 'F')
                    {
                        segitseg(betu, mozgo, &felhasznaltE, &felhasznaltF);
                    }
                    else if (betu == 'A' || betu == 'B' || betu == 'C' || betu == 'D' ||
                             betu == 'a' || betu == 'b' || betu == 'c' || betu == 'd')
                    {
                        if (!helyes_e(betu, mozgo, &nyeremeny, &penz))
                        {
                            helytelenvalasz = true;
                        }
                        korvege = true;
                        ++kor;
                    }
                    else
                    {
                        printf(" Nem megengedett válasz! Kérem adjon meg egy újabbat!\n\n");
                    }
                }
            }
            jatekvege(idoeleje, nyeremeny, eleje);
        }
        break;
        case '2':
            szabalyok();
            break;
        case '3':
            dicsoseglista();
            break;
        case '4':
            return 0;
            break;
        default:
            printf(" Kérem a fenti 4 lehetőség valamelyikét adja meg!\n\n");
        }
    }
    return 0;
}
