main: idz.o kurs.o menu.o
	gcc menu.o -o main idz.o kurs.o
		rm *.o

menu.o: menu.c idz.h kurs.h
	gcc -c menu.c
        
kurs.o: kurs.c kurs.h
	gcc -c -std=c99 kurs.c
        
idz.o: idz.c idz.h kurs.h
	gcc -c idz.c
