main: get_name.o print_str.o main.o
	 gcc main.o -o main  get_name.o print_str.o 
#Линковка
#Исполняемый файл - main
	rm *.o
#Очистка
main.o: main.c
	 gcc -c main.c 
#Создание объектного файла main.o

get_name.o: get_name.c get_name.h
	 gcc -c get_name.c  
#Создание объектного файла get_name.o

print_str.o: print_str.c print_str.h
	 gcc -c print_str.c 
#Создание объектного файла print_str.o

clean: 
	rm *.o

