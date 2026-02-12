CC = gcc
CFLAGS = -Wall -Werror
main: main.o
	$(CC) $(CFLAGS) -o main main.o -lm
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -lm
clean:
	rm -f *.o main
