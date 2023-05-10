

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#define M 3 
#define N 3 
//Matriz Transposta

// Matriz Conjugada

teste_conjugada() {
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
// matriz hermitiana




