# This Makefile is designed to build the test programs for the krr-read project
# It relies on the main Makefile in the project root to set up the build environment

CC = gcc
CFLAGS = -Wall -Wextra -Isrc

# List of test programs to build
TEST_PROGRAMS = test_ringbuf test_main

# Rule to build all test programs
all: $(TEST_PROGRAMS)

# Rule to build test_ringbuf
test_ringbuf: test_ringbuf.o
	$(CC) $(CFLAGS) -o $@ $< src/ringbuf.o

# Rule to build test_main
test_main: test_main.o
	$(CC) $(CFLAGS) -o $@ $< src/main.o

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean rule to remove object files and test programs
clean:
	rm -f *.o $(TEST_PROGRAMS)