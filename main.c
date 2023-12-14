#include "tFila.h"
#include "tDocumento.h"
#include "tReceita.h"
#include "tSecretario.h"
#include "tMedico.h"
#include "tPaciente.h"
#include "tSade.h"
#include "tConsulta.h"
#include "tLesao.h"
#include "tBiopsia.h"
#include "tEncaminhamento.h"
#include "tBuscaPaciente.h"
#include "tRelatorio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

    //DECLARACAO DE VARIAVEIS
    FILE *arq;//arquivo de entrada
    int opcao, secretariouser=0, secretarioadmin=0, medico=0, i, cpfjaexistente=0;
    char string[1024], login[21], senha[21], string2[2000], botao, cpf[15];

    //Sade
    tSade *sade;
    
    //Vetor de FILE
    tFila *fila = criaFila();


    /*
    ..................
    RECUPERA O BINARIO
    ..................
    */
    printf("################################################\nDIGITE O CAMINHO DO BANCO DE DADOS: ");
    scanf("%[^\n]%*c", string);
    printf("################################################\n");
    printf("Caminho do banco de dados: %s/%s\n", argv[1], string);
    sprintf(string2, "%s/%s", argv[1], "pacientes.bin");
    printf("Caminho do arquivo saida: %s/saida\n", argv[1]);
    arq = fopen(string2, "rb");
    
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
        sade = LeSade(arq);
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
    ..................................................
                        USO DO MENU
    ..................................................
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
                printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                scanf("%c%*c", &botao);
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
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                scanf("%c%*c", &botao);
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
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                scanf("%c%*c", &botao);
                printf("###############################################################\n");
            }
        }


        /*
        ....................................
                    CONSULTA MEDICA
        ....................................
        */
        else if(opcao==4 && secretariouser==0)
        {
            tConsulta *c = NULL;
            tLesao *lesao = NULL;
            printf("#################### CONSULTA MEDICA #######################\nCPF DO PACIENTE: ");
            scanf("%s%*c", cpf);
            if(VeSePacienteTaRegistrado(sade, cpf))
            {
                //printf("passou\n");
                c = CriaConsulta(RetornaPacienteCadastrado(sade, cpf));
                JaFoiConsultado(RetornaPacienteCadastrado(sade, cpf));
                printf("############################################################\n");
            }
            else
            {
                printf("PACIENTE SEM CADASTRO\n\nPRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                scanf("%c%*c", &botao);
                printf("############################################################\n");
                continue;
            }
            while(1)
            {
                PrintaMenuConsulta();
                scanf("%d%*c", &opcao);
                //CADASTRA LESAO
                if(opcao==1)
                {
                    lesao = CadastraLesao();
                    InsereLesoesNaConsulta(c, lesao);
                    InsereLesoes(sade, lesao);       
                }

                //FAZ RECEITA
                else if(opcao==2)
                {
                    eTipoUso tipodeuso;
                    char nomedomedicamento[51], tipodemedicamento[51],  instrucoes[301], tipodeusoc[20];
                    int qntd;
                    printf("#################### CONSULTA MEDICA #######################\nRECEITA MEDICA:\n");
                    printf("TIPO DE USO: ");
                    scanf("%s%*c", tipodeusoc);
                    if(strcmp(tipodeusoc, "ORAL")==0)
                    {
                        tipodeuso=ORAL;
                    }
                    else
                    {
                        tipodeuso=TOPICO;
                    }
                    printf("NOME DO MEDICAMENTO: ");
                    scanf("%[^\n]%*c", nomedomedicamento);
                    printf("TIPO DE MEDICAMENTO: ");
                    scanf("%s%*c", tipodemedicamento);
                    printf("QUANTIDADE: ");
                    scanf("%d%*c", &qntd);
                    printf("INSTRUÇÕES DE USO: ");
                    scanf("%[^\n]%*c", instrucoes);
                    printf("\n");
                    instrucoes[strlen(instrucoes)]='\0';
                    nomedomedicamento[strlen(nomedomedicamento)]='\0';
                    tReceita *re = criaReceita(ConsultaNomePaciente(c), tipodeuso, nomedomedicamento, tipodemedicamento, instrucoes, qntd, "\0", "\0", ConsultaData(c));
                    insereDocumentoFila(fila, (void*)re, imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);
                    printf("RECEITA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n############################################################\n");
                    scanf("%c%*c", &botao);
                }

                //PEDE BIÓPSIA
                else if(opcao==3)
                {
                    /*if(coletado==1)
                    {
                        printf("#################### CONSULTA MEDICA #######################\nSOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n############################################################\n");
                        scanf("%c%*c", &botao);
                        continue;
                    }*/
                    if(NaoPrecisaCirurgia(c))
                    {
                        printf("#################### CONSULTA MEDICA #######################\nNAO E POSSIVEL SOLICITAR BIOPSIA SEM LESAO CIRURGICA. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n############################################################\n");
                        scanf("%c%*c", &botao);
                        continue;
                    }
                    tBiopsia *biopsia = CriaBiopsia(c, cpf);
                    insereDocumentoFila(fila ,(void*)biopsia, imprimeNaTelaBiopsia, imprimeEmArquivoBiopsia, desalocaBiopsia);
                    printf("#################### CONSULTA MEDICA #######################\nSOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                    scanf("%c%*c", &botao);
                    printf("############################################################\n");
                }

                //PEDE ENCAMINHAMENTO
                else if(opcao==4)
                {
                    tEncaminhamento *e = CriaEncaminhamento(c, cpf);
                    insereDocumentoFila(fila, (void*)e , imprimeNaTelaEncaminhamento, imprimeEmArquivoEncaminhamento, desalocaEncaminhamento);
                    printf("ENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                    scanf("%c%*c", &botao);
                    printf("############################################################\n");
                }

                //ENCERRA CONSULTA
                else if(opcao==5)
                {
                    InsereConsulta(sade, c);
                    break;
                }
            }            
        }


        /*
        ...............................
                BUSCAR PACIENTE     
        ...............................
        */
        else if(opcao==5)
        {
            tBusca *b = criabusca(sade);
            if(!BuscaNpacientes(b))
            {
                printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR \n############################################################\n");
                desalocaBusca(b);
                scanf("%c%*c", &botao);
                continue;
            }
            printf("#################### BUSCAR PACIENTES #######################\n");
            printf("ESCOLHA UMA OPCAO:\n	(1) ENVIAR LISTA PARA IMPRESSAO\n	(2) RETORNAR AO MENU PRINCIPAL\n");
            printf("############################################################\n\n");
            scanf("%d%*c", &opcao);
            if(opcao==1)
            {
                insereDocumentoFila(fila, (void*)b, imprimeBuscaNaTela, imprimeEmArquivoBusca, desalocaBusca);
                printf("LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU PRINCIPAL\n############################################################\n");
                scanf("%c%*c", &botao);
            }
            else
            {
                desalocaBusca(b);
            }
        }

        /*
        ................................
                RELATORIO GERAL
        ................................
        */
        else if(opcao==6)
        {
            tRelatorio *r = CriaRelatorio(sade);
            printf("#################### RELATORIO GERAL #######################\n");
            imprimeNaTelaRelatorio((void*)r);
            printf("SELECIONE UMA OPÇÃO:\n");
            printf("    (1) ENVIAR PARA IMPRESSAO\n");
            printf("    (2) RETORNAR AO MENU PRINCIPAL\n");
            printf("############################################################\n\n");
            scanf("%d%*c", &opcao);
            if(opcao==1)
            {
                insereDocumentoFila(fila, (void*)r, imprimeNaTelaRelatorio, imprimeEmArquivoRelatorio, desalocaRelatorio);
                printf("RELATÓRIO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                scanf("%c%*c", &botao);
                printf("############################################################\n");
            }
            else
            {
                desalocaRelatorio(r);
            }
        }

        /*
        ................................
            FILA DE IMPRESSAO
        ................................
        */
        else if(opcao==7)
        {
            while(1)
            {
                printf("################### FILA DE IMPRESSAO MEDICA #####################\n");
                printf("ESCOLHA UMA OPCAO:\n	(1) EXECUTAR FILA DE IMPRESSAO\n	(2) RETORNAR AO MENU PRINCIPAL\n############################################################\n"); 
                scanf("%d%*c", &opcao);
                if(opcao==1)
                {
                    printf("################ FILA DE IMPRESSAO MEDICA ##################\nEXECUTANDO FILA DE IMPRESSAO:\n");
                    imprimeFila(fila, argv[1]);
                    printf("\nPRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU ANTERIOR\n");
                    scanf("%c%*c", &botao);
                    printf("############################################################\n");
                }
                else if(opcao==2)
                {
                    break;
                }
            }
        }

        /*
        ...............................
                      SAIR
        ...............................
        */
        else if(opcao==8)
        {
            break;
        }
    }
    GeraBinario(sade, argv[1]);
    DesalocaSade(sade);
    desalocaFila(fila);
    if(arq!=NULL)
    {
        fclose(arq);
    }
    return 0;
}