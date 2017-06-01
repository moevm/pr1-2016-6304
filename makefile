Rotation: main.o functions.o
	gcc main.o -o Rotation functions.o
	rm *.o
main.o: main.c BmpStructures.h functions.h
	gcc -c main.c
functions.o: functions.c functions.h BmpStructures.h
	gcc -c functions.c