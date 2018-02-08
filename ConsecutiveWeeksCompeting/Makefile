#Makefile
CC = g++
DEBUG = -g -O0  -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
SRC = src
BIN = bin

All: ConsecutiveWeeksCompeting

ConsecutiveWeeksCompeting: $(BIN)/ConsecutiveWeeksCompeting.o
	$(CC) $(LFLAGS) -o $(BIN)/ConsecutiveWeeksCompeting $(BIN)/ConsecutiveWeeksCompeting.o

$(BIN)/ConsecutiveWeeksCompeting.o: $(SRC)/ConsecutiveWeeksCompeting.cpp
	$(CC) $(CFLAGS) -o $(BIN)/ConsecutiveWeeksCompeting.o $(SRC)/ConsecutiveWeeksCompeting.cpp

.PHONY: clean

run:
	./bin/ConsecutiveWeeksCompeting resources/data.txt 

clean:
	rm -rf bin/*
	rm -rf results/*
