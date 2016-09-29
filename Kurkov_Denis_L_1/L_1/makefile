all: laba clean

laba: main.o get_name.o print_str.o
	gcc main.o get_name.o print_str.o -o laba

get_name.o: get_name.c
	gcc -c get_name.c
print_str.o: print_str.c
	gcc -c  print_str.c
main.o: main.c
	gcc -c main.c
clean:
	rm *.o 
