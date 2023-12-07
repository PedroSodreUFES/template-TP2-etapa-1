#include "tPaciente.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _tPaciente{
    char nome[101], cpf[20], nascimento[20], telefone[20], genero[20];
};

tPaciente *CriaPaciente()
{
    tPaciente *p = malloc(sizeof(tPaciente));
    if(p==NULL)
    {
        printf("PACIENTE NAO ALOCADO\n");
        exit(1);
    }
    printf("#################### CADASTRO PACIENTE #######################\n");
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", p->nome);
    p->nome[strlen(p->nome)]= '\0';
    printf("CPF: ");
    scanf("%s", p->cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%s", p->nascimento);
    printf("TELEFONE: ");
    scanf("%s", p->telefone);
    printf("GENERO: ");
    scanf("%s", p->genero);
    scanf("%*c");
    printf("\n");
    printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\nVOLTAR PARA O MENU INICIAL\n");
    printf("###############################################################\n");
    return p;
}

void DesalocaPaciente(tPaciente *p)
{
    if(p!=NULL)
    {
        free(p);
    }
}