#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "utils.h"

#define RINGBUF_SIZE 256
#define TEST_DATA "Hello, world!"

int main() {
    // Initialize the ring buffer with a default size
    ringbuf_t* ringbuf = ringbuf_init(RINGBUF_SIZE);

    // Test writing data to the ring buffer
    if (ringbuf_write(ringbuf, TEST_DATA, strlen(TEST_DATA)) != 0) {
        printf("Error writing to ring buffer: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Test reading data from the ring buffer
    char* data = ringbuf_read(ringbuf, RINGBUF_SIZE);
    if (data == NULL) {
        printf("Error reading from ring buffer: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Check if the read data matches the original test data
    if (strcmp(data, TEST_DATA) != 0) {
        printf("Read data does not match expected data\n");
        free(data);
        return EXIT_FAILURE;
    }

    // Clean up and free resources
    free(data);
    ringbuf_free(ringbuf);

    printf("Ring buffer test successful\n");
    return EXIT_SUCCESS;
}