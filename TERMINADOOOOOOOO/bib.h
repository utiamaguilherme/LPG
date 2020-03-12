#ifndef BIB_H
#define BIB_H

typedef struct{
  int coluna;
  float valor;
} EntradaMatriz;

typedef struct{
  EntradaMatriz **m;
  int num_linhas, num_colunas;
} MatrizEsparsa;

void carregar(FILE *arquivao, int n,MatrizEsparsa *a);
void visualizar(MatrizEsparsa *a,int n);
void modificar(MatrizEsparsa *a, int n);
void salvar(MatrizEsparsa *a, int n, FILE *saida);
void somar(MatrizEsparsa *a,FILE *saida);
void subtrair(MatrizEsparsa *a,FILE *saida);
void multiplicar(MatrizEsparsa *a,FILE *saida);
char *aloca_string();
int escolha_arquivo(char *arq_1, char *arq_2,int c);
int le_valor(MatrizEsparsa a, int i, int j);
int opcao_menu();
void func_free(MatrizEsparsa *a);
float modulo(float n);

#endif
