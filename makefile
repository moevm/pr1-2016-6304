zachet: mc_functions.o main.o
	gcc mc_functions.o main.o -o kurswork.out
	rm *.o
mc_functions: mc_functions.h mc_functions.c 
	gcc -c mc_functions.c 
main.o: main.c main.h
	gcc -c main.c
