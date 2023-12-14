#include "tConsulta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tConsulta{
    char nomedopaciente[101], cpfdopaciente[21], data[21], nomedomedico[101], pele[5], crmMEDICO[30];
    int diabetes, fumante, alergia, cancer;
    void **lesoes;
    int nlesoes;
};

void PrintaMenuConsulta()
{
    printf("#################### CONSULTA MEDICA #######################\nESCOLHA UMA OPCAO:\n	(1) CADASTRAR LESAO\n	(2) GERAR RECEITA MEDICA\n	(3) SOLICITACAO DE BIOPSIA\n	(4) ENCAMINHAMENTO\n	(5) ENCERRAR CONSULTA\n############################################################\n");
}



tConsulta *CriaConsulta(tPaciente *p)
{
    tConsulta *consulta = calloc(1, sizeof(tConsulta));
    consulta->lesoes=NULL;
    consulta->nlesoes=0;
    strcpy(consulta->nomedopaciente, RetornaNome(p));
    strcpy(consulta->cpfdopaciente, RetornaCPFpaciente(p));
    printf("---\n");
    printf("-NOME: %s\n", consulta->nomedopaciente);
    printf("-DATA DE NASCIMENTO: %s\n", retornadatapaciente(p));
    printf("---\n");
    printf("DATA DA CONSULTA: ");
    scanf("%s%*c", consulta->data);
    printf("POSSUI DIABETES: ");
    scanf("%d%*c", &consulta->diabetes);
    printf("FUMANTE: ");
    scanf("%d%*c", &consulta->fumante);
    printf("ALERGIA A MEDICAMENTO: ");
    scanf("%d%*c", &consulta->alergia);
    printf("HISTORICO DE CANCER: ");
    scanf("%d%*c", &consulta->cancer);
    printf("TIPO DE PELE: ");
    scanf("%s%*c", consulta->pele);
    printf("\n");
    return consulta;
}

char *ConsultaNomePaciente(tConsulta *c)
{
    return c->nomedopaciente;
}

char *ConsultaNomeMedico(tConsulta *c)
{
    return c->nomedomedico;
}

char *ConsultaData(tConsulta *c)
{
    return c->data;
}

int retornanlesoesconsulta(tConsulta *c)
{
    return c->nlesoes;
}

void InsereLesoesNaConsulta(tConsulta *consulta, tLesao *lesao)
{
    consulta->nlesoes+=1;
    consulta->lesoes = realloc(consulta->lesoes, retornanlesoesconsulta(consulta)*sizeof(void*));
    consulta->lesoes[retornanlesoesconsulta(consulta)-1]=(void*)lesao;
}

tLesao *PegaLesaoComIndice(tConsulta *consulta, int i)
{
    return (tLesao*)consulta->lesoes[i];
}


int NaoPrecisaCirurgia(tConsulta *c)
{
    int i;
    for(i=0 ; i<retornanlesoesconsulta(c) ; i++)
    {
        if(retornalesaocirurgia(PegaLesaoComIndice(c, i))==1)
        {
            return 0;
        }
    }
    return 1;
}


char *ConsultaCPF(tConsulta *c)
{
    return c->cpfdopaciente;
}

void DesalocaConsulta(tConsulta *c)
{
    int i;
    for(i=0 ; i<retornanlesoesconsulta(c) ; i++)
    {
        DesalocaLesao(PegaLesaoComIndice(c, i));
    }
    if(c->lesoes!=NULL)
    {
        free(c->lesoes);
    }
    if(c!=NULL)
    {
        free(c);
    }
}

void BinarioConsultas(void *dado, FILE *arq)
{
    tConsulta *c = (tConsulta*)dado;
    fwrite(c, sizeof(tConsulta), 1, arq);
    int i;
    for(i=0 ; i<retornanlesoesconsulta(c) ; i++)
    {
        BinarioLesoes(c->lesoes[i], arq);
    }
}

void *BC(FILE *arq)
{
    tConsulta *c = calloc(1, sizeof(tConsulta));
    fread(c, sizeof(tConsulta), 1, arq);
    c->lesoes = calloc(retornanlesoesconsulta(c), sizeof(void*));
    int i;
    for(i=0 ; i<retornanlesoesconsulta(c) ; i++)
    {
        c->lesoes[i] = BL(arq);
    }
    return (void*)c;
}