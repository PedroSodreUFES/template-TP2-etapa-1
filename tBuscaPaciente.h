#ifndef _TBUSCAPACIENTE_H
#define _TBUSCAPACIENTE_H

#include "tSade.h"
#include "tFila.h"

typedef struct _tBusca tBusca;

tBusca *criabusca(tSade *sade);

void AdicionaPacienteNaBusca(tBusca *busca, tPaciente *p);

void imprimeBuscaNaTela(void *dado);

int BuscaNpacientes(tBusca *busca);

void desalocaBusca(void *dado);

void imprimeEmArquivoBusca(void *dado, char *path);

#endif