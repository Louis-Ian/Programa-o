all: exe
	make clean
	make play

play:
	./exe

exe: ABB main
	gcc main.o ABB.o -o exe

main: main.c
	gcc -c main.c -o main.o

ABB: ABB.c ABB.h
	gcc -c ABB.c -o ABB.o

clean:
	rm *.o