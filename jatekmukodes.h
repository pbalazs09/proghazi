#ifndef JATEKMUKODES_H
#define JATEKMUKODES_H
#include <stdbool.h>
typedef struct Kerdesek
{
    int nehezseg;
    char kerdes[150];
    char a[30];
    char b[30];
    char c[30];
    char d[30];
    char valasz;
    char temakor[20];
} Kerdesek;

void beolvasas(Kerdesek *beol);
char segitseg(char betu, int random, Kerdesek *beolvas);
bool helyes_e(char betu, Kerdesek *beolvas, int random);
void jatekindit(void);


#endif

