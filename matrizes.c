#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_linalg.h>


typedef struct {
    double Re;
    double Im;
} Complex;


void impC(Complex c){
    printf("%.1f", c.Re);
    if (c.Im >= 0) {
        printf(" + %.1fi", c.Im);
    } else {
        printf(" - %.1fi", -c.Im);
    }
}

// função para imprimir a matriz
void printComplexMatrix(Complex *matrix, int L, int C) {
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            impC(matrix[i * C + j]);
            printf("\t");
        }
        printf("\n");
    }
}
// Função para imprimir uma matriz complexa
Complex conjugado(Complex c) {
    Complex resultado;
    resultado.Re = c.Re;
    resultado.Im = -c.Im; // troca o sinal da parte imaginária
    return resultado;
}
void calc_svd(Complex *mat, int L, int C, Complex **U, Complex **S, Complex **V) {
    gsl_matrix_complex *A = gsl_matrix_complex_alloc(L, C);

    // Preenche a matriz A com os valores da matriz de entrada
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            gsl_complex z = gsl_complex_rect(mat[i * C + j].Re, mat[i * C + j].Im);
            gsl_matrix_complex_set(A, i, j, z);
        }
    }

    // Aloca espa�o para as matrizes U, S e V
    gsl_matrix_complex *U_gsl = gsl_matrix_complex_alloc(L, L);
    gsl_vector_complex *S_gsl = gsl_vector_complex_alloc(C);
    gsl_matrix_complex *V_gsl = gsl_matrix_complex_alloc(C, C);

    // Calcula a SVD usando a biblioteca GSL
    gsl_vector *work = gsl_vector_alloc(C);
    gsl_linalg_SV_decomp(A, V_gsl, S_gsl, work);
    gsl_linalg_SV_decomp_U(A, U_gsl, S_gsl, V_gsl, work);

    // Copia os valores das matrizes U, S e V de volta para as estruturas Complex
    *U = (Complex *)malloc(L * L * sizeof(Complex));
    *S = (Complex *)malloc(C * sizeof(Complex));
    *V = (Complex *)malloc(C * C * sizeof(Complex));

    for (i = 0; i < L; i++) {
        for (j = 0; j < L; j++) {
            gsl_complex z = gsl_matrix_complex_get(U_gsl, i, j);
            (*U)[i * L + j].Re = GSL_REAL(z);
            (*U)[i * L + j].Im = GSL_IMAG(z);
        }
    }

    for (i = 0; i < C; i++) {
        gsl_complex z = gsl_vector_complex_get(S_gsl, i);
        (*S)[i].Re = GSL_REAL(z);
        (*S)[i].Im = GSL_IMAG(z);
    }

    for (i = 0; i < C; i++) {
        for (j = 0; j < C; j++) {
            gsl_complex z = gsl_matrix_complex_get(V_gsl, i, j);
            (*V)[i * C + j].Re = GSL_REAL(z);
            (*V)[i * C + j].Im = GSL_IMAG(z);
        }
    }

    // Libera a mem�ria alocada
    gsl_matrix_complex_free(A);
    gsl_matrix_complex_free(U_gsl);
    gsl_vector_complex_free(S_gsl);
    gsl_matrix_complex_free(V_gsl);
    gsl_vector_free(work);
}

void teste_calc_svd(int L, int C) {
    Complex *mat = (Complex *)malloc(L * C * sizeof(Complex));
    Complex *U, *S, *V;

    // Gera a matriz de entrada aleatoriamente
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            mat[i * C + j] = (Complex){(double)rand() / RAND_MAX, (double)rand() / RAND_MAX};
        }
    }

    printf("Matriz original %dx%d:\n", L, C);
    printComplexMatrix(mat, L, C);
    printf("\n");

    printf("Realizando c�lculo da SVD...\n\n");

    calc_svd(mat, L, C, &U, &S, &V);

    printf("Matriz U:\n");
    printComplexMatrix(U, L, L);
    printf("\n");

    printf("Vetor S:\n");
    printComplexMatrix(S, 1, C);
    printf("\n");

    printf("Matriz V:\n");
    printComplexMatrix(V, C, C);
    printf("\n");

    // Libera a mem�ria alocada
    free(mat);
    free(U);
    free(S);
    free(V);
}





// Matriz Transposta
void teste_transposta(Complex *mat, int L, int C) {
	int i,j;
	for ( i = 0; i < L; i++) {
        for ( j = i + 1; j < C; j++) {
            Complex temp = *(mat + i * C + j);
            *(mat + i * C + j) = *(mat + j * C + i);
            *(mat + j * C + i) = temp;
        }
    }
}
// Matriz Conjugada
void teste_conjugada(Complex *mat, int L, int C) {
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            mat[i * C + j] = conjugado(mat[i * C + j]);
        }
    }
}
// matriz hermitiana
void teste_hermitiana(Complex *mat,Complex *result, int L, int C) {
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            result[i * C + j] = conjugado(mat[j * C + i]);
        }
    }
}
// soma de matrizes
void teste_soma(Complex *mat, Complex *mat2, Complex *result, int L, int C) {
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
        result[i * C + j].Re = mat[i * C + j].Re + mat2[i * C + j].Re; // Realiza a Soma da parte Real
        result[i * C + j].Im = mat[i * C + j].Im + mat2[i * C + j].Im; // Realiza a Soma da parte imaginária
        }
    }
}

// subtração de matrizes
void teste_subtracao(Complex *mat, Complex *mat2, Complex *result, int L, int C) {
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
        result[i * C + j].Re = mat[i * C + j].Re - mat2[i * C + j].Re; // Realiza a Soma da parte Real
        result[i * C + j].Im = mat[i * C + j].Im - mat2[i * C + j].Im; // Realiza a Soma da parte imaginária
        }
    }
}

// produto escalar
void teste_produto_escalar(Complex *mat, Complex *mat2, int L, int C, Complex *resultado) {
    resultado->Re = 0;
    resultado->Im = 0;
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            Complex elem1 = mat[i * C + j];
            Complex elem2 = mat2[i * C + j];
            Complex prod = {elem1.Re * elem2.Re - elem1.Im * elem2.Im, elem1.Re * elem2.Im + elem1.Im * elem2.Re};
            resultado->Re += prod.Re;
            resultado->Im += prod.Im;
        }
    }
}
// produto matricial
void produtoMatricial(Complex *mat1, Complex *mat2, Complex *result, int L, int C) {
    int i, j, k;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            result[i * C + j].Re = 0;
            result[i * C + j].Im = 0;
            for (k = 0; k < C; k++) {
                Complex elem1 = mat1[i * C + k];
                Complex elem2 = mat2[k * C + j];
                Complex prod = {elem1.Re * elem2.Re - elem1.Im * elem2.Im, elem1.Re * elem2.Im + elem1.Im * elem2.Re};
                result[i * C + j].Re += prod.Re;
                result[i * C + j].Im += prod.Im;
            }
        }
    }
}
// execução de todas as matrizes
void teste_todos(){
    int L = 3;
    int C = 3;

    Complex *mat = (Complex *)malloc(L * C * sizeof(Complex));
    Complex *mat2 = (Complex *)malloc(L * C * sizeof(Complex));
    Complex *result = (Complex *)malloc(L * C * sizeof(Complex));

    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            *(mat + i * C + j) = (Complex){i + j, i - j};
            *(mat2 + i * C + j) = (Complex){i - j, i + j};
        }
    }

    printf("Matriz original 3x3:\n");
    printComplexMatrix(mat, L, C);
    printf("\n");

    printf("Segunda matriz 3x3:\n");
    printComplexMatrix(mat2, L, C);
    printf("\n");
    printf("1. Matriz transposta\n");
    teste_transposta(mat, L, C);
    printf("\n");
    printf("Matriz transposta:\n");
    printComplexMatrix(mat, C, L);
    printf("\n");
    free(mat);
    printf("2. Matriz conjugada\n");
    teste_conjugada(mat, L, C);
    printf("\n");
    printf("Matriz conjugada:\n");
    printComplexMatrix(mat, L, C);
    printf("\n");
    free(mat);

    printf("3. Matriz hermitiana\n");
    teste_hermitiana(mat,result, L, C);
    printComplexMatrix(result, L, C);
    printf("\n");
    free(mat);

    printf("4. Soma de matrizes\n");
    teste_soma(mat, mat2, result, L, C);
    printf("Matriz soma:\n");
    printComplexMatrix(result, L, C);
    printf("\n");

    printf("5. Subtracao de matrizes\n");
    teste_subtracao(mat, mat2, result, L, C);
    printf("Matriz subtracao:\n");
    printComplexMatrix(result, L, C);
    printf("\n");

    printf("6. Produto escalar\n");
    printf("Segunda matriz 3x3:\n");
    printComplexMatrix(mat2, L, C);
    printf("\n");
    Complex resultado;
    teste_produto_escalar(mat, mat2, L, C, &resultado);
    printf("Produto escalar: ");
    impC(resultado);
    printf("\n");

    printf("7. Produto matricial\n");
    printf("Segunda matriz 3x3:\n");
    printComplexMatrix(mat2, L, C);
    produtoMatricial(mat, mat2, result, L, C);
    printf("Produto matricial:\n");
    printComplexMatrix(result, L, C);
    printf("\n");

    free(result);
    free(mat);
    free(mat2);
}

int main() {
	srand(time(NULL));

    printf("Test Case 1: Matriz 3x2\n");
    teste_calc_svd(3, 2);
    printf("\n");

    printf("Test Case 2: Matriz 4x4\n");
    teste_calc_svd(4, 4);
    printf("\n");

    printf("Test Case 3: Matriz 6x5\n");
    teste_calc_svd(6, 5);
    printf("\n");

    printf("Test Case 4: Matriz 5x6 (Complexa)\n");
    teste_calc_svd(5, 6);
    printf("\n");

int i, j;
int L = 3;
int C = 3;

Complex *mat = (Complex *)malloc(L * C * sizeof(Complex));
Complex *mat2 = (Complex *)malloc(L * C * sizeof(Complex));
Complex *result = (Complex *)malloc(L * C * sizeof(Complex));

    for ( i = 0; i < L; i++) {
        for ( j = 0; j < C; j++) {
            *(mat + i * C + j) = (Complex){i + j, i - j};
            *(mat2 + i * C + j) = (Complex){i - j, i + j};
        }}

    printf("\n");
    printf("\t 1. Matriz trasposta \n");
    printf("\t 2. Matriz conjugada \n");
    printf("\t 3. Matriz hermitiana \n");
    printf("\t 4. Soma de matrizes  \n");
    printf("\t 5. Subtracao de matrizes \n");
    printf("\t 6. Produto escalar \n");
    printf("\t 7. Produto matricial \n");
    printf("\n");

    printf("\tMatriz original 3x3:\n");
        printComplexMatrix(mat, L, C);
        printf("\n");
        teste_transposta(mat, L, C);

    printf("\tMatriz transposta:\n");
            printComplexMatrix(mat, C, L);
            free(mat);
    printf("\n");
    printf("\tMatriz original 3x3:\n");
        printComplexMatrix(mat, L, C);
        printf("\n");
        teste_conjugada(mat, L, C);

    printf("\tMatriz conjugada:\n");
        printComplexMatrix(mat, L, C);
        free(mat);


    printf("\tMatriz original 3x3:\n");
        printComplexMatrix(mat, L, C);
        printf("\n");
    printf("\tMatriz Hermitiana 3x3:\n");
        teste_hermitiana(mat,result, L, C);
        printComplexMatrix(result, L, C);
        printf("\n");


    printf("\tMatriz original 3x3:\n");
            printComplexMatrix(mat, L, C);
            printf("\n");
    printf("\tSegunda matriz 3x3 :\n");
            printComplexMatrix(mat2, L, C);
            teste_soma(mat, mat2, result, L, C);
    printf("\tMatriz soma:\n");
            printComplexMatrix(result, L, C);
            free(result);
            free(mat);
            free(mat2);


    printf("\tMatriz original 3x3:\n");
            printComplexMatrix(mat, L, C);
            printf("\n");

    printf("\tSegunda matriz 3x3\n");
            printComplexMatrix(mat2, L, C);
            teste_subtracao(mat, mat2, result, L, C);
    printf("\tMatriz subtracao:\n");
            printComplexMatrix(result, L, C);
            free(result);
            free(mat);
            free(mat2);


    printf("\tMatriz original 3x3:\n");
            printComplexMatrix(mat, L, C);
            printf("\n");
    printf("\tSegunda matriz 3x3\n");
            printComplexMatrix(mat2, L, C);
    Complex resultado;
    teste_produto_escalar(mat, mat2, L, C, &resultado);
            printf("Produto escalar: ");
            impC(resultado);
            printf("\n");

    printf("\tMatriz original 3x3:\n");
            printComplexMatrix(mat, L, C);
            printf("\n");
    printf("\tSegunda matriz 3x3\n");
            printComplexMatrix(mat2, L, C);
            produtoMatricial(mat, mat2, result, L, C);
    printf("\tProduto matricial:\n");
            printComplexMatrix(result, L, C);
            free(result);
            free(result);
            free(mat);
            free(mat2);



return 0;

}







