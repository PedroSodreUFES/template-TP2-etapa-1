#ifndef _TSADE_H_
#define _TSADE_H_

typedef struct _tSade tSade;

#include "tMedico.h"
#include "tPaciente.h"
#include "tSecretario.h"
#include "tConsulta.h"

int obtemnlesoes(tSade *sade);

void InsereLesoes(tSade *sade, tLesao *lesao);

void InserePaciente(tSade *sade, tPaciente *p);

void InsereSecretario(tSade *sade, tSecretario *s);

void InsereMedico(tSade *sade, tMedico *m);

void InsereConsulta(tSade *sade, tConsulta *consulta);

tSade *CriaSade();

tPaciente *RetornaPacienteCadastrado(tSade *sade, char *cpf);

int obtemnmedicos(tSade *sade);

int obtemnsecretarios(tSade *sade);

int obtemnpacientes(tSade *sade);

int obtemnconsultas(tSade *sade);

int VeSePacienteTaRegistrado(tSade *sade, char *cpf);

void PrintaMenuSecretarioUser();

void PrintaMenuMedico();

void PrintaMenuSecretarioAdmin();

int CPFInvalido(char *cpfpradentro, char* cpfdobanco);

tMedico *RetornaMedico(tSade* sade, int indice);

tSecretario *RetornaSecretario(tSade* sade, int indice);

tPaciente *RetornaPaciente(tSade *sade, int indice);

tLesao *RetornaLesao(tSade *sade, int indice);

int EhMesmoLogin(char *login1, char *login2, char *senha1, char *senha2);

int CalculaIdadePessoa(tPaciente *p, char *dataatual);

#endif