#ifndef KRR_READ_UTILS_H
#define KRR_READ_UTILS_H

#include <stddef.h>

/**
 * Checks if a pointer is null.
 *
 * @param[in] ptr the pointer to check
 * @return 1 if the pointer is null, 0 otherwise
 */
int is_null(const void *ptr);

/**
 * Copies a string, handling null input and return values.
 *
 * @param[in] src the source string
 * @param[out] dest the destination string
 * @param[in] dest_size the size of the destination buffer
 * @return the actual size of the string, or -1 on error
 */
int string_copy(const char *src, char *dest, size_t dest_size);

/**
 * Prints an error message to stderr.
 *
 * @param[in] fmt the format string
 * @param[in] ... the arguments to print
 */
void print_error(const char *fmt, ...);

/**
 * Prints a message to stderr.
 *
 * @param[in] fmt the format string
 * @param[in] ... the arguments to print
 */
void print_info(const char *fmt, ...);

#endif /* KRR_READ_UTILS_H */