#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 * @brief Configuration file for krr-read
 */

/**
 * @defgroup krr_read_features  Project Features
 * @{
 */

/**
 * @def KRR_RINGBUF_SIZE
 * @brief Size of the ring buffer
 */
#define KRR_RINGBUF_SIZE 1024

/**
 * @def KRR_READ_TIMEOUT
 * @brief Timeout for read operations in milliseconds
 */
#define KRR_READ_TIMEOUT 1000

/**
 * @}
 */

#endif /* CONFIG_H */