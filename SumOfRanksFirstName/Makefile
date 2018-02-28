#Makefile
CC = g++
DEBUG = -g -O0  -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
SRC = src
BIN = bin

All: SumOfRanks

SumOfRanks: $(BIN)/SumOfRanks.o
	$(CC) $(LFLAGS) -o $(BIN)/SumOfRanks $(BIN)/SumOfRanks.o

$(BIN)/SumOfRanks.o: $(SRC)/SumOfRanks.cpp
	$(CC) $(CFLAGS) -o $(BIN)/SumOfRanks.o $(SRC)/SumOfRanks.cpp

.PHONY: clean

run:
	./bin/SumOfRanks resources/WorstRanks.txt resources/Ranks.txt 

clean:
	rm -rf bin/*
	rm -rf results/*
