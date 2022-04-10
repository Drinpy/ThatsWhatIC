#include <stdio.h>

int main (void)
 {   

    float notas[4];
    int i;

      for (i = 0; i < 4; i++) {

        printf("Coloque a nota do aluno %d: \n", i + 1);
          scanf("%f", &notas[i]);
       
      }
        printf("\n");
      for (i = 0; i < 4; i++) {

                             
        printf("Nota %d = %.2f\n", i + 1, notas[i]);
        // "i + 1" são as posições no vetor //
        // "notas[i]" são os valores no vetor //
      }

      return 0;
}
