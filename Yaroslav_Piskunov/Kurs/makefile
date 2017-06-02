KourseWork: main.o functions.o
	gcc -o main main.o functions.o
	rm *.o;

main.o: main.c functions.h
	gcc -c main.c

functions.o: functions.c functions.h
	gcc -c functions.c