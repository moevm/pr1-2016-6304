# -*- Makefile -*-

main:	get_name.o print_str.o main.o
	gcc main.o -o main get_name.o print_str.o get_name.h print_str.h
	rm *.o
# we create executable file main which depends on get_name.o and print_str.o
main.o:	main.c 
	gcc -I. -c main.c
# we create on object file main.o in our directory
get_name.o:	get_name.c get_name.h
	gcc -I. -c get_name.c
# creating o-file get_name.o in the current dir
print_str.o:	print_str.c print_str.h
	gcc -I. -c print_str.c
# creating o-file print_str.o

