#запись результата в исполняемый файл name
main: bmp_func.o main.o
	gcc main.o -o main bmp_func.o
#очистка
	rm *.o

#cоздание объектного файла main.o
main.o : main.c bmp_func.h bmp_structs.h
	gcc -c main.c

#cоздание объектного файла bmp_func.o
bmp_func.o: bmp_func.c bmp_func.h bmp_structs.h
	gcc -c bmp_func.c


