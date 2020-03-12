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

void carregar(FILE *entrada_1, FILE *entrada_2, FILE *saida, char *arq_1, char *arq_2);
void visualizar(FILE *entrada_1, FILE *entrada_2, FILE *saida, char *arq_1, char *arq_2);
void modificar(FILE *entrada_1, FILE *entrada_2, FILE *saida, char *arq_1, char *arq_2);
void salvar(FILE *entrada_1, FILE *entrada_2, FILE *saida, char *arq_1, char *arq_2);
void somar(FILE *entrada_1, FILE *entrada_2, FILE *saida);
void subtrair(FILE *entrada_1, FILE *entrada_2, FILE *saida);
void multiplicar(FILE *entrada_1, FILE *entrada_2, FILE *saida);
void reescrita_w(FILE *entrada_1, FILE *entrada_2, FILE *saida);
void menu(int k, FILE *entrada_1, FILE *entrada_2, FILE *saida, char *arq_1, char *arq_2);
char *aloca_string();
int escolha_arquivo(char *arq_1, char *arq_2);

#endif
