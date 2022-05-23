CC = gcc
CFLAGS = -g -Wall -lm -std=gnu11

build: tema1

tema1: tema1.c
	$(CC) -o tema1 tema1.c $(CFLAGS)

.PHONY : clean
clean:
	rm -f tema1
	rm -f *.out