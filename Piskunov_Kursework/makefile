main: main.o
	gcc -o main main.c spsw.c ms.c sort.c
	rm *.o

main.o: main.c
	gcc -c main.c

ms.o: ms.c td.h ms.h
	gcc -c ms.c

sort.o: sort.c sort.h ms.h
	gcc -c sort.c

spsw.o: spsw.c spsw.h ms.h
	gcc -c spsw.c
