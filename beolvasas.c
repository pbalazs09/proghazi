/*#include <stdio.h>
#include <stdlib.h>
#include "beolvasas.h"
#include "menu.h"
#include "jatekmukodes.h"


int beolvasas(void)
{
    FILE *fp; /* f�jl mutat� (file pointer/handle) */

    /*fp = fopen("loim.txt", "rt"); /* megnyit�s */
    /*if (fp == NULL)
    {
        perror("F�jl megnyit�sa sikertelen"); /* nem folytathatjuk! */
       /* return 1;
    }
    Kerdesek beolvas[5000];
    int i = 0;
    while ((fscanf(fp, "%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%c\t%[^\n]\n", &beolvas[i].nehezseg, beolvas[i].kerdes, beolvas[i].a, beolvas[i].b, beolvas[i].c, beolvas[i].d, &beolvas[i].valasz, beolvas[i].temakor)) != EOF) /* beolvas�s a f�jl v�g�ig */
       /* ++i;
    fclose(fp);   /* bez�r�s */
    /*return 0;
}*/

