#include "tReceita.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tReceita{
    eTipoUso tipo;
    int quantidade;
    char nomedopaciente[150], nomedomedicamento[51], tipodemedicamento[51], instrucaodeuso[301], nomedomedico[150], CRM[21], data[16];
};

tReceita *criaReceita(char *nomePaciente, eTipoUso tipoUso, char *nomeMedicamento, char *tipoMedicamento, char *instrucoes, int qntd, char *nomeMedico, char *CRM, char *dataStr){
    tReceita *receita = (tReceita*)malloc(sizeof(tReceita));
    strcpy(receita->nomedopaciente, nomePaciente);
    receita->tipo=tipoUso;
    strcpy(receita->nomedomedicamento, nomeMedicamento);
    strcpy(receita->instrucaodeuso, instrucoes);
    strcpy(receita->CRM, CRM);
    strcpy(receita->nomedomedico, nomeMedico);
    receita->quantidade=qntd;
    strcpy(receita->data, dataStr);
    strcpy(receita->tipodemedicamento, tipoMedicamento);
    return receita;
}

void desalocaReceita(void *dado)
{
    tReceita *r = (tReceita*)dado;
    if(r!=NULL)
    {
        free(r);
    }
}

void imprimeNaTelaReceita(void *dado)
{
    tReceita *r = (tReceita*)dado;
    if(r==NULL)
    {
        printf("Nao recebi uma receita\n");
        exit(1);
    }
    printf("RECEITUARIO\n");
    printf("NOME: %s\n\n", r->nomedopaciente);
    if(r->tipo==ORAL)
    {
        printf("USO ORAL\n\n");
    }
    else if(r->tipo==TOPICO)
    {
        printf("USO TOPICO\n\n");
    }
    printf("%s\n", r->nomedomedicamento);
    printf("%d %s\n\n", r->quantidade, r->tipodemedicamento);
    printf("%s\n\n", r->instrucaodeuso);
    printf("%s (%s)\n", r->nomedomedico, r->CRM);
    printf("%s\n\n", r->data);
}

void imprimeEmArquivoReceita(void *dado, char *path)
{
    char nome[2000];
    sprintf(nome, "%s/%s", path, NOME_ARQUIVO_RECEITA);
    FILE *arq = fopen(nome, "a");
    tReceita *r = (tReceita*)dado;
    if(r==NULL)
    {
        printf("Nao recebi uma receita\n");
        exit(1);
    }
    int dia, mes, ano;
    sscanf(r->data, "%d/%d/%d", &dia, &mes, &ano);
    fprintf(arq, "RECEITUARIO\n");
    fprintf(arq, "NOME: %s\n\n", r->nomedopaciente);
    if(r->tipo==ORAL)
    {
        fprintf(arq, "USO ORAL\n\n");
    }
    else if(r->tipo==TOPICO)
    {
        fprintf(arq, "USO TOPICO\n\n");
    }
    fprintf(arq, "%s\n", r->nomedomedicamento);
    fprintf(arq, "%d %s\n\n", r->quantidade, r->tipodemedicamento);
    fprintf(arq, "%s\n\n", r->instrucaodeuso);
    fprintf(arq, "%s (%s)\n", r->nomedomedico, r->CRM);
    fprintf(arq, "%d/%d/%d\n\n", dia , mes, ano);
    fclose(arq);
}