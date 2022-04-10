#include <stdio.h>

int main(void)
{

 double time, speed, alcool, gasolina, gpl;

    alcool = 3.10;
    gasolina = 4.20;

    puts("-----Cálculo do gasto de combustível-----\n");
    puts("Preencha as informações a seguir para uma determinada viagem\n");
    puts("Quilometragem por litro:");
     scanf("%lf", &gpl);
    puts("Tempo previsto de viagem:");
     scanf("%lf", &time);
    puts("Velocidade média do carro:");
     scanf("%lf", &speed);


     printf("-----Valores inseridos-----\n");

     printf("\n");

     printf("KM/L: %.2lf\n", gpl);
     printf("Tempo de viagem: %.2lf\n", time);
     printf("Velocidade média: %.2lf\n", speed);

     printf("\n");

     printf("-----Resultado do cálculo-----\n");

     printf("\n");

    printf("Gasto de combustível: %.3lf\n", time * speed/gpl );
    printf("Preço usando álcool: %.2lf\n", alcool * time * speed/gpl );
    printf("Preço usando gasolina: %.2lf\n", gasolina * time * speed/gpl );

    return 0;
}
