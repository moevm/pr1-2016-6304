make: main.o func.o struct.h func.h
	gcc main.o -o make.out func.o 
	rm *.o
main.o: main.c struct.h func.h			
	gcc -c main.c                     
func.o: func.c struct.h func.h
	gcc -c func.c
