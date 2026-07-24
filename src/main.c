// Include the necessary header file for the ring buffer
#include "ringbuf.h"

// Include the necessary header file for the test ring buffer
#include "test_ringbuf.h"

int main() {
    // Initialize the ring buffer
    ringbuf_t ringbuf;
    ringbuf_init(&ringbuf);

    // Test the ring buffer
    test_ringbuf(&ringbuf);

    return 0;
}