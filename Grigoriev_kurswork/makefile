main: api.o kursfunc.o main.o
		gcc main.o -o main api.o kursfunc.o
		rm *.o
                
main.o: main.c api.h kursfunc.h
		gcc -c -std=c99 main.c
	
api.o: api.c api.h
		gcc -c -std=c99 api.c
	
kursfunc.o: kursfunc.c kursfunc.h api.h
		gcc -c -std=c99 kursfunc.c             
