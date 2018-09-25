CFLAGS = -ansi -pedantic -Wall -O2 -fopenmp
CC = gcc

source=$(wildcard *.c)

obj = $(source:.c=)

all: $(obj)

$(obj): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(obj)
