#ifndef PARSE_UTIL_H
#define PARSE_UTIL_H

#include <stdio.h>

char tag_type(char*);
int close(char*, FILE*, char*); /* Look for closing tag (assuming that the tag needs closing,) and create it if not found */

#endif
