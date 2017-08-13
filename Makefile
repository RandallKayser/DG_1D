CC = gcc
CFLAGS =-O3 -Wall -c
LDFLAGS =-O3
INCLUDE =-lm
MAKE_OPTIONS = $(PWD)/Makefile.in
include $(MAKE_OPTIONS)
HEAD = structs.h init.h par.h legendre.h
OBJ = init.o legendre.o main.o par.o $(INITIAL).o
default: dg1d

dg1d: $(OBJ)
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDE)

$(INITIAL).o: Initial/$(INITIAL).c $(HEAD)
	$(CC) $(CFLAGS) $(INCLUDE) Initial/$(INITIAL).c

dg1d: $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@ $(INCLUDE)

.PHONY: clean

clean:
	rm -f *.o dg1d

.PHONY: echo
echo:
	echo $(INITIAL)
