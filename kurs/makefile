curs: curs.o func.o
	gcc  curs.c -o curs.out func.c
	rm -rf *.o
curs.o :curs.c
	gcc -c curs.c
func.o: func.c func.h
	gcc -c func.c
