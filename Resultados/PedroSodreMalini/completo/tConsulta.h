#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

#include "tPaciente.h"
#include "tMedico.h"
#include "tLesao.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _tConsulta tConsulta;

void PrintaMenuConsulta();

tConsulta *CriaConsulta(tPaciente *p);

char *ConsultaNomePaciente(tConsulta *c);

char *ConsultaNomeMedico(tConsulta *c);

char *ConsultaData(tConsulta *c);

int retornanlesoesconsulta(tConsulta *c);

void InsereLesoesNaConsulta(tConsulta *consulta, tLesao *lesao);

tLesao *PegaLesaoComIndice(tConsulta *consulta, int i);

int NaoPrecisaCirurgia(tConsulta *c);

char *ConsultaCPF(tConsulta *c);

void DesalocaConsulta(tConsulta *c);

void BinarioConsultas(void *dado, FILE *arq);

void *BC(FILE *arq);

#endif