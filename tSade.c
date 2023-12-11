#include "tSade.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _tSade
{
    void **secretarios, **medicos, **pacientes;
    int nsecretarios, nmedicos, npacientes;
};

tSade *CriaSade()
{
    tSade *sade = malloc(sizeof(tSade));
    sade->nmedicos=0;
    sade->npacientes=0;
    sade->nsecretarios=0;
    sade->medicos=NULL;
    sade->pacientes=NULL;
    sade->secretarios=NULL;
    return sade;
}

int obtemnmedicos(tSade *sade)
{
    return sade->nmedicos;
}

int obtemnsecretarios(tSade *sade)
{
    return sade->nsecretarios;
}

int obtemnpacientes(tSade *sade)
{
    return sade->npacientes;
}

void InsereMedico(tSade *sade, tMedico *m)
{
    sade->nmedicos++;
    sade->medicos = realloc(sade->medicos, obtemnmedicos(sade) * sizeof(void*));
    sade->medicos[obtemnmedicos(sade)-1]=(void*)m;
}

void InsereSecretario(tSade *sade, tSecretario *s)
{
    sade->nsecretarios++;
    sade->secretarios = realloc(sade->secretarios, obtemnsecretarios(sade)*sizeof(void*));
    sade->secretarios[obtemnsecretarios(sade)-1]= (void*)s;
}

void InserePaciente(tSade *sade, tPaciente *p)
{
    sade->npacientes++;
    sade->pacientes = realloc(sade->pacientes ,obtemnpacientes(sade)*sizeof(void*));
    sade->pacientes[obtemnpacientes(sade)-1]= (void*)p;
}

void PrintaMenuSecretarioUser()
{
    printf("####################### MENU PRINCIPAL #########################\nESCOLHA UMA OPCAO:\n      (2) CADASTRAR MEDICO\n      (3) CADASTRAR PACIENTE\n      (5) BUSCAR PACIENTES\n      (6) RELATORIO GERAL\n      (7) FILA DE IMPRESSAO\n      (8) FINALIZAR O PROGRAMA\n###############################################################\n");
}

void PrintaMenuMedico()
{
    printf("####################### MENU PRINCIPAL #########################\nESCOLHA UMA OPCAO:\n      (4) REALIZAR CONSULTA\n      (5) BUSCAR PACIENTES\n      (6) RELATORIO GERAL\n      (7) FILA DE IMPRESSAO\n      (8) FINALIZAR O PROGRAMA\n###############################################################\n");
}

void PrintaMenuSecretarioAdmin()
{
        printf("####################### MENU PRINCIPAL #########################\nESCOLHA UMA OPCAO:\n      (1) CADASTRAR SECRETARIO\n      (2) CADASTRAR MEDICO\n      (3) CADASTRAR PACIENTE\n      (4) REALIZAR CONSULTA\n      (5) BUSCAR PACIENTES\n      (6) RELATORIO GERAL\n      (7) FILA DE IMPRESSAO\n      (8) FINALIZAR O PROGRAMA\n###############################################################\n");
}

void BuscaPaciente(tSade *sade)
{
    char nome[101];
    scanf("%[^\n]%*c", nome);
    int i, n=1, a=0;
    tPaciente *p;
    printf("#################### BUSCAR PACIENTES #######################\n");
    for(i=0 ; i<obtemnpacientes(sade) ; i++)
    {
        p = (tPaciente*)sade->pacientes[i];
        if(strcmp(nome, RetornaNome(p))==0)
        {
            if(a==0)
            {
                a=1;
                printf("PACIENTES ENCONTRADOS:\n");
            }
            printf("%d - %s (%s)\n", n, RetornaNome(p), RetornaCPFpaciente(p));
            n++;
        }
    }
    if(a==0)
    {
        printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR \n############################################################\n");
        return;
    }
    else
    {
        printf("\n");
        printf("SELECIONE UMA OPÇÃO:\n");
        printf("    (1) ENVIAR LISTA PARA IMPRESSAO\n");
        printf("    (2) RETORNAR AO MENU PRINCIPAL\n");
        printf("############################################################\n");
        scanf("%d", &n);
        if(n==1)
        {
            printf("#################### BUSCAR PACIENTES #######################\nLISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU PRINCIPAL\n############################################################\n");
            //como envia????
        }
        else if(n==2)
        {
            return;
        }
    }
}

int CPFInvalido(char *cpfpradentro, char* cpfdobanco)
{
    if(strcmp(cpfpradentro, cpfdobanco)==0)
    {
        return 1;
    }
    return 0;
}

tMedico *RetornaMedico(tSade* sade, int indice)
{
    tMedico *m = (tMedico*)sade->medicos[indice];
    return m;
}

tSecretario *RetornaSecretario(tSade* sade, int indice)
{
    tSecretario *s = (tSecretario*)sade->secretarios[indice];
    return s;
}

tPaciente *RetornaPaciente(tSade *sade, int indice)
{
    tPaciente *p = (tPaciente*)sade->pacientes[indice];
    return p;
}

int EhMesmoLogin(char *login1, char *login2, char *senha1, char *senha2)
{
    if(strcmp(login1, login2)==0 && strcmp(senha1, senha2)==0)
    {
        return 1;
    }
    return 0;
}