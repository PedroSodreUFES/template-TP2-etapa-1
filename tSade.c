#include "tSade.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _tSade
{
    void **secretarios, **medicos, **pacientes, **consultas, **lesoes;
    int nsecretarios, nmedicos, npacientes, nconsultas, nlesoes;
};

int VeSePacienteTaRegistrado(tSade *sade, char *cpf)
{
    int i;
    for(i=0 ; i<obtemnpacientes(sade) ; i++)
    {
        tPaciente *p = RetornaPaciente(sade, i);
        if(strcmp(cpf, RetornaCPFpaciente(p))==0)
        {
            return 1;
        }
    }
    return 0;
}

tPaciente *RetornaPacienteCadastrado(tSade *sade, char *cpf)
{
    int i;
    for(i=0 ; i<obtemnpacientes(sade) ; i++)
    {
        tPaciente *p = (tPaciente*)RetornaPaciente(sade, i);
        if(strcmp(cpf, RetornaCPFpaciente(p))==0)
        {
            return p;
        }
    }
}

tSade *CriaSade()
{
    tSade *sade = malloc(sizeof(tSade));
    sade->nmedicos=0;
    sade->npacientes=0;
    sade->nsecretarios=0;
    sade->nconsultas=0;
    sade->nlesoes=0;
    sade->lesoes=NULL;
    sade->medicos=NULL;
    sade->pacientes=NULL;
    sade->secretarios=NULL;
    sade->consultas=NULL;
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


int obtemnconsultas(tSade *sade)
{
    return sade->nconsultas;
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

void InsereConsulta(tSade *sade, tConsulta *consulta)
{
    sade->nconsultas++;
    sade->consultas = realloc(sade->consultas , obtemnconsultas(sade)*sizeof(void*));
    sade->consultas[obtemnconsultas(sade)-1] = (void*)consulta;
}

void InsereLesoes(tSade *sade, tLesao *lesao)
{
    sade->nlesoes++;
    sade->lesoes = realloc(sade->lesoes, obtemnlesoes(sade)*sizeof(void*));
    tLesao *clone = ClonaLesao(lesao);
    sade->lesoes[obtemnlesoes(sade)-1]=(void*)clone;
}

int obtemnlesoes(tSade *sade)
{
    return sade->nlesoes;
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

int CPFInvalido(char *cpfpradentro, char* cpfdobanco)
{
    if(strcmp(cpfpradentro, cpfdobanco)==0)
    {
        return 1;
    }
    return 0;
}

tConsulta *RetornaConsulta(tSade *sade, int indice)
{
    tConsulta *c  = (tConsulta*)sade->consultas[indice];
    return c;
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

tLesao *RetornaLesao(tSade *sade, int indice)
{
    tLesao *l = (tLesao*)sade->lesoes[indice];
    return l;
}

int EhMesmoLogin(char *login1, char *login2, char *senha1, char *senha2)
{
    if(strcmp(login1, login2)==0 && strcmp(senha1, senha2)==0)
    {
        return 1;
    }
    return 0;
}

int CalculaIdadePessoa(tPaciente *p, char *dataatual)
{
    int dia1, mes1, ano1, dia2, mes2, ano2, idade;
    sscanf(retornadatapaciente(p), "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(dataatual, "%d/%d/%d", &dia2, &mes2, &ano2);
    idade = ano2 - ano1;
    if(mes2<mes1)
    {
        idade--;
    }
    else if(mes1 == mes2)
    {
        if(dia2<dia1)
        {
            idade--;
        }
    }
    return idade;
}


/*struct _tSade
{
    void **secretarios, **medicos, **pacientes, **consultas, **lesoes;
    int nsecretarios, nmedicos, npacientes, nconsultas, nlesoes;
};*/

void DesalocaSade(tSade *sade)
{
    int i;
    for(i=0 ; i<obtemnsecretarios(sade); i++)
    {
        DesalocaSecretario(RetornaSecretario(sade, i));
    }
    if(sade->secretarios!=NULL)
    {
        free(sade->secretarios);
    }

    for(i=0 ; i<obtemnmedicos(sade) ; i++)
    {
        DesalocaMedico(RetornaMedico(sade, i));
    }
    if(sade->medicos!=NULL)
    {
        free(sade->medicos);
    }
    
    for(i=0 ; i<obtemnpacientes(sade) ; i++)
    {   
        DesalocaPaciente(RetornaPaciente(sade, i));
    }
    if(sade->pacientes!=NULL)
    {
        free(sade->pacientes);
    }
    
    for(i=0 ; i<obtemnlesoes(sade) ; i++)
    {
        DesalocaLesao(RetornaLesao(sade, i));
    }
    if(sade->lesoes!=NULL)
    {
        free(sade->lesoes);
    }
    for(i=0 ; i<obtemnconsultas(sade) ; i++)
    {
        DesalocaConsulta(RetornaConsulta(sade, i));
    }
    if(sade->consultas!=NULL)
    {
        free(sade->consultas);
    }

    if(sade!=NULL)
    {
        free(sade);
    }
}

void GeraBinario(tSade*sade)
{

}

tSade *LeSade(tSade *sade, FILE *arquivo)
{
    
}