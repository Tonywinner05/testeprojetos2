//Matriz Transposta

#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 4
#include <time.h>

int** criar_matriz() {
	int i;
	int**m = (int**)malloc(M*sizeof(int));
	if(m==NULL){
		return 0;
	}
	for(i=0;i<M;i++){
		m[i]=(int*)malloc(N*sizeof(int));
		if(m[i]==NULL){
			return 0;
		}
	}
	return m;
}

 void preencher_matriz(int**m){
	int i,j;
	srand(time(NULL));
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			m[i][j]=rand() %50;
		}
	}

}

void mostrar_matriz(int **m){
	int i,j;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
	printf (" %d ",m[i][j]);
		}
	printf("\n");
	}
printf("\n");
}

//matriz_trasporta()
//desalocar_matriz()

int main(){

	int** matriz= criar_matriz();
	preencher_matriz(matriz);
	mostrar_matriz(matriz);
	return 0;
}

// Matriz Conjugada

#include <stdio.h>
#include <complex.h>
#define N 2

int main() {
    complex float matriz[N][N];

    // Lê a matriz complexa do usuário
    printf("Digite os elementos da matriz complexa (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float real, imag;
            printf("Real[%d][%d]: ", i+1, j+1);
            scanf("%f", &real);
            printf("Imag[%d][%d]: ", i+1, j+1);
            scanf("%f", &imag);
            matriz[i][j] = real + imag*I;
        }
    }

    // Calcula a matriz conjugada
    complex float conjugada[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            conjugada[i][j] = conj(matriz[i][j]);
        }
    }

    // Imprime as matrizes na tela
    printf("\nMatriz complexa:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.1f + %.1fi\t", creal(matriz[i][j]), cimag(matriz[i][j]));
        }
        printf("\n");
    }

    printf("\nMatriz conjugada:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.1f%.1fi\t", creal(conjugada[i][j]), cimag(conjugada[i][j]));
        }
        printf("\n");
    }

    return 0;
}


