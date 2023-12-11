#ifndef _TMEDICO_H_
#define _TMEDICO_H_

typedef struct _tMedico tMedico;

tMedico *CriaMedico();

void PrintaMedico(tMedico *m);

void DesalocaMedico(tMedico *m);

char *retornaCPFmedico(tMedico *m);

char *retornaloginmedico(tMedico *m);

char *retornasenhamedico(tMedico *m);

#endif