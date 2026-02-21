#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utilities.h"

/* global variables */
const char *usage = "USAGE: htmlParser [options] <input.hml>...";

/* main */
int main(int argc, char **argv)
{
    if (argc < 2) DIE(usage);

    FILE *contents = fopen(argv[1], "r");
    if (!contents) DIE("Failed to open file");

    char *line = NULL;
    size_t length = 0;
    ssize_t read;

    while ((read = getline(&line, &length, contents)) != -1) {
        for (int i = 0; i < read; i++) {
            if (line[i] == '<') {
                int j = i + 1;

                while (j < read && line[j] != '>')
                    j++;

                if (j < read) {
                    int tag_len = j - i - 1;

                    char *tag = malloc(tag_len + 1);
                    if (!tag) DIE("Failed to allocate memory");

                    memcpy(tag, &line[i + 1], tag_len);
                    tag[tag_len] = '\0';

                    printf("Tag: %s\n", tag);
                    free(tag);
                    i = j;
                }
            }
        }
    }

    fclose(contents);
    free(line);
    return 0;
}
