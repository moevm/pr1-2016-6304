main: menu.o main.o                    
	gcc main.o -o main menu.o
	rm *o
menu.o: menu.c 
	gcc -c menu.c
main.o: main.c menu.h
	gcc -c main.c
