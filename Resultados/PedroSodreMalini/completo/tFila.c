#include "tFila.h"
#include "tDocumento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tFila{
    void **vet;
    int qntd;
};

tFila *criaFila()
{
    tFila *f = malloc(sizeof(tFila));
    f->vet = NULL;
    f->qntd = 0;
    return f;
}

void desalocaFila(tFila *f)
{
    int i;
    tDocumento *d;
    for(i=0 ; i<quantidadeDocumentosNaFila(f) ; i++)
    {
        if(f->vet[i]!=NULL)
        {
            desalocaDocumento(f->vet[i]);
        }
    }
    if(f->vet!=NULL)
    {
        free(f->vet);
    }
    if(f!=NULL)
    {
        free(f);
    }
}

int quantidadeDocumentosNaFila(tFila *f)
{
    return f->qntd;
}

void imprimeFila(tFila *f, char *path)
{
    int i;
    for(i=0 ; i<quantidadeDocumentosNaFila(f) ; i++)
    {
       imprimeNaTelaDocumento(f->vet[i]);
       imprimeEmArquivoDocumento(f->vet[i], path);
    }
}

void insereDocumentoFila(tFila *f, void *dado, func_ptr_imprimeNaTela imprimeNaTela, func_ptr_imprimeEmArquivo ImprimeEmArquivo, func_ptr_desaloca desaloca)
{
    f->qntd+=1;
    f->vet = realloc(f->vet, quantidadeDocumentosNaFila(f)*sizeof(void*));
    tDocumento *d = criaDocumento(dado, imprimeNaTela, ImprimeEmArquivo, desaloca);
    f->vet[f->qntd-1]=(void*)d;
}