#include "tEncaminhamento.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct _tencaminhamento{
    char nomepaciente[151], cpf[21], especialidade[51], motivo[301], nomedomedico[151], crm[21], data[17]; 
};


tEncaminhamento *CriaEncaminhamento(tConsulta *c, char *cpf, char* nomemedico, char *crmmedico)
{
    tEncaminhamento *e = malloc(sizeof(tEncaminhamento));
    printf("#################### CONSULTA MEDICA #######################\nENCAMINHAMENTO:\n");
    strcpy(e->cpf, cpf);
    strcpy(e->nomepaciente, ConsultaNomePaciente(c));
    strcpy(e->nomedomedico, nomemedico);
    strcpy(e->crm, crmmedico);
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
    int dia, mes, ano;
    sscanf(r->data, "%d/%d/%d", &dia, &mes, &ano);
    printf("PACIENTE: %s\n", r->nomepaciente);
    printf("CPF: %s\n\n", r->cpf);
    printf("ESPECIALIDADE ENCAMINHADA: %s\n", r->especialidade);
    printf("MOTIVO: %s\n\n", r->motivo);
    printf("%s (%s)\n", r->nomedomedico, r->crm);
    printf("%d/%d/%d\n\n", dia, mes, ano);
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
    int i=0;
    //sscanf(b->data, "%d/%d/%d", &dia, &mes, &ano);
    fprintf(arq, "PACIENTE: %s\n", b->nomepaciente);
    fprintf(arq, "CPF: %s\n\n", b->cpf);
    fprintf(arq, "ESPECIALIDADE ENCAMINHADA: %s\n", b->especialidade);
    fprintf(arq, "MOTIVO: %s\n\n", b->motivo);
    fprintf(arq, "%s (%s)\n", b->nomedomedico, b->crm);
    /*if(dia<10)
    {
        fprintf(arq"%1d", dia);
    }
    else
    {
        fprintf("%d", dia);
    }
    fprintf(arq, "/%d/%d\n\n", mes, ano);
    */
    if(b->data[0]=='0')
    {
        i=1;
    }
    for(i ; i<strlen(b->data) ; i++)
    {
        fprintf(arq ,"%c", b->data[i]);
    }
    fprintf(arq, "\n\n");

    fclose(arq);
}


