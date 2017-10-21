CC=gcc
FLAGS= -std=c99 -Wall -g -o

DEP=graphs.h floyd.h array.h dijkstra.h
SRC=graphs.c main.c floyd.c array.c dijkstra.c

BIN=graphs



.PHONY: all clean

all: $(SRC)
	gcc $(FLAGS) $(BIN) $(SRC) $(DEP)

test: $(TEST)
	gcc $(FLAGS) $(TEST_BIN) $(TEST) $(TEST_DEP)

clean:
	$(RM) $(BIN) *~
