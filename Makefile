# Makefile for krr-read project

# Project configuration
PROJECT = krr-read
CFLAGS = -Wall -Werror -std=c99
LDFLAGS = -Wl,--no-undefined

# Source files
SRCS = src/main.c src/ringbuf.c src/test_ringbuf.c src/test_main.c src/utils.c

# Header files
HDRS = src/ringbuf.h src/utils.h

# Test program configuration
TEST_PROG = test_ringbuf test_main
TEST_SRCS = src/test_ringbuf.c src/test_main.c

# Build targets
all: ringbuf test_ringbuf test_main

ringbuf: src/ringbuf.o
	$(CC) $(CFLAGS) -o ringbuf src/ringbuf.o $(LDFLAGS)

test_ringbuf: test_ringbuf.o src/ringbuf.o
	$(CC) $(CFLAGS) -o test_ringbuf test_ringbuf.o src/ringbuf.o $(LDFLAGS)

test_main: test_main.o src/ringbuf.o
	$(CC) $(CFLAGS) -o test_main test_main.o src/ringbuf.o $(LDFLAGS)

src/ringbuf.o: src/ringbuf.c src/ringbuf.h
	$(CC) $(CFLAGS) -c src/ringbuf.c

test_ringbuf.o: src/test_ringbuf.c src/ringbuf.h
	$(CC) $(CFLAGS) -c src/test_ringbuf.c

test_main.o: src/test_main.c src/ringbuf.h
	$(CC) $(CFLAGS) -c src/test_main.c

src/utils.o: src/utils.c src/utils.h
	$(CC) $(CFLAGS) -c src/utils.c

# Clean target
clean:
	rm -f *.o ringbuf test_ringbuf test_main

# Test target
test: all
	./test_ringbuf
	./test_main

# Install target
install:
	cp ringbuf /usr/bin/
	cp test_ringbuf /usr/bin/
	cp test_main /usr/bin/

# Uninstall target
uninstall:
	rm -f /usr/bin/ringbuf
	rm -f /usr/bin/test_ringbuf
	rm -f /usr/bin/test_main