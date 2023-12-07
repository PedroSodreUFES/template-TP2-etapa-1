#ifndef _TSECRETARIO_H_
#define _TSECRETARIO_H_

typedef struct _tSecretario tSecretario;

tSecretario* CriaSecretario();

void PrintaSecretario(tSecretario *s);

void DesalocaSecretario(tSecretario *s);

#endif