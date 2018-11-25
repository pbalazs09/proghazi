#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "jatekmukodes.h"
#include <time.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "beolvasas.h"

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
