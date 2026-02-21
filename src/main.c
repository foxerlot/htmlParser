#include <stdio.h>
#include "utilities.h"
#include "parse-util.h"

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
            if (line[i] == '<')
            {
                /*
                 * TODO: Implement search function (and utilize here)
                 */
                char *tag = NULL;
                for (int j = 0; line[i] != '>' && line[i] != '\0'; i++, j++)
                {
                    tag[j] = line[i];
                }
                if (close(tag, contents, argv[1]) != 0) DIE("Error parsing file.");
            }
        }
    }

    fclose(contents);
    free(line);
    return 0;
}
