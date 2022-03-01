#include <stdio.h>

int main(void)
{

  int *ponteiro; // Declara uma variável ponteiro
                 // Guarda o endereço na memória onde existe um valor inteiro
  int i = 10;
  char c = 'H';
  char *pont;

  printf("%p = %i\n", &i, i);
  printf("%p = %c\n", &c, c);
  
  ponteiro = &i; // Adiciona o Endereço no ponteiro
  pont = &c;
  
  printf("%p = %i\n", ponteiro, *ponteiro); // O "ponteiro" representa o endereço
                                            // Já o "*ponteiro" representa o valor no endereço
  printf("%p = %c\n", pont, *pont);
  
  
}
