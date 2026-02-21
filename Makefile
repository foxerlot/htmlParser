CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c99

SOURCES := $(wildcard src/*.c)

all: clean build

build: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o htmlParser

clean:
	rm -f htmlParser

.PHONY: all build clean
