main: main.o get_name.o print_str.o
	gcc -o main main.c get_name.c print_str.c
	rm *.o

main.o: main.c get_name.c print_str.c
	gcc -c main.c

get_name.o: get_name.c get_name.h
	gcc -c get_name.c

print_str.o: print_str.c print_str.h
	gcc -c print_str.c

