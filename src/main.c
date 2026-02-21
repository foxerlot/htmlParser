#include <stdio.h>
#include "utilities.h"

/* global variables */
const char *usage = "USAGE: htmlParser [options] <input.hml>...";

/* prototypes */
void search(char*); /* Look for closing tag (assuming that the tag needs closing,) and return 1 if not found */

/* main */
int main(int argc, char **argv)
{
    if (argc < 2) { DIE(usage); }

    FILE *contents = fopen(argv[1], "r");
    if (!contents) { DIE("Failed to open file"); }

    char *line = NULL;
    size_t length = 0;

    while (getline(&line, &length, contents) != -1)
    {
        for (int i = 0; i < length; i++)
        {
            if (line[i] == '<')
            {
                /*
                 * TODO: Implement search function (and utilize here)
                 */
                char *tag;
                for (int j = 0; line[i] != '>' && line[i] != '\0'; i++, j++)
                {
                    tag[j] = line[i];
                }
                tag[j] = '\0';
                search(tag);
            }
        }
    }

    fclose(contents);
    free(line);
    return 0;
}
