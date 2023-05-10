

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#define N 3 

//Matriz Transposta

void teste_transposta(int *matrix) {
    int temp;
    int i,j;
    for(i = 0; i < N; i++) {
        for( j = i+1; j < N; j++) {
            temp = *(matrix + i*N + j);  // Armazena o elemento a ser trocado
            *(matrix + i*N + j) = *(matrix + j*N + i);  // Move o elemento da posição (j,i) para (i,j)
            *(matrix + j*N + i) = temp;  // Move o elemento armazenado para a posição (j,i)
        }
    }
}

// Matriz Conjugada

void teste_conjugada(){
	
}
// matriz hermitiana
void teste_hermitiana(){
	
}

// soma de matrizes 
void teste_soma(){
}

// subtração de matrizes
void teste_sub(){
}
// produto escalar
void teste_produto_escalar(){
	
	
}
// produto matricial
void teste_produto_matricial(){

}
// execução de todas as matrizes
teste_todos(){

}



int main() {
	int matriz[N][N];
    int i, j;
    int escolha;
    printf("Digite os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            }
        }
        
    printf("Escolha a manipulação matricial de 3x3 que deseja executar:\n");
    printf("1. matriz trasposta \n");
    printf("2. matriz conjugada \n");
    printf("3. matriz hermitiana \n");
    printf("4. soma de matrizes  \n");
    printf("5. subtração de matrizes \n");
    printf("6. produto escalar \n");
    printf("7. produto matrcial \n");
    printf("8. todas \n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
        teste_transposta(&matriz[N][N]);
	    printf("Matriz trasposta:\n");
   		for( i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    	}
        break;
        case 2:
            teste_conjugada();
            break;
        case 3:
            teste_hermitiana();
            break;
        case 4:
            teste_soma();
            
            break;
        case 5:
            teste_sub();
            break;
        case 6:
        teste_produto_escalar();
            break;
        case 7:
           teste_produto_matricial();
            break;
        case 8:
           teste_todos();
            break;
        default:
            printf("Opção inválida!\n");
            break;
}

	printf("Matriz original:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}






