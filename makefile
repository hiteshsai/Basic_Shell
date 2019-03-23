CC = gcc
CFLAGS = -Wall -c
INCPATH = ./include
INCLUDE = -I./include

Basicshell: main.o myshell.o
	$(CC) -g main.o myshell.o -o Basicshell

main.o: main.c 	$(INCPATH)/Basicshell.h
	$(CC) $(CFLAGS) main.c $(INCLUDE)

myshell.o: myshell.c $(INCPATH)/Basicshell.h
	$(CC) $(CFLAGS) myshell.c $(INCLUDE)

clean:
	rm *.o *~
