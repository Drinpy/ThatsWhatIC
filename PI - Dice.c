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

void leituradados()
{
    int temp = 0;

image dado0 = img_get("./0.pgm", &temp, &temp, &temp, GRAY);

image dado1 = img_get("./1.pgm", &temp, &temp, &temp, GRAY);

image dado2 = img_get("./2.pgm", &temp, &temp, &temp, GRAY);

image dado3 = img_get("./3.pgm", &temp, &temp, &temp, GRAY);

image dado4 = img_get("./4.pgm", &temp, &temp, &temp, GRAY);

image dado5 = img_get("./5.pgm", &temp, &temp, &temp, GRAY);

image dado6 = img_get("./6.pgm", &temp, &temp, &temp, GRAY);

}

void dicingimg(image In, image Out, int nl, int nc, int salto, int ml)
{

    int cs = nc * 40;

    for(int i = 0; i < nl; i++)
    {
        for(int j = 0; j < nc; j++)
        {
            image *dadoaux;
            In[i * nc + j];
        }
    }

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
    int nc, nr, ml, tp, salto, dado0, dado1, dado2, dado3, dado4, dado5, dado6;
    char *p, nameIn[100], nameOut[100], cmd[110];
    image In, Out;
    if (argc < 2)
        msg(argv[0]);
    img_name(argv[1], nameIn, nameOut, GRAY);
    //-- read image
    In = img_get(nameIn, &nr, &nc, &ml, GRAY);
    // printf("aaaa"); 
    
    salto = nc/100;
    int ls = nr/salto;
    int cs = nc/salto;

    Out = img_alloc(nr, nc);
    //-- transformation
    dicing(In, Out, nr, nc, salto, ml);


    //-- save image
    img_put(Out, nameOut, ls, cs, 7, GRAY);
    sprintf(cmd, "%s %s &", VIEW, nameOut);
    system(cmd);
    img_free(In);
    img_free(Out);
    return 0;
}
