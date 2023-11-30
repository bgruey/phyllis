# Make the Pin Thread Library!
.RECIPEPREFIX = >
CC=/usr/bin/gcc
BASE_CFLAGS=-shared -fPIC -Wall -I../inc
LD=/usr/bin/ld
LDFLAGS=-shared -fPIC -L../lib -lbcm2835 -lutils

srcfiles = $(wildcard *.c)
objfiles = $(srcfiles:.c=.o)
target = libpinio.so

default: build

debug: CFLAGS = -g -O0 -ggdb3 $(BASE_CFLAGS)
debug: $(target)

build: CFLAGS = $(BASE_CFLAGS)
build: $(target)

$(target): $(objfiles)
>   $(LD) $(LDFLAGS) -o $@ $^;
>	rm -f *.o

%.o: %.c
>	$(CC) $(CFLAGS) -o $@ -c $^

.PHONY: clean
clean:
>   rm -f $(target);
