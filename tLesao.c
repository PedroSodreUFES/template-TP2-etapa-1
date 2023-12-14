#include "tLesao.h"
#include "tDocumento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tlesao{
    char regiao[30], diagnostico[30], rotulo[7];
    int tamanho, cirurgia, crioterapia; 
};

tLesao *CadastraLesao()
{
    tLesao *lesao = calloc(1, sizeof(tLesao));
    char botao;
    printf("#################### CONSULTA MEDICA #######################\nCADASTRO DE LESAO:\n");
    printf("DIAGNOSTICO CLINICO: ");
    scanf("%[^\n]%*c", lesao->diagnostico);
    lesao->diagnostico[strlen(lesao->diagnostico)]='\0';
    printf("REGIAO DO CORPO: ");
    scanf("%[^\n]%*c", lesao->regiao);
    lesao->regiao[strlen(lesao->regiao)]='\0';
    printf("TAMANHO: ");
    scanf("%d%*c", &lesao->tamanho);
    printf("ENVIAR PARA A CIRURGIA: ");
    scanf("%d%*c", &lesao->cirurgia);
    printf("ENVIAR PARA A CRIOTERAPIA: ");
    scanf("%d%*c", &lesao->crioterapia);
    printf("\nLESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n############################################################\n");
    scanf("%c%*c", &botao);   
    return lesao;
}

tLesao *ClonaLesao(tLesao *lesao)
{
    tLesao *clone = calloc(1, sizeof(tLesao));
    strcpy(clone->regiao, lesao->regiao);
    strcpy(clone->diagnostico, lesao->diagnostico);
    clone->tamanho = lesao->tamanho;
    clone->cirurgia = lesao->cirurgia;
    clone->crioterapia = lesao->crioterapia;
    return clone;
}

int NaoPrecisaCrioterapia(tLesao *lesao)
{
    if(lesao->crioterapia==0)
    {
        return 1;
    }
    return 0;
}

int retornalesaocirurgia(tLesao *lesao)
{
    return lesao->cirurgia;
}

int retornalesaocrioterapia(tLesao *lesao)
{
    return lesao->crioterapia;
}

char *retornaregiaolesao(tLesao *lesao)
{
    return lesao->regiao;
}

char *retornarotulolesao(tLesao *lesao)
{
    return lesao->rotulo;
}

char *retornadiagnosticolesao(tLesao *lesao)
{
    return lesao->diagnostico;
}

int tamanhodalesao(tLesao *lesao)
{
    return lesao->tamanho;
}

void DesalocaLesao(tLesao *lesao)
{
    if(lesao!=NULL)
    {
        free(lesao);
    }
}

void BinarioLesoes(void *dado, FILE *arq)
{
    tLesao *l = (tLesao*)dado;
    fwrite(l, sizeof(tLesao), 1, arq);
}

void *BL(FILE* arq)
{
    tLesao *l = calloc(1, sizeof(tLesao));
    fread(l, sizeof(tLesao), 1, arq);
    return (void*)l;
}

