#ifndef _TLESAO_H_
#define _TLESAO_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct _tlesao tLesao;

tLesao *CadastraLesao();

int NaoPrecisaCrioterapia(tLesao *lesao);

char *retornaregiaolesao(tLesao *lesao);

char *retornarotulolesao(tLesao *lesao);

char *retornadiagnosticolesao(tLesao *lesao);

int tamanhodalesao(tLesao *lesao);

int retornalesaocirurgia(tLesao *lesao);

int retornalesaocrioterapia(tLesao *lesao);

tLesao *ClonaLesao(tLesao *lesao);

void DesalocaLesao(tLesao *lesao);

void BinarioLesoes(void *dado, FILE *arq);

void *BL(FILE* arq);

#endif