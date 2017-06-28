all: programm 
	rm *.o

programm: main.o get_matrix.o searching.o
	gcc -o programm main.o get_matrix.o searching.o -lm

main.o: main.c
	gcc -c main.c

get_matrix.o: get_matrix.c
	gcc -c get_matrix.c

searching.o: searching.c
	gcc -c searching.c