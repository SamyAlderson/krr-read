// main.c - Main entry point for the kernel ring buffer reader
// 2026

#include "config.h"
#include "utils.h"
#include "ringbuf.h"

int main(int argc, char **argv) {
    // Initialize the ring buffer with a default capacity (16 elements)
    ringbuf_t *buf = ringbuf_init(16);

    // Check if the buffer was successfully initialized
    if (buf == NULL) {
        fprintf(stderr, "Failed to initialize the ring buffer\n");
        return 1;
    }

    // Test the ring buffer reader with some sample data
    char data[] = "Hello, world!";
    int len = strlen(data);
    ringbuf_put(buf, data, len);

    // Print the contents of the ring buffer
    print_ringbuf(buf);

    // Clean up the ring buffer
    ringbuf_free(buf);

    return 0;
}
```

```c
// ringbuf.c - Kernel ring buffer implementation
// 2026

#include "config.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

// Structure to represent a ring buffer
typedef struct {
    char *data;
    int capacity;
    int head;
    int tail;
} ringbuf_t;

// Initialize a new ring buffer with the given capacity
ringbuf_t *ringbuf_init(int capacity) {
    ringbuf_t *buf = malloc(sizeof(ringbuf_t));
    if (buf == NULL) {
        fprintf(stderr, "Failed to allocate memory for the ring buffer\n");
        return NULL;
    }

    // Allocate memory for the buffer data
    buf->data = malloc(capacity * sizeof(char));
    if (buf->data == NULL) {
        fprintf(stderr, "Failed to allocate memory for the ring buffer data\n");
        free(buf);
        return NULL;
    }

    // Initialize the buffer metadata
    buf->capacity = capacity;
    buf->head = 0;
    buf->tail = 0;

    return buf;
}

// Free the resources associated with a ring buffer
void ringbuf_free(ringbuf_t *buf) {
    free(buf->data);
    free(buf);
}

// Put data into the ring buffer
int ringbuf_put(ringbuf_t *buf, char *data, int len) {
    // Copy data into the buffer
    int i;
    for (i = 0; i < len; i++) {
        // Write data to the next available slot
        buf->data[(buf->head + i) % buf->capacity] = data[i];
    }

    // Update the head and tail indices
    buf->head = (buf->head + len) % buf->capacity;
    return len;
}

// Print the contents of the ring buffer
void print_ringbuf(ringbuf_t *buf) {
    int i;
    for (i = 0; i < buf->capacity; i++) {
        printf("%c", buf->data[i]);
    }
    printf("\n");
}
```

```c
// Makefile
// 2026

# Build targets
all: main

# Source files
SRCS = main.c ringbuf.c utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Compile the program
main: $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -o $@

# Compile individual source files
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
    rm -f *.o main