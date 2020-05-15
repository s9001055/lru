$(CC):=gcc

all:
	$(CC) -Wall -g -o lru.out lru.c

.PHONY:clean
clean:
	rm lru.out
