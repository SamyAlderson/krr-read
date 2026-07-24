#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "utils.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <test-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *test_file = argv[1];
    FILE *fp = fopen(test_file, "r");
    if (!fp) {
        fprintf(stderr, "Error opening test file '%s': %s\n", test_file, strerror(errno));
        return EXIT_FAILURE;
    }

    int line_count = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        line_count++;
        printf("%s", buffer);
    }

    fclose(fp);
    printf("\nTest file '%s' has %d lines\n", test_file, line_count);
    return EXIT_SUCCESS;
}