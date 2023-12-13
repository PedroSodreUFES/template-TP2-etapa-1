#include "tBiopsia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tbiopsia{
    char nomepaciente[151], nomemedico[51], cpf[50], crmmedico[21], data[30];
    tLesao **lesoes;
    int nlesoes;
};


tBiopsia *CriaBiopsia(tConsulta *consulta, char *cpf)
{
    tBiopsia *b = malloc(sizeof(tBiopsia));
    b->lesoes=NULL;
    b->nlesoes=0;
    b->nomemedico[0]='\0';
    strcpy(b->nomepaciente, ConsultaNomePaciente(consulta));
    strcpy(b->cpf, ConsultaCPF(consulta));
    strcpy(b->data, ConsultaData(consulta));
    int i;
    for(i=0 ; i<retornanlesoesconsulta(consulta) ; i++)
    {
        if(retornalesaocirurgia(PegaLesaoComIndice(consulta, i)))
        {
            InsereLesaoBiopsia(b , PegaLesaoComIndice(consulta, i));
        }
    }
    b->crmmedico[0]='\0';
}

void InsereLesaoBiopsia(tBiopsia *biopsia, tLesao *lesao)
{
    biopsia->nlesoes++;
    biopsia->lesoes = realloc(biopsia->lesoes, NumeroDeLesoesBiopsia(biopsia)*sizeof(tLesao*));
    biopsia->lesoes[NumeroDeLesoesBiopsia(biopsia)-1]=lesao;
}


int NumeroDeLesoesBiopsia(tBiopsia *biopsia)
{
    return biopsia->nlesoes;
}

void desalocaBiopsia(void *dado)
{
    tBiopsia *b = (tBiopsia*)dado;
    if(b->lesoes!=NULL)
    {
        free(b->lesoes);
    }
    if(b!=NULL)
    {
        free(b);
    }
}

void imprimeNaTelaBiopsia(void *dado)
{
    tBiopsia *b = (tBiopsia*)dado;
    if(b==NULL)
    {
        printf("Nao recebi uma biopsia\n");
        exit(1);
    }
    printf("PACIENTE: %s\n", b->nomepaciente);
    printf("CPF: %s\n\n", b->cpf);
    printf("SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    int i;
    for(i=0 ; i<NumeroDeLesoesBiopsia(b) ; i++)
    {
        printf("L%d - %s - %s - %dMM\n", i+1 , retornadiagnosticolesao(b->lesoes[i]) , retornaregiaolesao(b->lesoes[i]) , tamanhodalesao(b->lesoes[i]));
    }
    printf("\n");
    printf(" ()\n" /*b->nomemedico, b->crmmedico*/);
    printf("%s\n\n", b->data);
}

void imprimeEmArquivoBiopsia(void *dado, char *path)
{
    char nome[2000];
    sprintf(nome, "%s/%s", path, "biopsia.txt");
    FILE *arq = fopen(nome, "a");
    tBiopsia *b = (tBiopsia*)dado;
    if(b==NULL)
    {
        printf("Nao recebi uma biopsia\n");
        exit(1);
    }
    fprintf(arq, "PACIENTE: %s\n", b->nomepaciente);
    fprintf(arq, "CPF: %s\n\n", b->cpf);
    fprintf(arq, "SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    int i;
    for(i=0 ; i<NumeroDeLesoesBiopsia(b) ; i++)
    {
        fprintf(arq, "L%d - %s - %s - %dMM\n", i+1 , retornadiagnosticolesao(b->lesoes[i]) , retornaregiaolesao(b->lesoes[i]) , tamanhodalesao(b->lesoes[i]));
    }
    fprintf(arq, "\n");
    fprintf(arq, " ()\n"/*, b->nomemedico, b->crmmedico*/);
    fprintf(arq, "%s\n\n", b->data);
    fclose(arq);
}
