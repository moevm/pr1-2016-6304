curs_work: main.o Functions.o
	gcc main.o -o curs_work Functions.o
	rm *.o
main.o: main.c
	gcc -c main.c
Functions.o: Functions.c Functions.h 
	gcc -c Functions.c
