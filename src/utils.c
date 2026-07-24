#include "config.h"
#include "utils.h"

// Utility function to print an error message
void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

// Utility function to print a success message
void print_success(const char *message) {
    fprintf(stdout, "Success: %s\n", message);
}

// Utility function to check if a file descriptor is valid
int is_valid_fd(int fd) {
    // Check if the file descriptor is within the valid range
    if (fd < 0 || fd > FD_SETSIZE) {
        print_error("Invalid file descriptor");
        return -1;
    }
    return 0;
}

// Utility function to check if a memory address is valid
void *is_valid_addr(void *addr) {
    // Check if the address is NULL
    if (addr == NULL) {
        print_error("Invalid memory address");
        return NULL;
    }
    return addr;
}

// Utility function to clear a buffer
void clear_buffer(char *buf, size_t size) {
    // Not proud of this but it works
    for (size_t i = 0; i < size; i++) {
        buf[i] = '\0';
    }
}

// Utility function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Utility function to get the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}