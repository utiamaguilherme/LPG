#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

int main(void){
  int  op = 0, erro = 1,linha, coluna, n;
  char *leitura_1 = 0, *leitura_2, *saida = 0;
  FILE *arquivo_um, *arquivo_saida, *arquivo_dois;
  MatrizEsparsa a;
  printf("Hoje, a partir de agora voce estara utilizando o melhor programa! Comecaremos entao:\n");

  while(erro == 1){

      printf("Digite o nome do arquivo com '.' extensao do arquivo de entrada: ");
      leitura_1 = aloca_string();
      arquivo_um = fopen(leitura_1, "rt");

      if(arquivo_um == NULL) {
          printf("ERRO: arquivo de entrada desconhecido - nome_do_arquivo.(o que estiver esolhido)\n");
      }

      else{
          printf("Digite o nome do arquivo com '.' extensao do arquivo dois: ");
          leitura_2 = aloca_string();
          arquivo_dois = fopen(leitura_2, "rt");

          if(arquivo_dois == NULL)
              printf("ERRO: arquivo de entrada desconhecido - nome_do_arquivo.(o que estiver esolhido)\n");

          else
              erro = 0;
      }
    }
    printf("Digite o nome do arquivo com '.' extensao do arquivo saida: ");
    saida = aloca_string();
    arquivo_saida = fopen(saida, "at");

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
    switch(op){
      case 1:
      n = escolha_arquivo(leitura_1, leitura_2);
      // a = carregar(arquivao[n], n);
      int cont = 0, i, j;
      float valor_da_matriz;
        printf("CARREGANDO MATRIZ\n");
        if(n==1)
          fscanf(arquivo_um, "%d %d", &linha, &coluna);
        else
          fscanf(arquivo_dois, "%d %d", &linha, &coluna);
        printf("%d %d\n", linha, coluna);
        a.num_linhas = linha;
        a.num_colunas = coluna;
        printf("%d %d\n",a.num_linhas, a.num_colunas);
        a.m = calloc(sizeof(EntradaMatriz*), a.num_linhas);
        for(i = 0; i<a.num_linhas; i++){
          cont = 0;
          for(j = 0; j<a.num_colunas; j++){
            fscanf(arquivo_um, "%f", &valor_da_matriz);

            if(valor_da_matriz != 0){
              a.m[i] = realloc(a.m[i], sizeof(EntradaMatriz) * (cont+2));
              a.m[i][cont].coluna = j;
              a.m[i][cont].valor = valor_da_matriz;
              a.m[i][cont+1].coluna = -1;
              cont++;
            }
          }
        }

        break;

        case 2:
        visualizar(a);
        break;

        case 3:
        modificar(arquivo_um, n); // recebe as coordenadas;
        break;

        case 4:
        salvar(arquivo_um, n);
        break;

        case 5:
        somar(arquivo_um, arquivo_dois);
        break;

        case 6:
        subtrair(arquivo_um, arquivo_dois);
        break;

        case 7:
        multiplicar(arquivo_um, arquivo_dois);
        break;

        case 0:
        break;
      }
    }

  printf("Obrigado por utilizar nosso programa!\n");
  fclose(arquivo_um);
  fclose(arquivo_dois);
  fclose(arquivo_saida);
  return 0;
}
