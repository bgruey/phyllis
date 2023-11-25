# Make the Dancer Library!
.RECIPEPREFIX = >
CC=/usr/bin/gcc
CFLAGS=-g -O0 -shared -fPIC -ggdb3 -Wall -I../../libs/inc
LD=/usr/bin/ld
LDFLAGS=-shared -fPIC -lbcm2835 \
		-L../../libs/lib -lpinio  -lpthread_workers -lsignal_processors -lutils

srcfiles = $(wildcard *.c)
objfiles = $(srcfiles:.c=.o)

default: libdancer.so

libdancer.so: $(objfiles)
>   $(LD) $(LDFLAGS) -o $@ $^;
>	rm -f *.o

%.o: %.c
>	$(CC) $(CFLAGS) -o $@ -c $^

.PHONY: clean
clean:
>   rm -f *.o libdancer.so;
