CC = clang++
CFLAGS = -g -Wall -pedantic -std=c++11

scrambler.out: main.o scrambler.o makefile
	$(CC) $(CFLAGS) main.o scrambler.o -o scrambler.out

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -c

scrambler.o: scrambler.cpp scrambler.h
	$(CC) $(CFLAGS) scrambler.cpp -c

clean:
	rm ./*.o
