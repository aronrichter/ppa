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
   retorno->linhas = linhas; //ou (*retorno).linhas = linhas
   retorno->colunas = colunas;

   //alocação de memória do ponteiro dentro da matriz
   retorno->dados = (double **) malloc(sizeof(double *) * retorno->linhas);
   
   //verifiquei se conseguimos memória
   if(!retorno->dados) {
      printf("Sem memória!\n");
      exit(EXIT_FAILURE);
   }

   int i;

   for (i = 0; i < retorno->linhas; i++) {
      retorno->dados[i] = (double *) malloc(sizeof(double) * retorno-> colunas);

      if(!retorno->dados[i]) {
         printf("Sem memória!\n");
         exit(EXIT_FAILURE);
      }
   }

   return retorno;
}

void matriz_destruir(matriz_t *m) {
    int i;

    for(i=0; i< m->linhas; i++) {
       free(m->dados[i]);
    }

    free(m->dados);
    free(m);

    printf("Dados limpos");
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
   matriz_t *retorno = NULL;
   int i, j, k;
    
   retorno =  matriz_criar(A->linhas, A->colunas);   
    
   for (i = 0; i < A->linhas; i++) {
      for (j = 0; j < B->colunas; j++) {  
        int aux = 0;
        for(k = 0; k < A->linhas-1; k++) {
            aux += A->dados[i][k] * B->dados[k][j];
        } 
        printf("aux %d \n", aux);
        retorno->dados[i][j] = aux;
      }
   }
    
    return retorno;
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
   matriz_t *retorno = NULL;
   int i, j;

   retorno =  matriz_criar(A->linhas, A->colunas);   

    printf("Soma\n");

   for (i = 0; i < A->linhas; i++) {
      for (j = 0; j < B->colunas; j++) {          
         retorno->dados[i][j] = A->dados[i][j] + B->dados[i][j];

         printf("%.17f + %.17f = %.17f\n", A->dados[i][j], B->dados[i][j], retorno->dados[i][j]);
      }
   }
    
    return retorno;
}

