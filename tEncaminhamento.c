#include "tEncaminhamento.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct _tencaminhamento{
    char nomepaciente[151], cpf[21], especialidade[51], motivo[301], nomedomedico[151], crm[21], data[17]; 
};


tEncaminhamento *CriaEncaminhamento(tConsulta *c, char *cpf)
{
    tEncaminhamento *e = malloc(sizeof(tEncaminhamento));
    printf("#################### CONSULTA MEDICA #######################\nENCAMINHAMENTO:\n");
    strcpy(e->cpf, cpf);
    strcpy(e->nomepaciente, ConsultaNomePaciente(c));
    e->nomedomedico[0]='\0';
    e->crm[0]='\0';
    strcpy(e->data, ConsultaData(c));
    printf("ESPECIALIDADE ENCAMINHADA: ");
    scanf("%s%*c", e->especialidade);
    printf("MOTIVO: ");
    scanf("%[^\n]%*c", e->motivo);
    e->motivo[strlen(e->motivo)]='\0';
    printf("\n");
    return e;
}

void desalocaEncaminhamento(void *dado)
{
    tEncaminhamento *r = (tEncaminhamento*)dado;
    if(r!=NULL)
    {
        free(r);
    }
}

void imprimeNaTelaEncaminhamento(void *dado)
{
    tEncaminhamento *r = (tEncaminhamento*)dado;
    if(r==NULL)
    {
        printf("Nao recebi um encaminhamento\n");
        exit(1);
    }
    printf("PACIENTE: %s\n", r->nomepaciente);
    printf("CPF: %s\n\n", r->cpf);
    printf("ESPECIALIDADE ENCAMINHADA: %s\n", r->especialidade);
    printf("MOTIVO: %s\n\n", r->motivo);
    printf("%s (%s)\n", r->nomedomedico, r->crm);
    printf("%s\n\n", r->data);
}

void imprimeEmArquivoEncaminhamento(void *dado, char *path)
{
    char nome[2000];
    sprintf(nome, "%s/%s", path, "encaminhamento.txt");
    FILE *arq = fopen(nome, "a");
    tEncaminhamento *b = (tEncaminhamento*)dado;
    if(b==NULL)
    {
        printf("Nao recebi uma biopsia\n");
        exit(1);
    }
    fprintf(arq, "PACIENTE: %s\n", b->nomepaciente);
    fprintf(arq, "CPF: %s\n\n", b->cpf);
    fprintf(arq, "ESPECIALIDADE ENCAMINHADA: %s\n", b->especialidade);
    fprintf(arq, "MOTIVO: %s\n\n", b->motivo);
    fprintf(arq, "%s (%s)\n", b->nomedomedico, b->crm);
    fprintf(arq, "%s\n\n", b->data);
    fclose(arq);
}


