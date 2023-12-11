#ifndef _TSADE_H_
#define _TSADE_H_

typedef struct _tSade tSade;

#include "tMedico.h"
#include "tPaciente.h"
#include "tSecretario.h"

void InserePaciente(tSade *sade, tPaciente *p);

void InsereSecretario(tSade *sade, tSecretario *s);

void InsereMedico(tSade *sade, tMedico *m);

tSade *CriaSade();

int obtemnmedicos(tSade *sade);

int obtemnsecretarios(tSade *sade);

int obtemnpacientes(tSade *sade);

void PrintaMenuSecretarioUser();

void PrintaMenuMedico();

void PrintaMenuSecretarioAdmin();

int CPFInvalido(char *cpfpradentro, char* cpfdobanco);

tMedico *RetornaMedico(tSade* sade, int indice);

tSecretario *RetornaSecretario(tSade* sade, int indice);

tPaciente *RetornaPaciente(tSade *sade, int indice);

int EhMesmoLogin(char *login1, char *login2, char *senha1, char *senha2);

#endif