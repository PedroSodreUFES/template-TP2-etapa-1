#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct _tPaciente tPaciente;

tPaciente *CriaPaciente();

void DesalocaPaciente(tPaciente *p);

char * RetornaNome(tPaciente *p);

char* RetornaCPFpaciente(tPaciente *p);

char *retornadatapaciente(tPaciente *p);

void JaFoiConsultado(tPaciente *p);

int obtemSeFoiConsultado(tPaciente *p);

int obtemIdadePaciente(tPaciente *p);

char *ObtemGeneroPaciente(tPaciente *p);

void BinarioPaciente(void *dado, FILE *arq);

void *BP(FILE *arq);

#endif