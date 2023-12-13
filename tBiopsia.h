#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

#include "tLesao.h"
#include "tConsulta.h"

typedef struct _tbiopsia tBiopsia;

tBiopsia *CriaBiopsia(tConsulta *consulta, char *cpf);

void InsereLesaoBiopsia(tBiopsia *biopsia, tLesao *lesao);

void imprimeEmArquivoBiopsia(void *dado, char *path);

void imprimeNaTelaBiopsia(void *dado);

void desalocaBiopsia(void *biopsia);

int NumeroDeLesoesBiopsia(tBiopsia *biopsia);


#endif