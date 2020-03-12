//Trabalho : Implementacao de Matrizes Esparsas  || LPG0001
//Academicos: Enrique  -  BCC
//            Marisangila Alves -TADS
//Data: 28/06/2017
//_____________________________________________________________________________________________________________________
//*********************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//************************************Declaracao de Estruturas*********************************************************
typedef struct{
	int coluna;
	int valor;
}EntradaMatriz;

typedef struct{
	EntradaMatriz **m;
	int num_linhas;
	int num_colunas;
}MatrizEsparsa;
//********************************Declaracao de Funcaes*****************************************************************
int menu();
MatrizEsparsa carregar_matriz(FILE *arq);
void visualizar_matriz(MatrizEsparsa ME);
MatrizEsparsa modificar_matriz(MatrizEsparsa ME);
void salvar_matriz(FILE *arq, MatrizEsparsa ME);
MatrizEsparsa somar_matriz(MatrizEsparsa ME);
MatrizEsparsa subtrair_matriz(MatrizEsparsa ME);
MatrizEsparsa multiplicar_matriz(MatrizEsparsa ME);
//**********************************Funcoes Main*************************************************************************
int main(){
MatrizEsparsa ME;
int opcao, sair = 1;
opcao= menu();
char narq[100];
char narqs[100];
MatrizEsparsa imprimir;
char nomeArquivo[100];
int erro=0;
FILE *arq;
FILE *arqs;
//Tratamento das opções do menu

//opcao=menu();
do{
	opcao=menu();
    system("cls");
switch(opcao){
  case 1: // Carregar uma matriz

  	//strcpy(nomeArquivo, "");
  	do{
  		erro=0;
  	printf("Digite o nome do arquivo de entrada seguido da extensao\n");
		scanf("%s", narq);
		printf("Digite o nome do arquivo de saida seguido da extensao\n");
		scanf("%s", narqs);
		FILE *arq= fopen(narq, "rt"), *arqs = fopen(narqs, "wt"); //arquivos e /s
		if(arq == NULL){
			printf("Erro no carregamento do arquivo de entrada!\n");
			printf("\nDigite Novamente:\n");
			erro=1;
		}
		if(arqs == NULL){
			printf("Erro no carregamento do arquivo de saida!\n");
			printf("\nDigite Novamente:\n");
			erro=1;

		}
	}while(erro==1);
 		system("cls");
  		carregar_matriz(arq);
  		system("cls");
  		printf("DESEJA RETORNAR AO MENU PRINCIPAL?\n");
  		printf("Digite [1] para menu ou qualquer tecla  para sair.\n");
  		scanf("%i",&opcao);
  		break;
 	case 2: //Visualizar uma matriz
  		system("cls");
  		//visualizar_matriz(ME);
  		system("cls");
  		printf("DESEJA RETORNAR AO MENU PRINCIPAL?\n");
  		printf("Digite [1] para menu ou qualquer tecla para sair.\n");
  		scanf("%i",&opcao);
  		break;
 	case 3://Modificar uma matriz
  		//visualizar_matriz(ME);
  		//int lin_mm, col_mm, val_mm;
  		//printf("\n");
  		//printf("Insira a linha, coluna e o valor a ser inserido\n");
  		//scanf("%d %d %d", &lin_mm, &col_mm, &val_mm);
  		system("cls");
  		//imprimir=modificar_matriz(ME);
  		//visualizar_matriz(imprimir);
  		system("cls");
  		printf("DESEJA RETORNAR AO MENU PRINCIPAL?\n");
  		printf("Digite [1] para menu ou qualquer tecla  para sair.\n");
  		scanf("%i",&opcao);
  		break;
 	case 4://Salva uma matriz
 		system("cls");
    	//salvar_matriz(arqs, ME);
    	system("cls");
  		printf("DESEJA RETORNAR AO MENU PRINCIPAL?\n");
  		printf("Digite [1] para menu ou qualquer tecla  para sair.\n");
  		scanf("%i",&opcao);
    	break;
 	case 5://Soma uma matriz
		system("cls");
    	imprimir=somar_matriz(ME);
    	visualizar_matriz(imprimir);
    	system("cls");
  		printf("DESEJA RETORNAR AO MENU PRINCIPAL?\n");
  		printf("Digite [1] para menu ou qualquer tecla  para sair.\n");
  		scanf("%i",&opcao);
    	break;
 	case 6://Subtrai uma matriz
 		system("cls");
    	imprimir=subtrair_matriz(ME);
    	visualizar_matriz(imprimir);
    	system("cls");
  		printf("DESEJA RETORNAR AO MENU PRINCIPAL?\n");
  		printf("Digite [1] para menu ou qualquer tecla  para sair.\n");
  		scanf("%i",&opcao);
    	break;
 	case 7://Multiplica uma matroz - matroz ??
 		system("cls");
    	imprimir=multiplicar_matriz(ME);
    	visualizar_matriz(imprimir);
    	system("cls");
  		printf("DESEJA RETORNAR AO MENU PRINCIPAL?\n");
  		printf("Digite [1] para menu ou qualquer tecla  para sair.\n");
  		scanf("%i",&opcao);
    	break;
 	case 8://Encerra o programa
 	//	fclose(arq);
    //	fclose(arqs);
    //	free(ME.m);
    //	system ("exit");
    	system("cls");
  		printf("VOCE TEM CERTEZA QUE DESEJA SAIR DO PROGRAMA?\n");
  		printf("Digite [1] para menu ou qualquer tecla  para sair.\n");
  		scanf("%i",&opcao);
    	break;
	}


}while(opcao==1);
	system("cls");
    printf("Encerrando programa!");
    return 0;
}






//***********************************Escopo das Funcoes*********************************************************
//***********************************MENU***********************************************************************
int menu(){

int opcao;

while((opcao<=0)|| (opcao>8)){
	printf("  **********************************************\n");
	printf("  **                   MENU                   **\n");
	printf("  **********************************************\n");
	printf("  ** [1]-CARREGAR UMA MATRIZ:                 **\n");
	printf("  ** [2]-VISUALIZAR UMA MATRIZ:               **\n");
	printf("  ** [3]-MODIFICAR UMA MATRIZ:                **\n");
	printf("  ** [4]-SALVAR UMA MATRIZ:                   **\n");
	printf("  ** [5]-SOMA ENTRE MATRIZES:                 **\n");
	printf("  ** [6]-SUBTRACAO ENTRE MATRIZES:            **\n");
	printf("  ** [7]-MULTIPLICACAO ENTRE MATRIZES:        **\n");
	printf("  ** [8]-SAIR:                                **\n");
	printf("  **********************************************\n");

	printf("\n");
	printf("Digite o numero correspondente a uma das opcoes do menu:\n");
	scanf("%i",&opcao);
	system("cls");
    printf("Opcao invalida, digite novamente:\n");
    printf("\n");
    printf("\n");
};
return opcao;
}
//***********************************CARREGAR**********************************************************************
MatrizEsparsa carregar_matriz(FILE *arq){ //antes era inicializa_matriz
	int i, j, x, cont = 0;

	printf("CARREGAR MATRIZ\n");
	//variavel matrizesparsa matriz
	MatrizEsparsa ME;
	//FILE *f = fopen(nomeArquivo, "rb"); //r and w - read and write
    //rewind(f);
    //fscanf(arq, "%d %d", &ME->num_linhas, &ME->num_colunas);
    /* debug linhas e colunas
    printf("num de linhas %d / num de colunas %d\n", ME.num_linhas, ME.num_colunas);
    */
    ME.m = (EntradaMatriz**)malloc(sizeof(EntradaMatriz*)*ME.num_linhas); // _____ 1
		printf("%d aquiiiii \n", ME.num_linhas);
    for(i=0;i<ME.num_linhas;i++){
        for(j=0;j<ME.num_colunas;j++){
            fscanf(arq,"%d",&x);
            if(x!=0)
                cont++; //tam vet
        }
        ME.m[i] = (EntradaMatriz*)malloc(sizeof(EntradaMatriz)*cont);
        //printf("%d cont\n", x);
        cont = 0;
    }
    rewind(arq);
    fscanf(arq, "%d %d", &ME.num_linhas, &ME.num_colunas);
    for(i = 0; i < ME.num_linhas; i++){
    	for(j = 0; j < ME.num_colunas; j++){
            fscanf(arq, "%d", &x);
            if(x != 0){
                ME.m[i][cont].coluna = j;
                ME.m[i][cont].valor = x;
                cont++;
            }
        }
        if(cont>0){
        	ME.m[i] = (EntradaMatriz*)realloc(ME.m[i], sizeof(EntradaMatriz)*(cont)); // TESTAR
    		ME.m[i][cont].coluna = -1;
    		//printf("\n %d %d ", ME.m[i][cont].coluna, ME.m[i][cont].valor)   //debug coluna -1
        	cont = 0;
    	}
    }
    return ME;
}
//***********************************VIZUALIZAR**********************************************************************
void visualizar_matriz(MatrizEsparsa ME){
	int i, j, cont = 0;
	printf("VIZUALIZAR MATRIZ\n");
    system("cls");
    for(i = 0; i < ME.num_linhas; i++){
        for(j = 0; j < ME.num_colunas; j++){
            if(j == ME.m[i][cont].coluna){ //coluna > 0
                printf("%d ", ME.m[i][cont].valor);
                cont++;
            }
            else{
                printf("0 ");
                //printf("0 xablau ");
            }
        }
        printf("\n");
        cont = 0;
    }
    printf("\n__________________________________\n"); //quando chamada em outra func p n ficar colado
}
//***********************************MODIFICAR**********************************************************************
MatrizEsparsa modificar_matriz(MatrizEsparsa ME){
	int lin_mm,col_mm, val_mm; //entrada alt
	int i= 0,j= 0, cont= 0 ;// aux rept
	int aux = 0, maior_coluna, menor_coluna;
    int repete = 0; //
    system("cls");
    printf("MODIFICAR MATRIZ\n");
    while(repete != 1){
        maior_coluna = 0;
        menor_coluna = 0;
        cont = 0;
    	visualizar_matriz(ME);
        printf("Digite a linha, coluna, e o valor: ");
        scanf("%d\n%d\n%d", &lin_mm, &col_mm, &val_mm);
        for(i=0;i<ME.num_colunas;i++){
            if(ME.m[lin_mm][i].coluna == col_mm){ //verifica a coluna ja existe aux
                ME.m[lin_mm][i].valor = val_mm;
                aux = 1;
            }
        }
        if(aux != 1){
            for(i=0;i<ME.num_colunas; i++){ //verifica qual a menor/maior (valor) coluna da linha
                if(ME.m[lin_mm][i].valor != 0){
                    cont++;
            	}
                if(ME.m[lin_mm][i].coluna>maior_coluna){
                    maior_coluna = ME.m[lin_mm][i].coluna;
            	}
                if(ME.m[lin_mm][i].coluna<menor_coluna){
                    menor_coluna = ME.m[lin_mm][i].coluna;
            	}
            }
            ME.m[lin_mm] =(EntradaMatriz*) realloc(ME.m[lin_mm], sizeof(EntradaMatriz) * (cont + 1));
            if(col_mm<menor_coluna){
                for(i=cont; i>0;i--){
                	ME.m[lin_mm][i].coluna = ME.m[lin_mm][i-1].coluna;
                    ME.m[lin_mm][i].valor = ME.m[lin_mm][i-1].valor;
                }
            }
            else if(col_mm>menor_coluna &&col_mm<maior_coluna){
                for(i=cont;i>col_mm;i--){
                    ME.m[lin_mm][i].coluna = ME.m[lin_mm][i-1].coluna;
                    ME.m[lin_mm][i].valor = ME.m[lin_mm][i-1].valor;
                }
            }
            ME.m[lin_mm][col_mm].coluna = col_mm;
            ME.m[lin_mm][col_mm].valor = val_mm;
        }
		printf("/n ______________ NOVA ___________ /n");
        visualizar_matriz(ME);
        printf("Deseja voltar para o menu? 1- Sim 2- Nao:");
        scanf("%d", &repete);
    }
    return ME;
}
//***********************************SALVAR***************************************************************************
void salvar_matriz(FILE *arq, MatrizEsparsa ME){
	int i, j,cont = 0;
    system("cls");
    printf("SALVAR MATRIZ\n");
    fprintf(arq, "%d %d\n", ME.num_linhas, ME.num_colunas);
    for(i=0;i<ME.num_linhas; i++){ //cc de visualizar
        for(j = 0; j < ME.num_colunas; j++){
            if(j == ME.m[i][cont].coluna){
                fprintf(arq, "%d ", ME.m[i][cont].valor);
                cont++;
            }
            else{
                fprintf(arq, "0 ");
            }
        }
        fprintf(arq, "\n");
        cont = 0;
    }
    printf("Matriz salva com sucesso!");
}
//***********************************SOMAR***************************************************************************
MatrizEsparsa somar_matriz(MatrizEsparsa ME){
    MatrizEsparsa SME;
	char nm[100];
    int i, j, cont = 0;
    system("cls");
    printf("SOMAR MATRIZ\n");
    printf("Digite o nome do arquivo da matriz seguido da extensao\n");
    scanf("%s", nm);
    FILE *arq = fopen(nm, "rt");
    if(arq==NULL){
        printf("Erro\n");
    }
    SME = carregar_matriz(arq); // cc ---- reaproveitar
    if(SME.num_colunas!=ME.num_colunas||ME.num_linhas!=SME.num_linhas){
        printf("erro no nro de ln e col/n");
        return ME;
    }
    else{
        for(i = 0; i < ME.num_linhas; i++){
            for(j = 0; j < ME.num_colunas; j++){
                if(j == SME.m[i][cont].coluna){ // se encontrar coluna
                    if(ME.m[i][cont].coluna == j){ // se encontrar a mesma coluna
                        SME.m[i][cont].valor += ME.m[i][cont].valor; // sum(SME.v, ME.v)
                        cont++;
                    } else { // se n encontrar mesma coluna recebe valor da SME
                        SME.m[i][cont].valor += 0;
                        cont++;
                    }
                }
            }
            cont = 0;
        }
    }
    return SME;

}
//***********************************SUBTRAIR***************************************************************************
//pronto - testar
MatrizEsparsa subtrair_matriz(MatrizEsparsa ME){
	//cc soma
	MatrizEsparsa DME;
	char nm[100];
    int i, j, cont = 0;
    system("cls");
    printf("SUBTRAIR MATRIZ\n");
    printf("Digite o nome do arquivo da matriz seguido da extensao\n");
    scanf("%s", nm);
    FILE *arq = fopen(nm, "rt");
    if(arq==NULL){
        printf("Erro no arq\n");
    }
    DME = carregar_matriz(arq); // cc ---- reaproveitar
    if(DME.num_colunas!=ME.num_colunas||ME.num_linhas!=DME.num_linhas){
        printf("erro no nro de ln e col/n");
        return ME;
    }
    else{
        for(i = 0; i < ME.num_linhas; i++){
            for(j = 0; j < ME.num_colunas; j++){
                if(j == DME.m[i][cont].coluna){ // se encontrar coluna
                        DME.m[i][cont].valor += ME.m[i][cont].valor; // sum(-1)(SME.v, ME.v)
                        //DME.m[i][cont].valor *= -1;
                        //printf("%d %d ", DME.m[i][cont].coluna,DME.m[i][cont].valor) // até aq nao abriu um buraco negro
                        cont++;
                }
            }
            cont = 0;
        }
    }
    return DME;
}
//***********************************MULTIPLICAR***************************************************************************
MatrizEsparsa multiplicar_matriz(MatrizEsparsa ME){
	//cc soma
	MatrizEsparsa MME;
	MatrizEsparsa AUX;
	char nm[100];
    int i, j, cont = 0;
    int k =0;
    system("cls");
    printf("MULTIPLICAR MATRIZ\n");
    printf("Digite o nome do arquivo da matriz seguido da extensao\n");
    scanf("%s", nm);
    FILE *arq = fopen(nm, "rt");
    if(arq==NULL){
        printf("Erro no arq\n");
    }
    MME = carregar_matriz(arq); // cc ---- reaproveitar
    if(MME.num_colunas!=ME.num_linhas){
        printf("erro no nro de ln e col/n");
        return ME;
    } else {
        AUX.num_colunas = MME.num_colunas; //recebe col d arq e lin de ME
        AUX.num_linhas = ME.num_linhas;
        AUX.m = (EntradaMatriz**)malloc(sizeof(EntradaMatriz*)*MME.num_colunas);
        for(i=0;i<ME.num_linhas; i++){
            AUX.m[i] =(EntradaMatriz*) malloc(sizeof(EntradaMatriz)*ME.num_linhas);
        }
        for(i = 0; i < MME.num_colunas; i++){
            for(j = 0; j < ME.num_linhas; j++){
                AUX.m[i][j].valor = 0;
            }
        }
        for(i=0;i<MME.num_colunas; i++){
            for(j=0; j<ME.num_linhas; j++){
                AUX.m[cont][cont].valor += ME.m[i][j].valor * MME.m[j][i].valor;
                AUX.m[cont][cont].coluna=cont;
            }
            if(k == MME.num_colunas){
                cont++;
                k = 0;
            }
            else{
                k++;
            }
        }
    }
    return AUX;
}
//____________________________________________________________________________________________________________________
//**********************************FINAL*****************************************************************************
