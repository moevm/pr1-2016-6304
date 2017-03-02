text: text.o main.o
	gcc main.o -o text text.o
	rm *.o
main.o: text.h main.c    
	gcc -c main.c
text.o: text.c
	gcc -c text.c





