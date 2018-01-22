CC = g++
DEBUG = -g -O0  -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

All: ClockLuck

ClockLuck: ClockLuck.o
	$(CC) $(LFLAGS) -o ClockLuck ClockLuck.o

ClockLuck.o: ClockLuck.cpp
	$(CC) $(CFLAGS) ClockLuck.cpp

.PHONY: clean

clean:
	rm -rf ClockLuck.o
	rm -rf ClockLuck
