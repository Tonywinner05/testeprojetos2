

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#define N 3 
//Matriz Transposta
teste_trasposta(){
	
	void transpose(int mat1[N][N]) {
    int transposed[N][N];
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            transposed[i][j] = mat1[j][i];
        }
    }

    printf("Matriz transposta:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    	}
	}
}
// Matriz Conjugada

teste_conjugada(){
	
    void conjugade()
	complex float matriz[N][N];
 	int i, j;
    // LÃª a matriz complexa do usuÃ¡rio
    
    
    matriz[i][j] = real + imag*I;
    // Calcula a matriz conjugada
    complex float conjugada[N][N];
    for ( i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            conjugada[i][j] = conj(matriz[i][j]);
        }
    }

    // Imprime as matrizes na tela
    printf("\nMatriz complexa:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%.1f + %.1fi\t", creal(matriz[i][j]), cimag(matriz[i][j]));
        }
        printf("\n");
    }

    printf("\nMatriz conjugada:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%.1f%.1fi\t", creal(conjugada[i][j]), cimag(conjugada[i][j]));
        }
        printf("\n");
    }

    return 0;
}
// matriz hermitiana
teste_hermitiana(){
	
}

// soma de matrizes 
teste_soma(){
}

// subtração de matrizes
teste_sub(){
}
// produto escalar
teste_produto_escalar(){
}
// produto matricial
teste_produto_matricial(){

}
// execução de todas as matrizes
teste_todos(){

}



int main() {
	int mat[N][N];
    int i, j;
    int escolha;
    printf("Digite os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
            }
        }
        
    printf("Escolha a manipulação matricial de 3x3 que deseja executar:\n");
    printf("1. matriz trasposta \n");
    printf("2. matriz conjugada \n");
    printf("3. matriz hermitian \n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            teste_trasposta();
            break;
        case 2:
            teste_conjugada();
            break;
        case 3:
            teste_soma();
            break;
        default:
            printf("Opção inválida!\n");
            break;
}

	printf("Matriz original:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}






