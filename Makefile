CC = gcc
CFLAGS = -O3 -Wall -c
LDFLAGS = -O3

MAKE_OPTIONS = $(PWD)/Makefile.in
include $(MAKE_OPTIONS)
HEAD = structs.h init.h par.h legendre.h
OBJ = grid.o init.o legendre.o main.o par.o
default: dg1d

dg1d: $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
	rm -f *.o dg1d
