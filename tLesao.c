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
    tLesao *lesao = malloc(sizeof(tLesao));
    char botao;
    printf("#################### CONSULTA MEDICA #######################\nCADASTRO DE LESAO:\n");
    printf("DIAGNOSTICO CLINICO: ");
    scanf("%s%*c", lesao->diagnostico);
    printf("REGIAO DO CORPO: ");
    scanf("%s%*c", lesao->regiao);
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
    tLesao *clone = malloc(sizeof(tLesao));
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




