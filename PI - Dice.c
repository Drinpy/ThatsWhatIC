#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagelib.h"


void dicing(image In, image Out, int nl, int nc, int salto)
{
    int ls, cs;
    salto = nc/100;
    ls = nl/salto;
    cs = nc/salto;
    for (int i = 0; i < nl - 1; i++)
    {
        for (int j = 0; j < nc - 1; j++)
        {
     
            Out[i * nc + j] = In[i * cs * salto + j * salto];         
               // Out[i * nc + j] = In[i * nc + j];
        }
    }
}

void msg(char *s)
{
    printf("\ndice"); // Em caso de mudança fazer 'make' de novo
    printf("\n-------------------------------");
    printf("\nUso:  %s  nome-imagem[.pgm] \n\n", s);
    printf("    nome-imagem[.pgm] é o nome do arquivo da imagem \n");
    exit(1);
}

/*-------------------------------------------------------------------------
 * main function
 *-------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int nc, nr, ml, tp, salto;
    char *p, nameIn[100], nameOut[100], cmd[110];
    image In, Out;
    if (argc < 2)
        msg(argv[0]);
    img_name(argv[1], nameIn, nameOut, GRAY);
    //-- read image
    In = img_get(nameIn, &nr, &nc, &ml, GRAY);
    Out = img_alloc(nr, nc);
    //-- transformation
    dicing(In, Out, nr, nc, salto);



    //-- save image
    img_put(Out, nameOut, nr, nc, ml, GRAY);
    sprintf(cmd, "%s %s &", VIEW, nameOut);
    system(cmd);
    img_free(In);
    img_free(Out);
    return 0;
}
