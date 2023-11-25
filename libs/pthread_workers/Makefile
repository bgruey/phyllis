# Make the Pin Thread Library!
.RECIPEPREFIX = >
CC=/usr/bin/gcc
CFLAGS=-g -O0 -shared -fPIC -ggdb3 -Wall -I../inc
LD=/usr/bin/ld
LDFLAGS=-shared -fPIC -L../lib -lpinio -lutils

srcfiles = $(wildcard *.c)
objfiles = $(srcfiles:.c=.o)
target = libpthread_workers.so

default: $(target)

$(target): $(objfiles)
>   $(LD) $(LDFLAGS) -o $@ $^;
>	rm -f *.o

.PHONY: clean
clean:
>   rm -f $(target);
