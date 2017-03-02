Lab: main.o print_names.o count.o push.o removeEl.o createMC.o struct.h func.h
	gcc main.o -o Lab.out print_names.o count.o push.o removeEl.o createMC.o 
	rm *.o
main.o: main.c struct.h func.h			
	gcc -c main.c                     
print_names.o: print_names.c struct.h	
	gcc -c print_names.c
removeEl.o: removeEl.c struct.h  
	gcc -c removeEl.c
count.o: count.c struct.h
	gcc -c count.c   
push.o: push.c struct.h
	gcc -c push.c
createMC.o: createMC.c struct.h
	gcc -c createMC.c
