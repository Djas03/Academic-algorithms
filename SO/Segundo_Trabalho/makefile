#$(CFLAGS)
CFLAGS = -O
C = gcc

all:allocator

allocator: trabalho.o
	$(C) -o allocator trabalho.o
trabalho.o : trabalho.c
	$(C) -c trabalho.c
clean: rm -f core *.o