#ifndef _TSECRETARIO_H_
#define _TSECRETARIO_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct _tSecretario tSecretario;

tSecretario* CriaSecretario();

void PrintaSecretario(tSecretario *s);

void DesalocaSecretario(tSecretario *s);

char *retornaCPFsecretario(tSecretario *s);

char *retornaloginsecretario(tSecretario *s);

char *retornasenhasecretario(tSecretario *s);

int EhAdmin(tSecretario *s);

void BinarioSecretario(void *dado, FILE *arq);

void *SB(FILE *arq);

#endif