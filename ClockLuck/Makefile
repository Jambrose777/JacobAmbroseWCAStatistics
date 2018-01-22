CC = g++
DEBUG = -g -O0  -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

All: ClockLuck ClockLuckSingle

ClockLuck: ClockLuck.o
	$(CC) $(LFLAGS) -o ClockLuck ClockLuck.o

ClockLuck.o: ClockLuck.cpp
	$(CC) $(CFLAGS) ClockLuck.cpp

ClockLuckSingle: ClockLuckSingle.o
	$(CC) $(LFLAGS) -o ClockLuckSingle ClockLuckSingle.o

ClockLuckSingle.o: ClockLuckSingle.cpp
	$(CC) $(CFLAGS) ClockLuckSingle.cpp

.PHONY: clean

clean:
	rm -rf ClockLuck.o
	rm -rf ClockLuck
	rm -rf ClockLuckSingle.o
	rm -rf ClockLuckSingle
