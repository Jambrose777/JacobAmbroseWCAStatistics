#Makefile
CC = g++
DEBUG = -g -O0  -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
SRC = src
BIN = bin

All: SumOfRanksS

SumOfRanksS: $(BIN)/SumOfRanksS.o
	$(CC) $(LFLAGS) -o $(BIN)/SumOfRanksS $(BIN)/SumOfRanksS.o

$(BIN)/SumOfRanksS.o: $(SRC)/SumOfRanksS.cpp
	$(CC) $(CFLAGS) -o $(BIN)/SumOfRanksS.o $(SRC)/SumOfRanksS.cpp

.PHONY: clean

run:
	./bin/SumOfRanksS resources/WorstRanksS.txt resources/RanksS.txt 

clean:
	rm -rf bin/*
	rm -rf results/*
