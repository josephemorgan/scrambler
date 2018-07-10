CC = clang++
CFLAGS = -g -Wall -pedantic -std=c++11

scrambler.out: main.o scrambler.o word.o makefile
	$(CC) $(CFLAGS) main.o scrambler.o word.o -o scrambler.out

main.o: main.cpp scrambler.h
	$(CC) $(CFLAGS) main.cpp -c

scrambler.o: scrambler.cpp scrambler.h
	$(CC) $(CFLAGS) scrambler.cpp -c

word.o: word.cpp word.h
	$(CC) $(CFLAGS) word.cpp -c

clean:
	rm ./*.o

vim:
	vim main.cpp scrambler.h scrambler.cpp word.h word.cpp makefile
