#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

typedef struct _tPaciente tPaciente;

tPaciente *CriaPaciente();

void DesalocaPaciente(tPaciente *p);

char * RetornaNome(tPaciente *p);

char* RetornaCPFpaciente(tPaciente *p);

int retornaNlesoes(tPaciente *p);

#endif