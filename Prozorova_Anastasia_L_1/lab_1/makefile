main: get_name.o print_str.o main.o
	gcc main.o -o main get_name.o print_str.o
#запись результата в исполняемый файл name
	rm *.o
#очистка
main.o : main.c get_name.h print_str.h
	gcc -c main.c
#cоздание объектного файла main.o
get_name.o: get_name.c get_name.h
	gcc -c get_name.c
#cоздание объектного файла get_name.o
print_str.o: print_str.c print_str.h
	gcc -c print_str.c
#cоздание объектного файла print_str.o
