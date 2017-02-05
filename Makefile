CC=gcc
CFLAGS=-Wall

all: p05
p05: p05.o
p05.o: p05.c p05.h

clean:
	rm -f p05 p05.o
