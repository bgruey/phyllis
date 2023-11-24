# Make the Puppet Library!
.RECIPEPREFIX = >
CC=/usr/bin/gcc
CFLAGS=-g -O0 -shared -fPIC -ggdb3 -Wall
LD=/usr/bin/ld
LDFLAGS=-shared -fPIC

srcfiles = $(wildcard *.c)
objfiles = $(srcfiles:.c=.o)

default: libutils.so

libutils.so: $(objfiles)
>   $(LD) $(LDFLAGS) -o $@ $^;
>	rm -f *.o

.PHONY: clean
clean:
>   rm -f libsigproc.so;
