#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int media(int argc, const char **argv) {
  int qtdparametros = argc;
  int vet[qtdparametros];
  int soma = 0;

  if (argc <= 1) {
    printf("Informe os valores para calcular a media em uma linha: \n");
    return 0;
  }

  for (int i = 0; i < qtdparametros; i++) {
    vet[i] = atoi(argv[i]);
  }

  for (int i = 0; i < qtdparametros; i++) {
    soma += vet[i];
  }

  int media = soma / (qtdparametros - 1);

  printf("A media dos valores informados eh: %d\n", media);
}