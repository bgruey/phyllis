# Make the Puppet Library!
.RECIPEPREFIX = >
CC=/usr/bin/gcc
BASE_CFLAGS=-shared -fPIC -Wall -I../inc
LD=/usr/bin/ld
LDFLAGS=-shared -fPIC -lm \
		-L../lib -lutils

srcfiles = $(wildcard *.c)
objfiles = $(srcfiles:.c=.o)
target = libsignal_processors.so

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
>   rm -f $(target)
