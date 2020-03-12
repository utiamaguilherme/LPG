#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

///////////////////////////////////////////
/////////////FUNCOES///////////////////////
///////////////////////////////////////////

MatrizEsparsa carregar(FILE *arquivao, int n){
  /*int i,j;
  int n = escolha_arquivo(arq_1, arq_2);
    MatrizEsparsa a[2];
    printf("Carregando a Matriz\n");
    if(n == 1){
      a[0].m->coluna=0;
      fscanf(entrada_1,"%d %d", &a[0].num_linhas, &a[0].num_colunas);
      printf("%d %d\n",a[0].num_linhas, a[0].num_colunas);
      a[0].m = malloc(sizeof(int*)*a[0].num_linhas);
      for(i=0; i<a[0].num_linhas; i++){
        a[0].m[i] = malloc(sizeof(int)*a[0].num_colunas);
        for(j=0; j<a[0].num_colunas; j++){
          fscanf(entrada_1,"%lf", a[0].m[i][a[0].m[i]->coluna].valor);
          if(a[0].m[i][a[0].m[i]->coluna] != 0)
          {
            a[0].m[i]->coluna +=1;
            a[0].m[i] = realloc(a[0].m[i], sizeof(float*)*a[0].m[i]->coluna);
          }
        }
        if(a[0].m[i][a[0].m[i]->coluna] != a[0].num_colunas - 1)
          a[0].m[i][a[0].m[i]->coluna] = -1;
        a[0].m[i]->coluna = 0;
      }
    }
    else{
      fscanf(entrada_2, "%d %d", &a[1].num_linhas, &a[1].num_colunas);
      printf("%d %d\n",a[1].num_linhas, a[1].num_colunas);
      a[1].m = malloc(sizeof(int*)*a[1].num_linhas);
      for(i=0; i<a[1].num_linhas; i++){
        a[1].m[i] = malloc(sizeof(int)*a[1].num_colunas);
        for(j=0; j<a[1].num_colunas; j++){
          a[1].m[i][j].valor = 0;
        }
      }
      for(i=0; i<a[1].num_linhas; i++)
      {
        for(j=0; j<a[1].num_colunas; j++){
          printf("%.1f", a[1].m[i][j].valor);
        }
        printf("\n");
      }
  }*/
  int cont = 0, i, j;
  float valor_da_matriz;
  MatrizEsparsa a;
    printf("CARREGANDO MATRIZ\n");
    rewind(arquivao);
    fscanf(arquivao, "%d %d", &a.num_linhas, &a.num_colunas);
    printf("%d %d", a.num_linhas, a.num_colunas);

    for(i = 0; i<a.num_linhas; i++){
      for(j = 0; j<a.num_colunas; j++){

        fscanf(arquivao, "%f", &valor_da_matriz);

        if(valor_da_matriz != 0){
          a.m[i][cont].coluna = j;
          a.m[i][cont].valor = valor_da_matriz;
          cont++;
        }
      }

      a.m[i] = realloc(a.m[i], sizeof(EntradaMatriz*)*cont);
      a.m[i][cont].coluna = -1;
      cont = 0;
    }


  return a;
}
void visualizar(MatrizEsparsa a){

  if(a.num_linhas != 0){
    int cont = 0;

    for(int i=0; i<a.num_linhas; i++){
      for(int j=0; j<a.num_colunas; j++){
        printf("%f   ", a.m[i][cont].valor);
        cont++;
      }
      printf("\n");
      cont = 0;
    }
  }
}

void modificar(FILE *arquivao, int n){

  if(n == 1){
    // carregar(arquivao, n);

  }

  else{
    // carregar(arquivao, n);

  }
}

void salvar(FILE *arquivao, int n){


  if(n == 1){
    // carregar(arquivao, n);

  }

  else{
    // carregar(arquivao, n);

  }
}

void somar(FILE *arq_1, FILE *arq_2){

}

void subtrair(FILE *arq_1, FILE *arq_2){

}

void multiplicar(FILE *arq_1, FILE *arq_2){

}

void reescrita_w(FILE *arquivao){

}

char *aloca_string(){
  char buffer[101], *leitura=NULL;
  fgets(buffer,100,stdin);
  leitura = malloc(sizeof(char)*(strlen(buffer)+1));
  strcpy(leitura,buffer);
  leitura[strlen(leitura)-1] = '\0';
  return leitura;
}

int escolha_arquivo(char *arq_1, char *arq_2){
  printf("Voce deseja qual arquivo?\n");
  int valor=5;
  while(valor < 0 || valor > 1){
  printf("0. %s\n", arq_1);
  printf("1. %s\n", arq_2);
  scanf("%d", &valor);
  }
  return valor;
}
