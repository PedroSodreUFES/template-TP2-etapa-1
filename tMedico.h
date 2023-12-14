#ifndef _TMEDICO_H_
#define _TMEDICO_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct _tMedico tMedico;

tMedico *CriaMedico();

void PrintaMedico(tMedico *m);

void DesalocaMedico(tMedico *m);

char *retornaCPFmedico(tMedico *m);

char *retornaloginmedico(tMedico *m);

char *retornasenhamedico(tMedico *m);

char *retornanomemedico(tMedico *m);

char *retornacrmmedico(tMedico *m);

void BinarioMedico(void *dado, FILE *arq);

void *BM(FILE *arq);

#endif