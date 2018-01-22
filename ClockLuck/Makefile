#Makefile
CC = g++
DEBUG = -g -O0  -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

All: ClockLuck ClockLuckSingle ClockDelegate

ClockLuck: ClockLuck.o
	$(CC) $(LFLAGS) -o ClockLuck ClockLuck.o

ClockLuck.o: ClockLuck.cpp
	$(CC) $(CFLAGS) ClockLuck.cpp

ClockLuckSingle: ClockLuckSingle.o
	$(CC) $(LFLAGS) -o ClockLuckSingle ClockLuckSingle.o

ClockLuckSingle.o: ClockLuckSingle.cpp
	$(CC) $(CFLAGS) ClockLuckSingle.cpp

ClockDelegate: ClockDelegate.o
	$(CC) $(LFLAGS) -o ClockDelegate ClockDelegate.o

ClockDelegate.o: ClockDelegate.cpp
	$(CC) $(CFLAGS) ClockDelegate.cpp

.PHONY: clean

clean:
	rm -rf ClockLuck.o
	rm -rf ClockLuck
	rm -rf ClockLuckSingle.o
	rm -rf ClockLuckSingle
	rm -rf ClockDelegate.o
	rm -rf ClockDelegate
