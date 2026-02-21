#include <stdio.h>
#include <string.h>
#include "parse-util.h"
#include "utilities.h"

int close(char *tag, FILE* contents, char *filename)
{
    char *closing_tag = strdup(tag);
    GLOB(closing_tag);
    FILE *temp = contents;
    contents = freopen(filename, "w", stdout);

    fclose(temp);
    return 0;
}
