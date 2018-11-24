#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "jatekmukodes.h"
#include <time.h>
#include <stdbool.h>
#include "debugmalloc.h"

Kerdesek *beolvasas(int *meret)
{
    FILE *fp; /* fájl mutató (file pointer/handle) */
    fp = fopen("loim.txt", "rt"); /* megnyitás */
    if (fp == NULL)
    {
        perror("Fájl megnyitása sikertelen"); /* nem folytathatjuk! */
        return NULL;
    }

    int i = 1;
    int ch = 0;
    while (!feof(fp)) {
        ch = fgetc(fp);
        if(ch == '\n')
            ++i;
    }
    fclose(fp);   /* bezárás */

    *meret = i;

    fp = fopen("loim.txt", "rt"); /* megnyitás */
    if (fp == NULL)
    {
        perror("Fájl megnyitása sikertelen"); /* nem folytathatjuk! */
        return NULL;
    }


    Kerdesek *lis = NULL;
    for (int i = 0; i < *meret+1; i++) {
        Kerdesek *uj;
        uj = (Kerdesek*) malloc(sizeof(Kerdesek));
        uj->kov = lis;
        lis = uj;
    }
    Kerdesek *eleje;
    eleje = lis;
    Kerdesek *mozgo = eleje;
    while ((fscanf(fp, "%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%c\t%[^\n]\n", &mozgo->nehezseg, mozgo->kerdes, mozgo->a, mozgo->b, mozgo->c, mozgo->d, &mozgo->valasz, mozgo->temakor)) != EOF) /* beolvasás a fájl végéig */
            mozgo = mozgo->kov;
    fclose(fp);   /* bezárás */
    return eleje;
}

void felszabadit(Kerdesek *eleje) {
    Kerdesek *mozgo = eleje;
    while(mozgo != NULL) {
        mozgo = mozgo->kov;
        free(eleje);
        eleje = mozgo;
    }
}

void jatekosteljesitmenye(int ny, char *nev, int perc, int mp)
{
    FILE *dp;
    dp = fopen("dicsoseglista.txt", "at");
    if (dp == NULL)
    {
        perror("Fájl megnyitása sikertelen");
        return;
    }

    fprintf(dp, " Név: %s\tNyeremény: %d Ft\tJátékban eltöltött idő: %d perc %d másodperc\n", nev, ny, perc, mp);
    fclose(dp);
}

void dicsoseglista(void)
{

    int k;
    FILE *dicsp; /* fájl mutató (file pointer/handle) */

    dicsp = fopen("dicsoseglista.txt", "rt"); /* megnyitás */
    if (dicsp == NULL)
    {
        perror("Fájl megnyitása sikertelen"); /* nem folytathatjuk! */
        return;
    }

    int sz = 1;
    int ch = 0;
    while (!feof(dicsp)) {
        ch = fgetc(dicsp);
        if(ch == '\n')
            ++sz;
    }
    fclose(dicsp);   /* bezárás */

    int meret = sz;

    dicsp = fopen("dicsoseglista.txt", "rt"); /* megnyitás */
    if (dicsp == NULL)
    {
        perror("Fájl megnyitása sikertelen"); /* nem folytathatjuk! */
        return;
    }

    Dicsoseg *dics = (Dicsoseg*) malloc(meret * sizeof(Dicsoseg));
    int i = 0;
    while ((fscanf(dicsp, "%[^\t]\t%[^\t]\t%[^\n]\n", dics[i].nev, dics[i].nyeremeny, dics[i].ido)) != EOF) /* beolvasás a fájl végéig */
        ++i;
    printf(" Dicsőséglista:\n\n");
    for (k = i-1; k >= 0; --k)
        printf(" %s\t%s\t%s\n", dics[k].nev, dics[k].nyeremeny, dics[k].ido);
    printf("\n\n");
    fclose(dicsp);   /* bezárás */
    free(dics);
}

void szabalyok(void) {
printf("Minden kérdésre egy helyes válasz van!\n2 segítség közül lehet választani, mindegyik csak egyszer használható fel!\nJó válasz esetén tovább léphetünk a következő kérdésre, rossz válasz esetén azonban vége a játéknak.\nA kérdéshez tartozó betűjel beírásával adhatjuk meg válaszunkat.\n");
}

char segitseg(char betu, Kerdesek *mozgo)
{
    if (betu == 'E')
    {
        int tipp;
        tipp = rand()%100+1;
        if (tipp == 13 || tipp == 69)
        {
            if (mozgo->valasz == 'A')
                printf(" A közönség tippje: B");
            if (mozgo->valasz == 'B')
                printf(" A közönség tippje: C");
            if (mozgo->valasz == 'C')
                printf(" A közönség tippje: D");
            if (mozgo->valasz == 'D')
                printf(" A közönség tippje: A");
        }
        printf(" A közönség tippje: %c\n\n", mozgo->valasz);
        printf(" Helyes válasz betűjele: ");
        scanf(" %c", &betu);
        printf("\n");
        return betu;
    }
    if (betu == 'F')
    {
        if (mozgo->valasz == 'A')
        {
            printf(" A: %s\n", mozgo->a);
            printf(" C: %s\n\n", mozgo->c);
            printf(" Helyes válasz betűjele: ");
            scanf(" %c", &betu);
            printf("\n");
            return betu;
        }
        if (mozgo->valasz == 'B')
        {
            printf(" A: %s\n", mozgo->a);
            printf(" B: %s\n\n", mozgo->b);
            printf(" Helyes válasz betűjele: ");
            scanf(" %c", &betu);
            printf("\n");
            return betu;
        }
        if (mozgo->valasz == 'C')
        {
            printf(" A: %s\n", mozgo->a);
            printf(" C: %s\n\n", mozgo->c);
            printf(" Helyes válasz betűjele: ");
            scanf(" %c", &betu);
            printf("\n");
            return betu;
        }
        if (mozgo->valasz == 'D')
        {
            printf(" B: %s\n", mozgo->b);
            printf(" D: %s\n\n", mozgo->d);
            printf(" Helyes válasz betűjele: ");
            scanf(" %c", &betu);
            printf("\n");
            return betu;
        }
    }
}

bool helyes_e(char betu, Kerdesek *mozgo, int *ny, int *p)
{
    if (mozgo->valasz == betu || (mozgo->valasz == (betu - 32)))
    {
        printf(" ===============\n");
        printf(" Helyes válasz!\n");
        printf(" ===============\n\n");
        printf(" -----------------------------------------------------------------\n\n");
        *ny = *ny + *p;
        *p = *p*2;
        return true;
    }
    else
        return false;
}

void jatekvege(int idoeleje, int nyeremeny, Kerdesek *eleje) {
    int idovege;
    int perc, mp;
            idovege = time(0);
            perc = (idovege - idoeleje)/60;
            mp = (idovege - idoeleje)%60;
            printf(" Nyereménye: %d Ft\n", nyeremeny);
            printf(" Játékban eltöltött idő: %d perc %d másodperc\n", perc, mp);
            printf(" Adja meg a becenevét: ");
            char nev[40];
            scanf("%s", nev);
            printf("\n");
            jatekosteljesitmenye(nyeremeny, nev, perc, mp);
            felszabadit(eleje);
}

Kerdesek *kerdeskivalaszt(Kerdesek *eleje, int nehezsegiszint, int meret) {
        Kerdesek *mozgo = eleje;
        int random = rand()%meret;
        for (int i = 0; i < random; ++i)
            mozgo = mozgo->kov;
        if (nehezsegiszint == 1)
        {
            while ((mozgo->nehezseg != 1) && (mozgo->nehezseg != 2) && (mozgo->nehezseg != 3) && (mozgo->nehezseg != 4) && (mozgo->nehezseg != 5))
            {
                random = rand()%meret;
                mozgo = eleje;
                for (int i = 0; i < random; ++i)
                    mozgo = mozgo->kov;
            }
            return mozgo;
        }
        if (nehezsegiszint == 2)
        {
            while ((mozgo->nehezseg != 6) && (mozgo->nehezseg != 7) && (mozgo->nehezseg != 8) && (mozgo->nehezseg != 9) && (mozgo->nehezseg != 10))
            {
                random = rand()%meret;
                mozgo = eleje;
                for (int i = 0; i < random; ++i)
                    mozgo = mozgo->kov;
            }
            return mozgo;
        }
        if (nehezsegiszint == 3)
        {
            while ((mozgo->nehezseg != 11) && (mozgo->nehezseg != 12) && (mozgo->nehezseg != 13) && (mozgo->nehezseg != 14) && (mozgo->nehezseg != 15))
            {
                random = rand()%meret;
                mozgo = eleje;
                for (int i = 0; i < random; ++i)
                    mozgo = mozgo->kov;
            }
            return mozgo;
        }
}

void kerdeskiir(Kerdesek *mozgo) {
        printf(" %s\n\n", mozgo->kerdes);
        printf(" A: %s\n", mozgo->a);
        printf(" B: %s\n", mozgo->b);
        printf(" C: %s\n", mozgo->c);
        printf(" D: %s\n\n", mozgo->d);
}

