#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>


typedef struct {
    double Re;
    double Im;
} Complex;

void impC(Complex c) {
    printf("%.1f", c.Re);
    if (c.Im >= 0) {
        printf(" + %.1fi", c.Im);
    } else {
        printf(" - %.1fi", -c.Im);
}
}
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
void teste_hermitiana(){
	
}

// soma de matrizes 
void addComplexMatrices(Complex **matrix1, Complex **matrix2, Complex **result, int A, int B) {
    int i, j;
    for (i = 0; i < A; i++) {
        for (j = 0; j < B; j++) {
            result[i][j].Re = matrix1[i][j].Re + matrix2[i][j].Re; //Realiza a Soma da parte Real
            result[i][j].Im = matrix1[i][j].Im + matrix2[i][j].Im; //Realiza a Soma da parte imaginaria
        }
    }
}
    printf("Matriz dada 3x3 :\n"); //Gera a matriz 3x3
    for (i = 0; i < L; i++) {
        for ( j = 0; j < C; j++) {
            impC(mat[i * C + j]);
            printf("\t");
        }
        printf("\n");

    // Libera a mem�ria alocada
    for (i = 0; i < A; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}


// subtração de matrizes
void addComplexMatrices(Complex **matrix1, Complex **matrix2, Complex **result, int A, int B) {
    int i, j;
    for (i = 0; i < A; i++) {
        for (j = 0; j < B; j++) {
            result[i][j].Re = matrix1[i][j].Re - matrix2[i][j].Re; //Realiza a Subtra��o da parte Real
            result[i][j].Im = matrix1[i][j].Im - matrix2[i][j].Im; //Realiza a Subtra��o da parte imaginaria
        }
    }
}
 printf("Matriz dada 3x3 :\n"); //Gera a matriz 3x3
    for (i = 0; i < L; i++) {
        for ( j = 0; j < C; j++) {
            impC(mat[i * C + j]);
            printf("\t");
        }
        printf("\n");

    // Libera a mem�ria alocada
    for (i = 0; i < A; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
// produto escalar
void teste_produto_escalar(){
	
	
}
// produto matricial
void teste_produto_matricial(){

}

// execução de todas as matrizes
void teste_todos(){
}





int main() {
   
    int i, j;
    int escolha;
    int L = 3;
    int C = 3;

    Complex *mat = (Complex *)malloc(L * C * sizeof(Complex));
    
    for ( i = 0; i < L; i++) {
        for ( j = 0; j < C; j++) {
            *(mat + i * C + j) = (Complex){i + j, i - j};
        }

    }
    printf("Matriz dada 3x3 :\n");
    for (i = 0; i < L; i++) {
        for ( j = 0; j < C; j++) {
            impC(mat[i * C + j]);
            printf("\t");
        }
        printf("\n");
    }   
    printf("\n");
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
    	teste_transposta(mat, L, C);
		     printf("\nMatriz transposta:\n");
    for ( i = 0; i < C; i++) {
        for ( j = 0; j < L; j++) {
            impC(mat[i * C + j]);
            printf("\t");
        }
        printf("\n");
    }
    //
    free(mat);
    
    break;
   case 2:
    teste_conjugada(mat, L, C);
    printf("\nMatriz conjugada:\n");
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            impC(mat[i * C + j]);
            printf("\t");
        }
        printf("\n");
    }
    free(mat);
          
    break;
    
    case 3:
        teste_hermitiana();
    break;
    case 4:
        teste_soma(mat, L, C);
        printf("\nMatriz Soma:\n");
        for (i = 0; i < L; i++) {
            for (j = 0; j < C; j++) {
                impC(mat[i * C + j]);
                printf("\t");
        }
        printf("\n");
    }
    free(mat);
            
    break;
    
    case 5:
        teste_sub(mat, L, C);
        printf("\nMatriz Subtração:\n");
        for (i = 0; i < L; i++) {
            for (j = 0; j < C; j++) {
                impC(mat[i * C + j]);
                printf("\t");
        }
        printf("\n");
    }
    free(mat);

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

printf("Matriz original :\n");
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            impC(mat[i * C + j]);
            printf("\t");
        }
        printf("\n");
    }      
    
return 0;

}







