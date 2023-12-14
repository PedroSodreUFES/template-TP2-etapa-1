#ifndef _TRELATORIO_H_
#define _TRELATORIO_H_

#include "tSade.h"
#include "tConsulta.h"

typedef struct _trelatorio tRelatorio;

tRelatorio *CriaRelatorio(tSade *sade);

void imprimeEmArquivoRelatorio(void *dado, char *path);

void imprimeNaTelaRelatorio(void *dado);

void desalocaRelatorio(void *dado);

#endif