#include "tRelatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _trelatorio{
    int idademedia, pacientesatendidos, feminino, masculino, outros, tamanhomediolesoes, numerodelesoes, numerocirurgias, numerocrioterapia;
};

tRelatorio *CriaRelatorio(tSade *sade)
{
    tRelatorio *relatorio = malloc(sizeof(tRelatorio));
    int i;
    int nconsultados=0;
    for(i=0 ; i<obtemnpacientes(sade) ; i++)
    {
        if(obtemSeFoiConsultado(RetornaPaciente(sade, i)))
        {
            nconsultados++;
        }
    }
    relatorio->pacientesatendidos=nconsultados;

    
    
    //FAZER IDADE MÉDIA
    int idades=0;
    for(i=0 ; i<obtemnpacientes(sade) ; i++)
    {
        idades += CalculaIdadePessoa(RetornaPaciente(sade, i), "09/11/2023");
    }
    relatorio->idademedia = idades / obtemnpacientes(sade);

    

    //DISTRIBUICAO GENERO
    int m=0, f=0, o=0;
    for(i=0 ; i<obtemnpacientes(sade) ; i++)
    {
        if(strcmp(ObtemGeneroPaciente(RetornaPaciente(sade, i)), "MASCULINO")==0)
        {
            m++;
        }
        else if(strcmp(ObtemGeneroPaciente(RetornaPaciente(sade, i)), "FEMININO")==0)
        {
            f++;
        }
        else
        {
            o++;
        }
    }
    relatorio->feminino=f;
    relatorio->masculino=m;
    relatorio->outros=o;

    //TAMANHO LESOES, CIRURGIAS E CRIOTERAPIAS
    int tamanholesao=0, CIRURGIAS=0, CRIOTERAPIAS=0;;
    for(i=0 ; i<obtemnlesoes(sade) ; i++)
    {
        tamanholesao += tamanhodalesao(RetornaLesao(sade, i)); 
        if(retornalesaocirurgia(RetornaLesao(sade, i)))
        {
            CIRURGIAS++;
        }
        if(retornalesaocrioterapia(RetornaLesao(sade, i)))
        {
            CRIOTERAPIAS++;
        }       
    }
    relatorio->tamanhomediolesoes = tamanholesao / obtemnlesoes(sade);
    relatorio->numerodelesoes = obtemnlesoes(sade);
    relatorio->numerocrioterapia = CRIOTERAPIAS;
    relatorio->numerocirurgias = CIRURGIAS;
    return relatorio;
}

void imprimeEmArquivoRelatorio(void *dado, char *path)
{
    tRelatorio *r = (tRelatorio*)dado;
    if(r==NULL)
    {
        printf("Nao recebi um relatorio\n");
        exit(1);
    }
    char nome[2000];
    sprintf(nome, "%s/%s", path, "relatorio_geral.txt");
    FILE *arq = fopen(nome, "a");
    fprintf(arq ,"NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", r->pacientesatendidos);
    fprintf(arq, "IDADE MEDIA: %d\n", r->idademedia);
    fprintf(arq, "DISTRIBUICAO POR GENERO:\n");
    fprintf(arq, "- FEMININO: %d\n", r->feminino);
    fprintf(arq, "- MASCULINO: %d\n", r->masculino);
    fprintf(arq, "- OUTROS: %d\n", r->outros);
    fprintf(arq, "TAMANHO MEDIO DAS LESOES: %d\n", r->tamanhomediolesoes);
    fprintf(arq, "NUMERO TOTAL DE LESOES: %d\n", r->numerodelesoes);
    fprintf(arq, "NUMERO TOTAL DE CIRURGIAS: %d\n", r->numerocirurgias);
    fprintf(arq, "NUMERO TOTAL DE CRIOTERAPIA: %d\n\n", r->numerocrioterapia);
    fclose(arq);
}

void imprimeNaTelaRelatorio(void *dado)
{
    tRelatorio *r = (tRelatorio*)dado;
    if(r==NULL)
    {
        printf("Nao recebi um relatorio\n");
        exit(1);
    }
    printf( "NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", r->pacientesatendidos);
    printf( "IDADE MEDIA: %d\n", r->idademedia);
    printf( "DISTRIBUICAO POR GENERO:\n");
    printf( "- FEMININO: %d\n", r->feminino);
    printf( "- MASCULINO: %d\n", r->masculino);
    printf( "- OUTROS: %d\n", r->outros);
    printf( "TAMANHO MEDIO DAS LESOES: %d\n", r->tamanhomediolesoes);
    printf( "NUMERO TOTAL DE LESOES: %d\n", r->numerodelesoes);
    printf( "NUMERO TOTAL DE CIRURGIAS: %d\n", r->numerocirurgias);
    printf( "NUMERO TOTAL DE CRIOTERAPIA: %d\n\n", r->numerocrioterapia);
}

void desalocaRelatorio(void *dado)
{
    tRelatorio *r = (tRelatorio*)dado;
    if(r!=NULL)
    {
        free(r);
    }
}
