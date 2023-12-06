#include "tFila.h"
#include "tDocumento.h"
#include "tReceita.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct tFila{
    void **vet;
    int qntd;
};

struct tDocumento{
    func_ptr_imprimeEmArquivo printArq;
    func_ptr_imprimeNaTela printTela;
    func_ptr_desaloca funcDesaloc;
    void *tipodedocumento;
};

int main()
{
    
}