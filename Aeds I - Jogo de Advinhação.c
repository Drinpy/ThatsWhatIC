#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Jogo modificado por Pedro Henrique Borges Luiz.
//Em fase de testes.

int main(void)

{
  int chute, num;
  int i = 3;

  srand((unsigned)time(NULL));
  num = rand() % 10;
  puts ("\n");
  puts ("Esse é um jogo de advinhação\n");
  puts ("AINDA EM FASE DE TESTES!! \nSUJEITO A BUGS!!\n");
  puts ("Objetivo:");
  puts ("Eu escondi um número entre 0 e 10!! Tente adivinhá-lo\n");
  puts ("Instruções:");
  puts ("|Digite um número de (0 a 10)|");
  puts ("|Você tem 3 tentativas!|\n");

  scanf("%i", &chute);

  while(i > 0)
  {

  if (chute == num)
  {

       puts ("\n");
    printf("Parabéns! Você acertou!!\n");
    break;

    }
    else
    {

       puts ("\n");
       i--;
      if (i == 0)
        break;
      printf("Poxa, você errou!\n");
      printf("Tente novamente!\n");
      printf("Tentativas sobrando:%i\n", i);
      scanf("%i", &chute);
      
    }
  
  }

      printf("O número era: %i\n", num);

      return 0;
    }
