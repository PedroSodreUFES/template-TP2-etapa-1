#include "tDocumento.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tDocumento{
    func_ptr_imprimeEmArquivo printArq;
    func_ptr_imprimeNaTela printTela;
    func_ptr_desaloca funcDesaloc;
    void *tipodedocumento;
};

tDocumento *criaDocumento(void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                          func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                          func_ptr_desaloca desaloca)
{
    tDocumento *d = malloc(sizeof(tDocumento));
    d->funcDesaloc = desaloca;
    d->printArq = ImprimeEmArquivo;
    d->printTela = imprimeNaTela;
    d->tipodedocumento = dado;
    return d;
}

void desalocaDocumento(tDocumento *doc)
{
    if(doc->tipodedocumento!=NULL)
    {
       doc->funcDesaloc(doc->tipodedocumento);
    }
    if(doc!=NULL)
    {
        free(doc);
    }
}

void imprimeNaTelaDocumento(tDocumento *doc)
{
    doc->printTela(doc->tipodedocumento);
}

void imprimeEmArquivoDocumento(tDocumento *doc, char *path)
{
    doc->printArq(doc->tipodedocumento, path);
}