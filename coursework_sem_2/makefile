bmptest: main.o functions.o
	gcc main.o -o bmptest functions.o
	rm *.o
main.o: main.c structures.h functions.h
	gcc -c main.c
functions.o: functions.c functions.h structures.h
	gcc -c functions.c