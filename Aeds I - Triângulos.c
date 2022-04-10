#include <stdio.h>

int main(void)
{

  double a, b, c;

      puts("Digite os lados do triângulo\n");

      puts("Escreva valor de a");

      scanf("%lf",&a);

      puts("Escreva valor de b");
      
      scanf("%lf",&b);

      puts("Escreva valor de c");

      scanf("%lf",&c);

      if (a <= 0 || b <= 0 || c <= 0){

        printf("Nenhum dos lados podem ser negativos\n");

        }else 
          
            if (a + b < c || a + c < b || b + c < a){

               printf("Não há Triângulo\n");

             }else

                if (a == b && a == c){

                  printf("Triângulo Equilátero");

                  }else 

                    if ( a == b || b ==c || a == c ){

                      printf("Triângulo Isósceles");
                   }else

                      printf("Triângulo Escaleno");

                  
                  if ((a*a) == (b*b) + (c*c) || (b*b) == (a*a) + (c*c) || (c*c) == (b*b) + (a*a)){

                    printf("Triângulo Retângulo");
                  }else 
      return 0;
}
