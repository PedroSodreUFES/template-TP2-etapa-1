#include "tFila.h"
#include "tDocumento.h"
#include "tReceita.h"
#include "tSecretario.h"
#include "tMedico.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    tMedico *m = CriaMedico();
    PrintaMedico(m);
    DesalocaMedico(m);
    return 0;
}