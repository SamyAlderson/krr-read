#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"

#define RINGBUF_SIZE (config.RINGBUF_SIZE)

struct ringbuf {
    char data[RINGBUF_SIZE];
    uint32_t head;
    uint32_t tail;
};

bool ringbuf_init(struct ringbuf *buf) {
    if (buf == NULL) {
        return false;
    }
    buf->head = 0;
    buf->tail = 0;
    return true;
}

size_t ringbuf_len(struct ringbuf *buf) {
    if (buf == NULL) {
        return 0;
    }
    if (buf->head >= buf->tail) {
        return RINGBUF_SIZE - buf->tail + buf->head;
    } else {
        return buf->head - buf->tail;
    }
}

size_t ringbuf_capacity(struct ringbuf *buf) {
    return RINGBUF_SIZE;
}

bool ringbuf_is_empty(struct ringbuf *buf) {
    return (buf->head == buf->tail);
}

bool ringbuf_is_full(struct ringbuf *buf) {
    return ((buf->head + 1) % RINGBUF_SIZE == buf->tail);
}

bool ringbuf_put(struct ringbuf *buf, char c) {
    if (buf == NULL || ringbuf_is_full(buf)) {
        return false;
    }
    buf->data[buf->head] = c;
    buf->head = (buf->head + 1) % RINGBUF_SIZE;
    return true;
}

bool ringbuf_get(struct ringbuf *buf, char *c) {
    if (buf == NULL || ringbuf_is_empty(buf)) {
        return false;
    }
    *c = buf->data[buf->tail];
    buf->tail = (buf->tail + 1) % RINGBUF_SIZE;
    return true;
}

const char *ringbuf_strerror(int err) {
    switch (err) {
        case 0:
            return "Success";
        case -1:
            return "Invalid ring buffer pointer";
        case -2:
            return "Ring buffer is full";
        case -3:
            return "Ring buffer is empty";
        default:
            return "Unknown error";
    }
}

int main() {
    struct ringbuf buf;
    if (!ringbuf_init(&buf)) {
        printf("Failed to initialize ring buffer\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        if (!ringbuf_put(&buf, 'a' + i)) {
            printf("Failed to put byte into ring buffer\n");
            return 1;
        }
    }
    for (int i = 0; i < 10; i++) {
        char c;
        if (!ringbuf_get(&buf, &c)) {
            printf("Failed to get byte from ring buffer\n");
            return 1;
        }
        printf("%c\n", c);
    }
    return 0;
}