#include <stdio.h>

  int i, j, vet[10], vet2[10];


int main(void)
{

  for (i = 0; i < 10; i++)
    {
      printf("Escreva os valores no Vetor\n");
      scanf("%i", &vet[i]);
     }

    for (i = 0; i < 10; i++)
      {
    vet2[i] = vet[i];
      }

    printf("\n");
    printf("Valores\n");

    for (i = 0; i < 10; i++)
      {

    printf("%i\n", vet2[i]);

     }
}
