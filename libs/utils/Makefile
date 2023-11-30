# Make the Puppet Library!
.RECIPEPREFIX = >
CC=/usr/bin/gcc
BASE_CFLAGS=-shared -fPIC -Wall
LD=/usr/bin/ld
LDFLAGS=-shared -fPIC

srcfiles = $(wildcard *.c)
objfiles = $(srcfiles:.c=.o)
target = libutils.so

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
>   rm -f libsigproc.so;
