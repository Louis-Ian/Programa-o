all: exe
	make limpar
	make jogar

exe: main3.o tudo3.o
	gcc main3.o tudo3.o -o JOGO

jogar: exe
	./JOGO

main: main3.c
	gcc -c main3.c -o main3.o

batalhaNaval: tudo3.c tudo3.h
	gcc -c tudo3.c -o tudo3.o

limpar:
	rm *.o

desinstalar:
	rm JOGO