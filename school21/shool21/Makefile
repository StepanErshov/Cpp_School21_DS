CC=gcc
CFLAGS=-Wall -Wextra -Werror
DIR= build/

all: cipher

cipher: cipher.o logger.o
	$(CC) $(CFLAGS) cipher.o logger.o -o $(DIR)cipher
cipher.o: cipher.c
	$(CC) $(CFLAGS) -c cipher.c -o cipher.o
logger.o: logger.c
	$(CC) $(CFLAGS) -c logger.c -o logger.o
clean:
	rm -f *.o $(DIR)cipher.exe
rebuild: 
	clean all
