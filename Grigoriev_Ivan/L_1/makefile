main: main.o get_name.o print_str.o
	gcc main.o -o main get_name.o print_str.o
	rm *.o
main.o: main.c get_name.h print_str.h
	gcc -c main.c
print_str.o: print_str.h print_str.c
	gcc -c print_str.c
get_name.o: get_name.h get_name.c
	gcc -c get_name.c

