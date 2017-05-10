Lab3: main.o functions.o
	g++ main.o -o read_catalog.out functions.o
	rm *.o
main.o: main.c functions.h
	g++ -c main.c
functions.o: functions.c functions.h
	g++ -c functions.c
