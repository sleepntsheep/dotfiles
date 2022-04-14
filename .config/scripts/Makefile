CC = gcc

CFLAGS = -std=c99 -Wall -Werror -pedantic
	
SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
