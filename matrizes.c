#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
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
    }}// Função para imprimir uma matriz complexa
Complex conjugado(Complex c) {
    Complex resultado;
    resultado.Re = c.Re;
    resultado.Im = -c.Im; // troca o sinal da parte imaginária
    return resultado;
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
int i, j;
int escolha;
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
    printf("\tEscolha a manipulacao matricial de 3x3 que deseja executar:\n");
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







