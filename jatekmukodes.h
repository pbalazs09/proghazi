#ifndef JATEKMUKODES_H
#define JATEKMUKODES_H
#include <stdbool.h>
typedef struct Kerdesek
{
    int nehezseg;
    char kerdes[250];
    char a[40];
    char b[40];
    char c[40];
    char d[40];
    char valasz;
    char temakor[30];
    struct Kerdesek *kov;
} Kerdesek;

typedef struct Dicsoseg {
    char nev[40];
    char nyeremeny[40];
    char ido[60];
} Dicsoseg;

Kerdesek *beolvasas(int *meret);
void jatekosteljesitmenye(int ny, char *nev, int perc, int mp);
void dicsoseglista(void);
void szabalyok(void);
void jatekvege(int idoeleje, int nyeremeny, Kerdesek *eleje);
Kerdesek *kerdeskivalaszt(Kerdesek *eleje, int nehezsegiszint, int meret);
void kerdeskiir(Kerdesek *mozgo);
char segitseg(char betu, Kerdesek *mozgo);
bool helyes_e(char betu, Kerdesek *mozgo, int *ny, int *p);
void felszabadit(Kerdesek *eleje);
#endif

