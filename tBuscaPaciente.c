#include "tBuscaPaciente.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _tBusca{
    tPaciente **pacientes;
    int npacientes;
};

tBusca *criabusca(tSade *sade)
{
    tBusca *busca = malloc(1 * sizeof(tBusca));
    char nome[101];
    int i, n=1, a=0;
    tPaciente *p;
    printf("#################### BUSCAR PACIENTES #######################\n");
    printf("NOME DO PACIENTE: ");
    scanf("%[^\n]%*c", nome);
    for(i=0 ; i<obtemnpacientes(sade) ; i++)
    {
        p = RetornaPaciente(sade, i);
        if(strcmp(nome, RetornaNome(p))==0)
        {
            AdicionaPacienteNaBusca(busca, p);
            if(a==0)
            {
                a=1;
                printf("PACIENTES ENCONTRADOS:\n");
            }
            printf("%d - %s (%s)\n", n, RetornaNome(p), RetornaCPFpaciente(p));
            n++;
        }
    }
    printf("\n");
    return busca;
}

void AdicionaPacienteNaBusca(tBusca *busca, tPaciente *p)
{
    busca->npacientes++;
    busca->pacientes = realloc(busca->pacientes, busca->npacientes * sizeof(tPaciente*));
    busca->pacientes[busca->npacientes-1]=p;
}

void imprimeBuscaNaTela(void *dado)
{
    tBusca *busca = (tBusca*)dado;
    int i;
    for(i=0 ; i<BuscaNpacientes(busca) ; i++)
    {
        printf("%d - %s (%s)\n ", i+1, RetornaNome(busca->pacientes[i]), RetornaCPFpaciente(busca->pacientes[i]));
    }
    printf("\n");
}

int BuscaNpacientes(tBusca *busca)
{
    return busca->npacientes;
}

void desalocaBusca(void *dado)
{
    tBusca *busca = (tBusca*)dado;
    free(busca->pacientes);
    free(busca);
}

void imprimeEmArquivoBusca(void *dado, char *path)
{
    tBusca *busca = (tBusca*)dado;
    char nome[2000];
    sprintf(nome, "%s/%s", path, "lista_busca.txt");
    FILE *arq;
    arq = fopen(nome, "w");
    if(busca==NULL)
    {
        printf("Nao recebi uma busca\n");
        exit(1);
    }
    int i, a=1;
    for(i=0 ; i<BuscaNpacientes(busca) ; i++, a++)
    {
        fprintf(arq, "%d - %s (%s)\n", a, RetornaNome(busca->pacientes[i]), RetornaCPFpaciente(busca->pacientes[i]));
    }
    fprintf(arq, "\n");
    fclose(arq);
}
