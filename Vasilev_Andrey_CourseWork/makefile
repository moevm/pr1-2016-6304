course: main.o functions.o
	g++ main.o -o course.out functions.o
	rm *.o
main.o: main.c bmp_structs.h functions.h
	g++ -c main.c
functions.o: functions.c functions.h bmp_structs.h
	g++ -c functions.c




