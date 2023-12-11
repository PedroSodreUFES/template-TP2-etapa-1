#include "tFila.h"
#include "tDocumento.h"
#include "tReceita.h"
#include "tSecretario.h"
#include "tMedico.h"
#include "tPaciente.h"
#include "tSade.h"
#include "tConsulta.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

    //DECLARACAO DE VARIAVEIS
    FILE *arq;
    int opcao, secretariouser=0, secretarioadmin=0, medico=0, i, cpfjaexistente=0;
    char string[1024], login[21], senha[21], string2[2000];
    tSade *sade;
    tMedico *usuariomedico;
    tSecretario *usuariosecretario;


    /*
    ..................
    RECUPERA O BINARIO
    ..................
    */
    printf("################################################\nDIGITE O CAMINHO DO BANCO DE DADOS: ");
    scanf("%s%*c", string);
    printf("################################################\n");
    printf("Caminho do banco de dados: %s/%s\n", argv[1], string);
    sprintf(string2, "%s/%s", argv[1], string);
    printf("Caminho do arquivo saida: %s/saida\n", argv[1]);
    arq = fopen(string, "rb");


    /*
    ..............................
    SE O BANCO DE DADOS NAO EXISTE
    ..............................
    */
    if(arq==NULL)
    {
        sade = CriaSade();
        tSecretario *s = CriaSecretario();
        InsereSecretario(sade, s);
    }

    /*
    ..........................
    SE O BANCO DE DADOS EXISTE
    ..........................
    */

   else
   {

   }
    

    /*
    ..............................
    login e indicar quem ta usando
    ..............................
    */
    while(1)
    {
        printf("######################## ACESSO MINI-SADE ######################\n");
        printf("DIGITE SEU LOGIN: ");
        scanf("%s%*c", login);
        printf("DIGITE SUA SENHA: ");
        scanf("%s%*c", senha);
        printf("###############################################################\n");
        for(i=0 ; i<obtemnmedicos(sade) ; i++)
        {
            tMedico *m = (tMedico*)RetornaMedico(sade, i);
            if(EhMesmoLogin(retornaloginmedico(m), login, retornasenhamedico(m), senha))
            {
                usuariomedico=m;
                medico=1;
                break;
            }
        }
        if(medico==1)
        {
            break;
        }
        for(i=0 ; i<obtemnsecretarios(sade) ; i++)
        {
            tSecretario *s = (tSecretario*)RetornaSecretario(sade, i);
            if(EhMesmoLogin(retornaloginsecretario(s), login, retornasenhasecretario(s), senha))
            {
                usuariosecretario=s;
                if(EhAdmin(s))
                {
                    secretarioadmin=1;
                }
                else
                {
                    secretariouser=1;
                }
                break;
            }
        }
        if(secretariouser==1 || secretarioadmin==1)
        {
            break;
        }
        printf("SENHA INCORRETA OU USUARIO INEXISTENTE\n");
    }

   

    /*
    ...........
    USO DO MENU
    ...........
    */
    while(1)
    {
        cpfjaexistente=0;
        if(medico==1)
        {
            PrintaMenuMedico();
        }
        else if(secretarioadmin==1)
        {
            PrintaMenuSecretarioAdmin();
        }
        else if(secretariouser==1)
        {
            PrintaMenuSecretarioUser();
        }
        scanf("%d", &opcao);
        scanf("%*c");
        
        //CADASTRA SECRETARIO
        if(opcao==1 && secretarioadmin==1)
        {
            tSecretario *s = CriaSecretario();
            for(i=0 ; i<obtemnsecretarios(sade) ; i++)
            {
                if(strcmp(retornaCPFsecretario(s), retornaCPFsecretario(RetornaSecretario(sade, i)))==0)
                {
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                    cpfjaexistente=1;
                    DesalocaSecretario(s);
                    break;
                }
            }
            if(cpfjaexistente==0)
            {
                InsereSecretario(sade, s);   
                printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\nVOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################\n");
            }
        }

        //CADASTRA MÉDICO
        else if(opcao==2 && medico==0)
        {
            tMedico *m = CriaMedico();
            for(i=0 ; i<obtemnmedicos(sade) ; i++)
            {
                if(strcmp(retornaCPFmedico(m), retornaCPFmedico(RetornaMedico(sade, i)))==0)
                {
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                    cpfjaexistente=1;
                    DesalocaMedico(m);
                    break;
                }
            }
            if(cpfjaexistente==0)
            {
                InsereMedico(sade, m);
                printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\nVOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################\n");
            }
        }

        //CADASTRA PACIENTE
        else if(opcao==3 && medico==0)
        {
            tPaciente *p = CriaPaciente();
            for(i=0 ; i<obtemnpacientes(sade) ; i++)
            {
                if(strcmp(RetornaCPFpaciente(p), RetornaCPFpaciente(RetornaPaciente(sade, i)))==0)
                {
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                    cpfjaexistente=1;
                    DesalocaPaciente(p);
                    break;
                }
            }
            if(cpfjaexistente==0)
            {
                InserePaciente(sade, p);
                printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\nVOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################\n");
            }
        }
        else if(opcao==4 && secretariouser==0)
        {

        }
        else if(opcao==5)
        {

        }
        else if(opcao==6)
        {

        }
        else if(opcao==7)
        {

        }
        else if(opcao==8)
        {
            break;
        }
        else
        {
            printf("Opcao invalida\n");
        }
    }
    /*
    SalvaSade();
    DesalocaSade();
    */
    return 0;
}