transpose: main.o function.o
	gcc main.o –o transpose function.o
	rm *.o
main.o: main.c function.h
	gcc –c main.c
function.o: function.c function.h
	gcc –c function.h
