#include "tMedico.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _tMedico{
    char nome[101], cpf[20], nascimento[20], telefone[20], genero[20], usuario[21], senha[21], CRM[20];
};

tMedico *CriaMedico()
{
    tMedico *m = malloc(sizeof(tMedico));
    if(m==NULL)
    {
        printf("MEDICO NAO ALOCADO\n");
        exit(1);
    }
    printf("#################### CADASTRO MEDICO #######################\n");
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", m->nome);
    m->nome[strlen(m->nome)]= '\0';
    printf("CPF: ");
    scanf("%s", m->cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%s", m->nascimento);
    printf("TELEFONE: ");
    scanf("%s", m->telefone);
    printf("GENERO: ");
    scanf("%s", m->genero);
    printf("CRM: ");
    scanf("%s", m->CRM);
    printf("NOME DE USUARIO: ");
    scanf("%s", m->usuario);
    printf("SENHA: ");
    scanf("%s", m->senha);
    scanf("%*c");
    printf("\n");
    return m;
}

void PrintaMedico(tMedico *m)
{
    if(m==NULL)
    {
        printf("MEDICO NAO ALOCADO\n");
        exit(1);
    }
    printf("#################### CADASTRO SECRETARIO #######################\n");
    printf("NOME COMPLETO: ");
    printf("%s\n", m->nome);
    printf("CPF: ");
    printf("%s\n", m->cpf);
    printf("DATA DE NASCIMENTO: ");
    printf("%s\n", m->nascimento);
    printf("TELEFONE: ");
    printf("%s\n", m->telefone);
    printf("GENERO: ");
    printf("%s\n", m->genero);
    printf("NOME DE USUARIO: ");
    printf("%s\n", m->usuario);
    printf("SENHA: ");
    printf("%s\n", m->senha);
    printf("CRM: ");
    printf("%s", m->CRM);
    printf("\n");
    printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL");
    printf("###############################################################\n");
}

void DesalocaMedico(tMedico *m)
{
    if(m!=NULL)
    {
        free(m);
    }
}

char *retornaCPFmedico(tMedico *m)
{
    return m->cpf;
}

char *retornaloginmedico(tMedico *m)
{
    return m->usuario;
}

char *retornasenhamedico(tMedico *m)
{
    return m->senha;
}

char *retornanomemedico(tMedico *m)
{
    return m->nome;
}

char *retornacrmmedico(tMedico *m)
{
    return m->CRM;
}