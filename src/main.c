#include <stdlib.h>
#include <stdio.h>
// #include <string.h>
#include "utilities.h"
// #include "parse-util.h"

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

    while (getline(&line, &length, contents) != -1)
    {
        for (int i = 0; i < (int) length; i++)
        {
            char *tag = NULL;
            int k = 1;
            if (line[i++] == '<')
            {
                for (int j = 0; line[j] != '>'; j++)
                {
                    tag = realloc(tag, k++ * sizeof(char));
                    tag[k] = line[j];
                }
            }
            printf("%s\n", tag);
        }
    }

    fclose(contents);
    free(line);
    return 0;
}
