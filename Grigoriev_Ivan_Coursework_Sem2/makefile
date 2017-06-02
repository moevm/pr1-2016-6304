swapqrt: main.o bmpfunctions.o
        gcc main.o -o swapqrt bmpfunctions.o
        rm *.o
main.o: main.c bmpstructures.h bmpfunctions.h
        gcc -c main.c
bmpfunctions.o: bmpfunctions.c bmpfunctions.h bmpstructures.h
        gcc -c bmpfunctions.c
