main:main.o functions.o 
	gcc  main.cpp -o cursach.out functions.cpp
	rm -rf *.o 
main.o :main.cpp
	gcc -c main.cpp
functions.o: functions.cpp functions.h
	gcc -c functions.cpp 
