#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

///////////////////////////////////////////
/////////////FUNCOES///////////////////////
///////////////////////////////////////////

void carregar(FILE *arquivao, int n,MatrizEsparsa *a){
  int cont = 0, i, j, linha, coluna;
  float valor_da_matriz;
    printf("CARREGANDO MATRIZ %d\n",n+1);
	    fscanf(arquivao, "%d %d", &linha, &coluna);
	    // printf("%d %d\n", linha, coluna);
	if(a[n].num_colunas){
		printf("ESSA MATRIZ JA FOI CARREGADA\n\n");
	}else{
	    a[n].num_linhas = linha;
	    a[n].num_colunas = coluna;
	    a[n].m = calloc(sizeof(EntradaMatriz*), linha);
	    for(i = 0; i<linha; i++){
	      cont = 0;
	      a[n].m[i] = calloc(sizeof(EntradaMatriz), coluna);
	      a[n].m[i] = NULL;
	      for(j = 0; j<coluna; j++){
	        fscanf(arquivao, "%f", &valor_da_matriz);
	        if(valor_da_matriz != 0){
	          cont++;
	          a[n].m[i] = realloc(a[n].m[i], sizeof(EntradaMatriz) * (coluna + 1) );
	          a[n].m[i][cont-1].coluna = j;
	          a[n].m[i][cont-1].valor = valor_da_matriz;
	          a[n].m[i][cont].coluna = -1;
	        }
	      }
	    }
	    printf("Linhas: %d Colunas: %d\n", linha, coluna);
		for(i=0;i<a[n].num_linhas;i++){
			printf("| ");
			for(j=0;j<a[n].num_colunas;j++){
	     		 int x=le_valor(a[n],i,j);//dada a matriz e a cordenada ele retorna o valor
	     		 printf("%d ",x);
			}
	   	   printf("|\n");
		}
		printf("MATRIZ CARREGADA COM SUCESSO\n\n");
	}
}
void visualizar(MatrizEsparsa *a,int n){
	int i,j;
  // float maior = 0, teste;
	if(a[n].num_colunas){
    /*for(i=0; i<a[n].num_linhas; i++){
      for(j=0; j<a[n].num_colunas; j++){
        teste = modulo(teste);
        if(maior < teste)
          maior = a[n].m[i][j].valor;
      }
    }*/
		printf("Matriz: %d\n",n+1);
		printf("Linhas: %d Colunas: %d\n", a[n].num_linhas, a[n].num_colunas);
		for(i=0;i<a[n].num_linhas;i++){
			printf("| ");
			for(j=0;j<a[n].num_colunas;j++){
	 			 int x=le_valor(a[n],i,j);//dada a matriz e a cordenada ele retorna o valor
	 			 printf("%d\t ", x);
			}
			printf("|\n");
		}
		printf("\n");
	}else
		printf("ESSA MATRIZ PRECISA SER CARREGADA\n\n");
}


void modificar(MatrizEsparsa *a, int n){
	int linha, coluna;
	int aux;
	if(a[n].num_colunas){
		printf("Modificando Matriz\n");
		printf("Quais sao as coordenadas?\nPrimeiro a linha, logo em seguida a coluna\n");
		scanf("%d %d", &linha, &coluna);
		// a = modificar(a, linha, coluna);// recebe as coordenadas;
		printf("Qual valor ira querer modificar na matriz?\n");
		scanf("%d", &aux);
		// a.m[linha-1][coluna-1].valor = aux;
		a[n].m[linha-1] = realloc(a[n].m[linha-1], sizeof(EntradaMatriz) * (a[n].num_colunas + 1));
		a[n].m[linha-1][coluna-1].coluna = coluna-1;
		a[n].m[linha-1][coluna-1].valor = aux;
		a[n].m[linha-1][coluna].coluna = -1;
		printf("\nMatriz alterada com sucesso\n");
	}else
		printf("ESSA MATRIZ PRECISA SER CARREGADA\n\n");

}

void salvar(MatrizEsparsa *a, int n, FILE *saida){
	int i,j,x;
	if(a[n].num_colunas){
		fprintf(saida, "%d %d\n", a[n].num_linhas,a[n].num_colunas);
		for(i=0;i<a[n].num_linhas;i++){
			for(j=0;j<a[n].num_colunas;j++){
				x=le_valor(a[n],i,j);//dada a matriz e a cordenada ele retorna o valor
				fprintf(saida ,"%d ", x);
			}
			fprintf(saida, "\n");
		}
		printf("MATRIZ SALVA COM SUCESSO\n\n");
	}
	else
		printf("ESSA MATRIZ ESTA NAO FOI CARREGADA\n\n");
}

void somar(MatrizEsparsa *a,FILE *saida){
	int i,j,x,y,cont;
	if(a[0].num_colunas && a[1].num_colunas){
		if(a[0].num_linhas==a[1].num_linhas && a[0].num_colunas==a[1].num_colunas){
			/*a[2].m = malloc(sizeof(int)*a[0].num_linhas);
			for(i=0;i<a[0].num_linhas;i++)
				a[2].m[i] = malloc(sizeof(int)*a[0].num_colunas);*/
			a[2].num_linhas= a[0].num_linhas;
			a[2].num_colunas = a[0].num_colunas;
			a[2].m = calloc(sizeof(EntradaMatriz*), a[2].num_linhas);
			for(i=0;i<a[2].num_linhas;i++){
				cont = 0;
				a[2].m[i] = calloc(sizeof(EntradaMatriz), a[2].num_colunas);
			    a[2].m[i] = NULL;
				for(j=0;j<a[2].num_colunas;j++){
		      		x=le_valor(a[0],i,j);
		      		y=le_valor(a[1],i,j);
              cont++;
		      		if(x+y != 0){

			      		a[2].m[i] = realloc(a[2].m[i], sizeof(EntradaMatriz) * (a[2].num_colunas + 1));
			      		a[2].m[i][cont-1].coluna = j;
			     	 	a[2].m[i][cont-1].valor = x+y;
			      		a[2].m[i][cont].coluna = -1;
			     	}
		      	}
			}
			printf("\nResultado da soma:\n");
			printf("Linhas: %d Colunas: %d\n", a[2].num_linhas, a[2].num_colunas);
			for(i=0;i<a[2].num_linhas;i++){
				printf("| ");
				for(j=0;j<a[2].num_colunas;j++){
		     		 int x=le_valor(a[2],i,j);//dada a matriz e a cordenada ele retorna o valor
		     		 printf("%d ",x);
				}
		   	   printf("|\n");
			}
			printf("\nDeseja salvar o resultado?\n1. Salvar\n(Qualquer outra tecla sair)\n");
			int save;
			scanf("%d",&save);
			if(save==1){
				salvar(a,2,saida);
			}

		}else{
			printf("\nAs matrizes precisam ter o mesmo numero de linhas e colunas\n\n");
		}
	}
	else
		printf("\nUMA OU AS DUAS MATRIZES NAO FORAM CARREGADAS\n\n");
}

void subtrair(MatrizEsparsa *a,FILE *saida){
	int i,j,x,y,cont;
	if(a[0].num_colunas && a[1].num_colunas){
		if(a[0].num_linhas==a[1].num_linhas && a[0].num_colunas==a[1].num_colunas){
			a[2].num_linhas= a[0].num_linhas;
			a[2].num_colunas = a[0].num_colunas;
			a[2].m = calloc(sizeof(EntradaMatriz*), a[2].num_linhas);
			for(i=0;i<a[2].num_linhas;i++){
				cont = 0;
				a[2].m[i] = calloc(sizeof(EntradaMatriz), a[2].num_colunas);
			    a[2].m[i] = NULL;
				for(j=0;j<a[2].num_colunas;j++){
		      		x=le_valor(a[0],i,j);
		      		y=le_valor(a[1],i,j);
              cont++;
		      		if(x-y != 0){

			      		a[2].m[i] = realloc(a[2].m[i], sizeof(EntradaMatriz) * (a[2].num_colunas + 1));
			      		a[2].m[i][cont-1].coluna = j;
			     	 	a[2].m[i][cont-1].valor = x-y;
			      		a[2].m[i][cont].coluna = -1;
			     	}
		      	}
			}
			printf("\nResultado da subtracao:\n");
			printf("Linhas: %d Colunas: %d\n", a[2].num_linhas, a[2].num_colunas);
			for(i=0;i<a[0].num_linhas;i++){
				printf("| ");
				for(j=0;j<a[0].num_colunas;j++){
		     		 int x=le_valor(a[2],i,j);//dada a matriz e a cordenada ele retorna o valor
		     		 printf("%d ",x);
				}
		   	   printf("|\n");
			}
			printf("\nDeseja salvar o resultado?\n1. Salvar\n(Qualquer outra tecla sair)\n");
			int save;
			scanf("%d",&save);
			if(save==1){
				salvar(a,2,saida);
			}
		}else{
			printf("\nAs matrizes precisam ter o mesmo numero de linhas e colunas\n\n");
		}
	}
	else
		printf("\nUMA OU AS DUAS MATRIZES NAO FORAM CARREGADAS\n\n");
}

void multiplicar(MatrizEsparsa *a,FILE *saida){
	int i,j,x,y,k,aux,t,cont;
	if(a[0].num_colunas && a[1].num_colunas){
		if(a[0].num_colunas==a[1].num_linhas){
			a[2].num_linhas = a[0].num_linhas;
			a[2].num_colunas = a[1].num_colunas;
			/*a[2].m = malloc(sizeof(int)*a[2].num_linhas);
			for(i=0;i<a[2].num_linhas;i++)
				a[2].m[i] = malloc(sizeof(int)*a[2].num_colunas);*/

			a[2].m = calloc(sizeof(EntradaMatriz*), a[2].num_linhas);
			for(i=0;i<a[2].num_linhas;i++){
				cont = 0;
				a[2].m[i] = calloc(sizeof(EntradaMatriz), a[2].num_colunas);
			    a[2].m[i] = NULL;

				for(j=0;j<a[2].num_colunas;j++){
	                 for(k=0; k<a[0].num_colunas; k++){
	                 	x=le_valor(a[0],i,k);
		      			y=le_valor(a[1],k,j);
	                    aux += x * y;
	                 }
	                 if(aux != 0){
			     	 	cont++;
			      		a[2].m[i] = realloc(a[2].m[i], sizeof(EntradaMatriz) * (a[2].num_colunas + 1));
			      		a[2].m[i][cont-1].coluna = j;
			     	 	a[2].m[i][cont-1].valor = aux;
			      		a[2].m[i][cont].coluna = -1;
			     	}
	                 aux=0;
		      	}
			}
			printf("\nResultado da multiplicacao:\n");
			printf("Linhas: %d Colunas: %d\n", a[2].num_linhas, a[2].num_colunas);
			for(i=0;i<a[2].num_linhas;i++){
				printf("| ");
				for(j=0;j<a[2].num_colunas;j++){
		     		 t=le_valor(a[2],i,j);//dada a matriz e a cordenada ele retorna o valor
		     		 printf("%d ",t);
				}
		   	   printf("|\n");
			}
			printf("\nDeseja salvar o resultado?\n1. Salvar\n(Qualquer outra tecla sair)\n");
			int save;
			scanf("%d",&save);
			if(save==1){
				salvar(a,2,saida);
			}
		}else{
			printf("O numero de colunas da matriz 1 tem que ser igual o numero de linhas da matriz 2\n\n");
		}
	}
	else
		printf("\nUMA OU AS DUAS MATRIZES NAO FORAM CARREGADAS\n\n");
}

char *aloca_string(){
	char buffer[101], *leitura=NULL;
	fgets(buffer,100,stdin);
	leitura = malloc(sizeof(char)*(strlen(buffer)+1));
	strcpy(leitura,buffer);
	leitura[strlen(leitura)-1] = '\0';
	return leitura;
}

int escolha_arquivo(char *arq_1, char *arq_2,int c){
	printf("Voce deseja manipular qual arquivo/matriz?\n");
	int valor=5;
	if(c==1)
		while(valor < 0 || valor > 3){
			printf("1. %s\n", arq_1);
			printf("2. %s\n", arq_2);
			printf("3. Os dois\n");
			printf("0. Voltar ao menu\n");
			scanf("%d", &valor);
			return valor-1;
		}
	else
		while(valor < 0 || valor > 2){
			printf("1. %s\n", arq_1);
			printf("2. %s\n", arq_2);
			printf("0. Voltar ao menu\n");
			scanf("%d", &valor);
		}
		return valor-1;
}

int le_valor(MatrizEsparsa a, int i, int j) {
  int x;
  if(a.m[i] == NULL)
  return 0;
  else{
    x = a.m[i][j].valor;
    return x;
  }
}

int opcao_menu(){

  printf("Pressione enter para voltar ao menu\n");
  fpurge(stdin);
  getchar();
  return 10;
}

void func_free(MatrizEsparsa *a){
  int i,j;
  for(i=0; i<3; i++){

      if(a[i].m != NULL){

        for(j=0; j<a[i].num_colunas; j++){
        	free(a[i].m[j]);

        }

        free(a[i].m);
      }
    }
  }

float modulo(float n)
{
  if(n < 0){
    n*=(-1);
  }
  return n;
}
