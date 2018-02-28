#Makefile
CC = g++
DEBUG = -g -O0  -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
SRC = src
BIN = bin

All: SumOfRanksS SumOfRanksA

SumOfRanksS: $(BIN)/SumOfRanksS.o
	$(CC) $(LFLAGS) -o $(BIN)/SumOfRanksS $(BIN)/SumOfRanksS.o

$(BIN)/SumOfRanksS.o: $(SRC)/SumOfRanksS.cpp
	$(CC) $(CFLAGS) -o $(BIN)/SumOfRanksS.o $(SRC)/SumOfRanksS.cpp

SumOfRanksA: $(BIN)/SumOfRanksA.o
	$(CC) $(LFLAGS) -o $(BIN)/SumOfRanksA $(BIN)/SumOfRanksA.o

$(BIN)/SumOfRanksA.o: $(SRC)/SumOfRanksA.cpp
	$(CC) $(CFLAGS) -o $(BIN)/SumOfRanksA.o $(SRC)/SumOfRanksA.cpp

.PHONY: clean

run:
	./bin/SumOfRanksS resources/WorstRanksS.txt resources/RanksS.txt 
	./bin/SumOfRanksA resources/WorstRanksA.txt resources/RanksA.txt 

clean:
	rm -rf bin/*
	rm -rf results/*
