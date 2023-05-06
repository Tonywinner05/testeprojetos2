#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 4
#include <time.h>

int** criar_matriz() {
	int i;
	int*m = (int*)malloc(M*sizeof(int));
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
	printf ("%d",m[i][j]);
		}
	printf("/n");
	}
printf("/n");
}

//matriz_trasporta()
//desalocar_matriz()

int main(){
	
	int** matriz= criar_matriz();
	preencher_matriz(matriz);
	mostrar_matriz(matriz);
	return 0;
}