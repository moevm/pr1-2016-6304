main: main.o
	gcc -o main main.c create.c sort.c
	rm *.o

main.o: main.c 
	gcc -c main.c 

create.o: create.c create.h structure.h
	gcc -c create.c

sort.o: sort.c sort.h structure.h
	gcc -c sort.c
