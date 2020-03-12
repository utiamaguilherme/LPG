#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

void menu(int k, FILE *entrada_1, FILE *entrada_2, FILE *saida, char *arq_1, char *arq_2){
  switch(k){
    case 1:
    carregar(entrada_1, entrada_2, saida, arq_1, arq_2);
    break;

    case 2:
    visualizar(entrada_1, entrada_2, saida, arq_1, arq_2);
    break;

    case 3:
    modificar(entrada_1, entrada_2, saida, arq_1, arq_2); // recebe as coordenadas;
    break;

    case 4:
    salvar(entrada_1, entrada_2, saida, arq_1, arq_2);
    break;

    case 5:
    somar(entrada_1, entrada_2, saida);
    break;

    case 6:
    subtrair(entrada_1, entrada_2, saida);
    break;

    case 7:
    multiplicar(entrada_1, entrada_2, saida);
    break;
  }
}
///////////////////////////////////////////
/////////////FUNCOES///////////////////////
///////////////////////////////////////////

void carregar(FILE *entrada_1, FILE *entrada_2, FILE *saida, char *arq_1, char *arq_2, ?????matriz struct){

  int n = escolha_arquivo(arq_1, arq_2);

  if(n == 1){
    int **m, i, j;
    MatrizEsparsa a;
    printf("Carregando a Matriz\n");
    fscanf(entrada_1,"%d %d", &a.num_linhas, &a.num_colunas);
    printf("%d %d\n",a.num_linhas, a.num_colunas);
    m = malloc(sizeof(int*)*a.num_linhas);
    for(i=0; i<a.num_linhas; i++){
      m[i] = malloc(sizeof(int)*a.num_colunas);
      for(j=0; j<a.num_colunas; j++){
        m[i][j] = 0;
      }
    }
  }

  else{
    int **m, i, j;
    MatrizEsparsa a;
    printf("Carregando a Matriz\n");
    fscanf(entrada_2,"%d %d", &a.num_linhas, &a.num_colunas);
    printf("%d %d\n",a.num_linhas, a.num_colunas);
    m = malloc(sizeof(int*)*a.num_linhas);
    for(i=0; i<a.num_linhas; i++){
      m[i] = malloc(sizeof(int)*a.num_colunas);
      for(j=0; j<a.num_colunas; j++){
        m[i][j] = 0;
      }
    }
  }
}
void visualizar(FILE *entrada_1, FILE *entrada_2, FILE *saida, char *arq_1, char *arq_2){

  int n = escolha_arquivo(arq_1, arq_2);

  if(n == 1){
    carregar(entrada_1,entrada_2,saida,arq_1,arq_2);
  }

  else{
    carregar(entrada_1,entrada_2,saida,arq_1,arq_2);
  }
}

void modificar(FILE *entrada_1, FILE *entrada_2, FILE *saida, char *arq_1, char *arq_2){

  int n = escolha_arquivo(arq_1, arq_2);

  if(n == 1){
    carregar(entrada_1,entrada_2,saida,arq_1,arq_2);

  }

  else{
  carregar(entrada_1,entrada_2,saida,arq_1,arq_2);

  }
}

void salvar(FILE *entrada_1, FILE *entrada_2, FILE *saida, char *arq_1, char *arq_2){

  int n = escolha_arquivo(arq_1, arq_2);

  if(n == 1){
    carregar(entrada_1,entrada_2,saida,arq_1,arq_2);

  }

  else{
    carregar(entrada_1,entrada_2,saida,arq_1,arq_2);

  }
}

void somar(FILE *entrada_1, FILE *entrada_2, FILE *saida){

}

void subtrair(FILE *entrada_1, FILE *entrada_2, FILE *saida){

}

void multiplicar(FILE *entrada_1, FILE *entrada_2, FILE *saida){

}

void reescrita_w(FILE *entrada_1, FILE *entrada_2, FILE *saida){

}

char *aloca_string(){
  char buffer[101], *leitura=NULL;
  fgets(buffer,100,stdin);
  leitura = malloc(sizeof(char)*(strlen(buffer)+1));
  strcpy(leitura,buffer);
  return leitura;
}

int escolha_arquivo(char *arq_1, char *arq_2){
  printf("Voce deseja qual arquivo?\n");
  int valor=0;
  while(valor < 1 || valor > 2){
  printf("1. %s\n", arq_1);
  printf("2. %s\n", arq_2);
  scanf("%d", &valor);
  }
  return valor;
}
