#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagelib.h"

        // Código ajustado por Neves

int tom(int tom, int ls, int cs, int ml){ //Separa os tons em 7 partes para a imagem reduzida.
    int aux = ml/7;
    if(tom < aux){
        tom = 0;
    }else if(tom<aux*2){
        tom = 1;
    }else if(tom<aux*3){
        tom=2;
    }else if(tom<aux*4){
        tom=3;
    }else if(tom<aux*5){
        tom=4;
    }else if(tom<aux*6){
        tom=5;
    }else{
        tom=6;
    }
    return tom;
}

void dicing(image In, image Out, int nl, int nc, int salto, int ml)
{
    int ls, cs;
    salto = nc/100;
    ls = nl/salto;
    cs = nc/salto;
    for (int i = 0; i < ls; i++)
    {
        for (int j = 0; j < cs; j++)
        {
            //Out[i*nc+j] = In[i*nc+j];
            Out[i * cs + j] = In[i * nc * salto + j * salto];         
            // Out[i * nc + j] = In[i * nc + j];
            Out[i * cs + j]=tom(Out[i*cs+j], ls, cs, ml);
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
    printf("aaaa");
    
    salto = nc/100;
    int ls = nr/salto;
    int cs = nc/salto;

    Out = img_alloc(nr, nc);
    //-- transformation
    dicing(In, Out, nr, nc, salto, ml);


    //-- save image
    img_put(Out, nameOut, ls, cs, ml, GRAY);
    sprintf(cmd, "%s %s &", VIEW, nameOut);
    system(cmd);
    img_free(In);
    img_free(Out);
    return 0;
}
