all: teste

teste: main.o matrizes.o
	gcc main.o matrizes.o -o teste

main.o: main.c
	gcc -c main.c -o main.o

matrizes.o: matrizes.c
	gcc -c matrizes.c -o matrizes.o


clean:
	rm *.o
	rm *.exe