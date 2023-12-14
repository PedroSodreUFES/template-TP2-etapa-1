#include "tSecretario.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _tSecretario{
    char nome[101], cpf[20], nascimento[20], telefone[20], genero[20], usuario[21], senha[21], tipo[12];
};

tSecretario* CriaSecretario()
{
    tSecretario *s = calloc(1, sizeof(tSecretario));
    if(s==NULL)
    {
        printf("SECRETARIO NAO ALOCADO\n");
        exit(1);
    }
    printf("#################### CADASTRO SECRETARIO #######################\n");
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", s->nome);
    s->nome[strlen(s->nome)]= '\0';
    printf("CPF: ");
    scanf("%s", s->cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%s", s->nascimento);
    printf("TELEFONE: ");
    scanf("%s", s->telefone);
    printf("GENERO: ");
    scanf("%s", s->genero);
    printf("NOME DE USUARIO: ");
    scanf("%s", s->usuario);
    printf("SENHA: ");
    scanf("%s", s->senha);
    printf("NIVEL DE ACESSO: ");
    scanf("%s", s->tipo);
    scanf("%*c");
    return s;
}

void PrintaSecretario(tSecretario *s)
{
    if(s==NULL)
    {
        printf("SECRETARIO NAO ALOCADO\n");
        exit(1);
    }
    printf("#################### CADASTRO SECRETARIO #######################\n");
    printf("NOME COMPLETO: ");
    printf("%s\n", s->nome);
    printf("CPF: ");
    printf("%s\n", s->cpf);
    printf("DATA DE NASCIMENTO: ");
    printf("%s\n", s->nascimento);
    printf("TELEFONE: ");
    printf("%s\n", s->telefone);
    printf("GENERO: ");
    printf("%s\n", s->genero);
    printf("NOME DE USUARIO: ");
    printf("%s\n", s->usuario);
    printf("SENHA: ");
    printf("%s\n", s->senha);
    printf("NIVEL DE ACESSO: ");
    printf("%s", s->tipo);
    printf("\n");
    printf("###############################################################\n");
}

void DesalocaSecretario(tSecretario *s)
{
    if(s!=NULL)
    {
        free(s);
    }
}

char *retornaCPFsecretario(tSecretario *s)
{
    return s->cpf;
}

char *retornaloginsecretario(tSecretario *s)
{
    return s->usuario;
}

char *retornasenhasecretario(tSecretario *s)
{
    return s->senha;
}

int EhAdmin(tSecretario *s)
{
    if(strcmp(s->tipo, "ADMIN")==0)
    {
        return 1;
    }
    return 0;
}

void BinarioSecretario(void *dado, FILE *arq)
{
    tSecretario *s = (tSecretario*)dado;
    fwrite(s, sizeof(tSecretario), 1 , arq);
}

void *SB(FILE *arq)
{
    tSecretario *s = malloc(sizeof(tSecretario));
    fread(s, sizeof(tSecretario), 1, arq);
    return (void*)s;
}