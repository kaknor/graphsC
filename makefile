CC=gcc
FLAGS= -std=c99 -Wall -g -o

DEP=graphs.h floyd.h
SRC=graphs.c main.c floyd.c
BIN=graphs

.PHONY: all clean

all: $(SRC)
	gcc $(FLAGS) $(BIN) $(SRC) $(DEP)

clean:
	$(RM) $(BIN) *~
