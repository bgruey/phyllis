# Make the Pin Thread Library!
.RECIPEPREFIX = >
CC=/usr/bin/gcc
CFLAGS=-g -O0 -shared -fPIC -ggdb3 -Wall -I../inc
LD=/usr/bin/ld
LDFLAGS=-shared -fPIC -lbcm2835

srcfiles = $(wildcard *.c)
objfiles = $(srcfiles:.c=.o)
target = libpinio.so

default: $(target)

$(target): $(objfiles)
>   $(LD) $(LDFLAGS) -o $@ $^;
>	rm -f *.o

.PHONY: clean
clean:
>   rm -f $(target);
