main : main.o lib.o
	gcc main.o lib.o -o main
lib.o: lib.c lib.h
	gcc -c lib.c -o lib.o
main.o: main.c lib.h
	gcc -c main.c -o main.o