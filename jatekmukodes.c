#include <stdio.h>
#include <stdlib.h>
#include "beolvasas.h"
#include "menu.h"
#include "jatekmukodes.h"
#include <time.h>
#include <stdbool.h>

void beolvasas(Kerdesek *beol)
{
    FILE *fp; /* fájl mutató (file pointer/handle) */
    fp = fopen("loim.txt", "rt"); /* megnyitás */
    if (fp == NULL)
    {
        perror("Fájl megnyitása sikertelen"); /* nem folytathatjuk! */
        beol[0].nehezseg = -1;
        return;
    }

    int i = 0;
    while ((fscanf(fp, "%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%c\t%[^\n]\n", &beol[i].nehezseg, beol[i].kerdes, beol[i].a, beol[i].b, beol[i].c, beol[i].d, &beol[i].valasz, beol[i].temakor)) != EOF) /* beolvasás a fájl végéig */
        ++i;
    fclose(fp);   /* bezárás */
}

char segitseg(char betu, int random, Kerdesek *beolvas) {
    if (betu == 'E') {
        int tipp;
        tipp = rand()%100+1;
        if (tipp == 13 || tipp == 69) {
            if (beolvas[random].valasz == 'A')
                printf("A közönség tippje: B");
            if (beolvas[random].valasz == 'B')
                printf("A közönség tippje: C");
            if (beolvas[random].valasz == 'C')
                printf("A közönség tippje: D");
            if (beolvas[random].valasz == 'D')
                printf("A közönség tippje: A");
        }
        printf("A közönség tippje: %c\n", beolvas[random].valasz);
        scanf(" %c", &betu);
        return betu;
    }

}

bool helyes_e(char betu, Kerdesek *beolvas, int random) {
    if (beolvas[random].valasz == betu) {
        printf("Helyes válasz!\n\n");
        printf("-------------------\n\n");
        return true;
    }
    else
        return false;
}

void jatekindit(void)
{
    Kerdesek beolvas[5000];
    beolvasas(beolvas);
    if (beolvas[0].nehezseg == -1)
        return 1;
    printf("Válasszon nehézségi szintet! 1 - 15: ");
    int nehezsegiszint;
    scanf("%d", &nehezsegiszint);
    srand(time(0));
    int kor = 0;

    while (kor != 15) {
        printf("%d. kérdés:\n", kor+1);
        int random = rand()%5000+1;
        while (beolvas[random].nehezseg != nehezsegiszint){
            random = rand()%5000+1;
        }

        printf("%s\n\n", beolvas[random].kerdes);
        printf("A: %s\n", beolvas[random].a);
        printf("B: %s\n", beolvas[random].b);
        printf("C: %s\n", beolvas[random].c);
        printf("D: %s\n\n", beolvas[random].d);
        printf("E: Közönség segítsége\n");
        printf("F: Felezés\n\n");
        printf("%c\n\n", beolvas[random].valasz);
        printf("Helyes válasz betűjele: \n");
        char betu;
        scanf(" %c", &betu);
        printf("\n");
        if (betu == 'E' || betu == 'F')
            betu = segitseg(betu, random, beolvas);
        if (!helyes_e(betu, beolvas, random)){
            printf("Rossz válasz! Vége a játéknak!\n");
            return;
        }
        ++kor;


    }


}

