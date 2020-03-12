#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

int main(void){
  int  op = 10, erro = 1, n = 0;
  char *leitura_1 = 0, *leitura_2 = 0, *saida = 0;
  FILE *arquivo_um, *arquivo_saida, *arquivo_dois;
  MatrizEsparsa a[3];

  printf("Hoje, a partir de agora voce estara utilizando o melhor programa! Comecaremos entao:\n");

  while(erro == 1){

      printf("Digite o nome do arquivo com '.' extensao do arquivo de entrada: ");
      leitura_1 = aloca_string();
      arquivo_um = fopen(leitura_1, "rt");

      if(arquivo_um == NULL) {
          printf("ERRO: arquivo de entrada desconhecido - nome_do_arquivo.(o que estiver esolhido)\n");
      }else{
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
    while(op < 0 || op >7){
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
    if(op >= 0 && op < 8)
		switch(op){

		  ///////////////////////////////////////////
	    ////////////GRAVAR MATRIZ /////////////////
	    ///////////////////////////////////////////

			case 1:
			n = escolha_arquivo(leitura_1, leitura_2,1);
			if(n!=-1)//-1 para voltar ao menu
			{
				if(n==2){//carregar os 2
					carregar(arquivo_um, 0,a);
					carregar(arquivo_dois, 1,a);
				}

				else{//selecionar um dos dois
					if(n==0)
						carregar(arquivo_um, n,a);
					else
						carregar(arquivo_dois, n,a);
				}

				op = opcao_menu();
			}
			// else
			// 	op = 10;//continuar no loop do menu
			break;

		    ///////////////////////////////////////////
        ////////////VISUALIZAR MATRIZ /////////////
        ///////////////////////////////////////////

		    case 2:
		    n = escolha_arquivo(leitura_1, leitura_2,1);
		    if(n!=-1)
			{
			    if(n==2){//visualizar os 2
			    	visualizar(a,0);
			    	visualizar(a,1);
			    }
			    else//visualizar o escolhido
			    	visualizar(a,n);
			    op = opcao_menu();
			}
			// else
			// 	op = 10;//continuar no loop do menu
		    break;

		     ///////////////////////////////////////////
        ////////////MODIFICAR MATRIZ //////////////
       ///////////////////////////////////////////

		    case 3:
		    n = escolha_arquivo(leitura_1, leitura_2,0);
		    if(n!=-1)
			{
		        modificar(a,n);
		        op = opcao_menu();
	        }
			// else
			// 	op = 10;//continuar no loop do menu
		    break;

		     ///////////////////////////////////////////
        ////////////SALVAR MATRIZ /////////////////
       ///////////////////////////////////////////

		    case 4:
		    n = escolha_arquivo(leitura_1, leitura_2,0);
		    if(n!=-1)
			{
		        salvar(a, n, arquivo_saida);
		        op = opcao_menu();
	        }
			// else
			// 	op = 10;//continuar no loop do menu
		    break;

		     ///////////////////////////////////////////
        ////////////SOMAR MATRIZES ////////////////
       ///////////////////////////////////////////

		    case 5:
			somar(a,arquivo_saida);
			op = opcao_menu();

		    break;

		     ///////////////////////////////////////////
        ////////////SUBTRAIR MATRIZES /////////////
       ///////////////////////////////////////////

		    case 6:
			subtrair(a,arquivo_saida);
			op = opcao_menu();
		    break;

		      ///////////////////////////////////////////
         ////////////MULTIPLICAR MATRIZES //////////
        ///////////////////////////////////////////

		    case 7:
			multiplicar(a,arquivo_saida);
			op = opcao_menu();
		    break;

		      ///////////////////////////////////////////
         ////////////NAO FAZER NADA ////////////////
        ///////////////////////////////////////////

		    case 0:
		    break;
		}
  }
  func_free(a);
  if(a[0].m == NULL)
    printf("certo\n");
  else
    printf("ferrou\n");
  printf("Obrigado por utilizar nosso programa!\n");
  fclose(arquivo_um);
  fclose(arquivo_dois);
  fclose(arquivo_saida);
  return 0;
}
