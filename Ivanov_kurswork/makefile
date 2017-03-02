main: dlya_kurs.o from_L_4.o main_of_kurs.o
	gcc main_of_kurs.o -o main dlya_kurs.o from_L_4.o
		rm *.o

main_of_kurs.o: main_of_kurs.c dlya_kurs.h from_L_4.h
	gcc -c main_of_kurs.c
	
from_L_4.o: from_L_4.c from_L_4.h
	gcc -c -std=c99 from_L_4.c
	
dlya_kurs.o: dlya_kurs.c dlya_kurs.h from_L_4.h
	gcc -c dlya_kurs.c
