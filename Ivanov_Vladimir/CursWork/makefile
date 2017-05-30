rank: main.o Gauss.o Swaps.o
	gcc main.o -o rank Gauss.o Swaps.o
	rm *.o
main.o: main.c Gauss.h 
	gcc -c main.c 
Gauss.o: Gauss.c Gauss.h Swaps.h
	gcc -c Gauss.c
Swaps.o: Swaps.c Swaps.h
	gcc -c Swaps.c
