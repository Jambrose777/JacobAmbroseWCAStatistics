#Makefile
CC = g++
DEBUG = -g -O0  -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
SRC = src
BIN = bin

All: ClockLuck ClockLuckSingle ClockDelegate

ClockLuck: $(BIN)/ClockLuck.o
	$(CC) $(LFLAGS) -o $(BIN)/ClockLuck $(BIN)/ClockLuck.o

$(BIN)/ClockLuck.o: $(SRC)/ClockLuck.cpp
	$(CC) $(CFLAGS) -o $(BIN)/ClockLuck.o $(SRC)/ClockLuck.cpp

ClockLuckSingle: $(BIN)/ClockLuckSingle.o
	$(CC) $(LFLAGS) -o $(BIN)/ClockLuckSingle $(BIN)/ClockLuckSingle.o

$(BIN)/ClockLuckSingle.o: $(SRC)/ClockLuckSingle.cpp
	$(CC) $(CFLAGS) -o $(BIN)/ClockLuckSingle.o $(SRC)/ClockLuckSingle.cpp

ClockDelegate: $(BIN)/ClockDelegate.o
	$(CC) $(LFLAGS) -o $(BIN)/ClockDelegate $(BIN)/ClockDelegate.o

$(BIN)/ClockDelegate.o: $(SRC)/ClockDelegate.cpp
	$(CC) $(CFLAGS) -o $(BIN)/ClockDelegate.o $(SRC)/ClockDelegate.cpp

.PHONY: clean

run:
	./bin/ClockLuck resources/all.txt 
	./bin/ClockLuckSingle resources/all.txt
	./bin/ClockDelegate resources/competition_delegates.txt

clean:
	rm -rf bin/*
