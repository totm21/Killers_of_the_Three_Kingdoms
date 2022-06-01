all:main

main:main.o error_me.o
	gcc -o ../main main.o error_me.o

main.o:../code/sources/main.c
	gcc -c ../code/sources/main.c -o main.o

error_me.o:../code/sources/error_me.c ../code/headers/error_me.h
	gcc -c ../code/sources/error_me.c -o error_me.o

clean:
	del *.o

.PHONY:clean