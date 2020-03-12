#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

int main(void){
  int  op = 2, erro = 1;
  char *leitura_1 = 0, *leitura_2, *saida = 0;
  FILE *arquivao[3];
  printf("Hoje, a partir de agora voce estara utilizando o melhor programa! Comecaremos entao:\n");

  while(erro == 1){

      printf("Digite o nome do arquivo com '.' extensao do arquivo de entrada: ");
      leitura_1 = aloca_string();
      arquivao[0] = fopen(leitura_1, "rt");

      if(arquivao[0] == NULL) {
          printf("ERRO: arquivo de entrada desconhecido - nome_do_arquivo.(o que estiver esolhido)\n");
      }

      else{
          printf("Digite o nome do arquivo com '.' extensao do arquivo dois: ");
          leitura_2 = aloca_string();
          arquivao[1] = fopen(leitura_2, "rt");

          if(arquivao[1] == NULL)
              printf("ERRO: arquivo de entrada desconhecido - nome_do_arquivo.(o que estiver esolhido)\n");

          else
              erro = 0;
      }
    }
    printf("Digite o nome do arquivo com '.' extensao do arquivo saida: ");
    saida = aloca_string();
    arquivao[2] = fopen(saida, "at");
    MatrizEsparsa a;

    int n = 0;
    ///////menu com as opções ao usuario escolher///////////
    while(op > 1 || op < 8){
    system("clear");
    printf("Ola! O que voce deseja?\n");
    printf("1. Carregar uma matriz do arquivo\n");
    printf("2. Visualizar uma matriz\n");
    printf("3. Modificar uma matriz, dando as coordenadas de linha e coluna\n");
    printf("4. Salvar uma matriz\n");
    printf("5. Soma entre matrizes\n");
    printf("6. Subtracao entre matrizes\n");
    printf("7. Multiplicacao entre matrizes\n");
    printf("0. Sair do programa\n");
    scanf("%d", &op);
    if(op > 0 && op < 8)
    switch(op){
      case 1:
      n = escolha_arquivo(leitura_1, leitura_2);
      // a = carregar(arquivao[n], n);
      int cont = 0, i, j;
      float valor_da_matriz;
        printf("CARREGANDO MATRIZ\n");
        rewind(arquivao[n]);
        fscanf(arquivao[n], "%d %d", &a.num_linhas, &a.num_colunas);
        printf("%d %d", a.num_linhas, a.num_colunas);
        a.m = malloc
        for(i = 0; i<a.num_linhas; i++){
          for(j = 0; j<a.num_colunas; j++){

            fscanf(arquivao[n], "%f", &valor_da_matriz);

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

      break;

      case 2:
      visualizar(a);
      break;

      case 3:
      modificar(arquivao[n], n); // recebe as coordenadas;
      break;

      case 4:
      salvar(arquivao[n], n);
      break;

      case 5:
      somar(arquivao[0], arquivao[1]);
      break;

      case 6:
      subtrair(arquivao[0], arquivao[1]);
      break;

      case 7:
      multiplicar(arquivao[0], arquivao[1]);
      break;

      case 0:
      break;
    }
  }

  printf("Obrigado por utilizar nosso programa!\n");
  for(int i=0; i<3; i++)
    fclose(arquivao[i]);
  return 0;
}
