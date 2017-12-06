.SUFFIXES: .c.o
CC=gcc
CFLAGS=
OUTPUT_FOLDER=out
SOURCE_FOLDER=src

all: ex1 hw1 hw2

ex1 hw1 hw2: out
		$(CC) $(CFLAGS) $(SOURCE_FOLDER)/$@.c -o $(OUTPUT_FOLDER)/$@

out:
		mkdir out

.PHONY: all
