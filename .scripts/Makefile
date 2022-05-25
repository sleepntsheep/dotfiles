CC = gcc

DEST = /usr/local/bin/

CFLAGS = -std=c99 -Wall -Werror -pedantic
	
SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

