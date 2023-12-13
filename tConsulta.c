#include "tConsulta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tConsulta{
    char nomedopaciente[101], cpfdopaciente[21], data[21], nomedomedico[101], pele[5];
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
    tConsulta *consulta = malloc(sizeof(tConsulta));
    consulta->lesoes=NULL;
    consulta->nlesoes=0;
    strcpy(consulta->nomedopaciente, RetornaNome(p));
    consulta->nomedomedico[0]='\0';
    printf("---\n");
    printf("-NOME: %s\n", consulta->nomedopaciente);
    printf("-DATA DE NASCIMENTO: %s\n", retornadatapaciente(p));
    printf("---\n");
    printf("DATA DA CONSULTA: ");
    scanf("%s", consulta->data);
    printf("POSSUI DIABETES: ");
    scanf("%d", &consulta->diabetes);
    printf("FUMANTE: ");
    scanf("%d", &consulta->fumante);
    printf("ALERGIA A MEDICAMENTO: ");
    scanf("%d", &consulta->alergia);
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
    consulta->nlesoes++;
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