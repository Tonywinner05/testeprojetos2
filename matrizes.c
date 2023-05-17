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
    resultado.Im = -c.Im; // troca o sinal da parte imagin�ria
    return resultado;
}

// Matriz Transposta
void teste_transposta() {
	
}

// Matriz Conjugada
void teste_conjugada() {
    
}
// matriz hermitiana
void teste_hermitiana(){
	
}

// soma de matrizes 
void teste_soma(){
}

// subtra��o de matrizes
void teste_sub(){
}
// produto escalar
void teste_produto_escalar(){
	
	
}
// produto matricial
void teste_produto_matricial(){

}
// execu��o de todas as matrizes
void teste_todos(){

}



int main() {
    int escolha;
    int L = 3;
    int C = 3;
	int i,j;
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
    printf("Escolha a manipula��o matricial de 3x3 que deseja executar:\n");
    printf("1. matriz trasposta \n");
    printf("2. matriz conjugada \n");
    printf("3. matriz hermitiana \n");
    printf("4. soma de matrizes  \n");
    printf("5. subtra��o de matrizes \n");
    printf("6. produto escalar \n");
    printf("7. produto matrcial \n");
    printf("8. todas \n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
    	teste_transposta();
    
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
    printf("Op��o inv�lida!\n");
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







