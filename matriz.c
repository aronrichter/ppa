#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

matriz_t *matriz_criar(int linhas, int colunas) {
   matriz_t *retorno = NULL;

   //alocação de memória
   retorno = (matriz_t *) malloc(sizeof(matriz_t));

   //verifiquei se conseguimos memória
   if(!retorno) {
      printf("Sem memória!\n");
      exit(EXIT_FAILURE);
   }

   //atribuir informações no atributo do ponteiro (struct)
   retorno->linhas = linhas;
   retorno->colunas = colunas;

   

   return retorno;
}

void matriz_destruir(matriz_t *m) {
    printf("Implementar\n");
    return;
}

void matriz_preencher_rand(matriz_t *m) {
   int i, j;
   for (i = 0; i < m->linhas; i++) {
      for (j = 0; j < m->colunas; j++) {
         m->dados[i][j] = random();
      }
   }
}

void matriz_preencher(matriz_t *m, double valor) {
   int i, j;
   for (i = 0; i < m->linhas; i++) {
      for (j = 0; j < m->colunas; j++) {
         m->dados[i][j] = valor;
      }
   }
}

matriz_t *matriz_multiplicar(matriz_t *A, matriz_t *B) {
    printf("Implementar!\n");
    return NULL;
}

void matriz_imprimir(matriz_t *m) {
   int i, j;
   for (i = 0; i < m->linhas; i++) {
      for (j = 0; j < m->colunas; j++) {
         printf("%.17f ", m->dados[i][j]);
      }
      printf("\n");
   }
}

matriz_t *matriz_somar(matriz_t *A, matriz_t *B) {
    printf("Implementar!\n");
    return NULL;
}

