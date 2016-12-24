mclist: mclist.o
	gcc -o mclist mclist.c addel.c createfunc.c remove.c
	rm *.o

mclist.o: mclist.c
	gcc -c mclist.c

createfunc.o: createfunc.c createfunc.h type.h
	gcc -c createfunc.c

addel.o: addel.c addel.h createfunc.h
	gcc -c addel.c

remove.o: remove.c remove.h createfunc.h
	gcc -c remove.c
