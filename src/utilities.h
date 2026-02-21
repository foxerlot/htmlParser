/* See LICENSE file for copyright and license details. */
#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdlib.h>

/* simple DIE macro. TODO: make it variadic. */
#define DIE(msg)                      \
    do {                              \
        fprintf(stderr, "%s\n", msg); \
        exit(1);                      \
    } while (0)

#define GLOB(x) (void)(x)

#endif
