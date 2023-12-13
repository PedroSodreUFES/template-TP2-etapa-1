#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

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


#endif