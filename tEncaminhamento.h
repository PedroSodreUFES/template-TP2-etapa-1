#ifndef _TENCAMINHAMENTO_H_
#define _TENCAMINHAMENTO_H_

#include "tConsulta.h"

typedef struct _tencaminhamento tEncaminhamento;

tEncaminhamento *CriaEncaminhamento(tConsulta *c, char *cpf);

void imprimeEmArquivoEncaminhamento(void *dado, char *path);

void imprimeNaTelaEncaminhamento(void *dado);

void desalocaEncaminhamento(void *dado);

#endif
