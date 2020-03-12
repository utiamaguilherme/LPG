#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

int main(void){
  int  op = 0, erro = 1;
  char *leitura_1 = 0, *leitura_2, *saida = 0;
  FILE *arquivo_um, *arquivo_saida, *arquivo_dois;
  printf("Hoje, a partir de agora voce estara utilizando o melhor programa! Comecaremos entao:\n");

  while(erro == 1){

      printf("Digite o nome do arquivo com '.' extensao do arquivo de entrada: ");
      leitura_1 = aloca_string();
      arquivo_um = fopen(leitura_1, "r");
      printf("%s\n", leitura_1);

      if(arquivo_um == NULL) {
          printf("ERRO: arquivo de entrada desconhecido - nome_do_arquivo.(o que estiver esolhido)\n");
      }

      else{
          printf("Digite o nome do arquivo com '.' extensao do arquivo dois: ");
          leitura_2 = aloca_string();
          arquivo_dois = fopen(leitura_2, "r");

          if(arquivo_dois == NULL)
              printf("ERRO: arquivo de entrada desconhecido - nome_do_arquivo.(o que estiver esolhido)\n");

          else
              erro = 0;
      }
    }
    printf("Digite o nome do arquivo com '.' extensao do arquivo saida: ");
    saida = aloca_string();
    arquivo_saida = fopen(saida, "a");

    ///////menu com as opções ao usuario escolher///////////
    while(op < 1 || op >7){
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
      menu(op,arquivo_um, arquivo_dois, arquivo_saida, leitura_1, leitura_2);
    }

  printf("Obrigado por utilizar nosso programa!\n");
  fclose(arquivo_um);
  fclose(arquivo_dois);
  fclose(arquivo_saida);
  return 0;
}
