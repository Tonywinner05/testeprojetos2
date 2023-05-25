all: teste

teste: build/main.o matrizes.o
	gcc build/main.o matrizes.o -o teste

main.o: main.c
	gcc -c src/main.c -o build/main.o

matrizes.o: matrizes.c
	gcc -c src/matrizes.c -o build/matrizes.o


clean:
	rm *.o
	rm *.exe
