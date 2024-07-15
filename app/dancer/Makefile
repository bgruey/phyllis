# Make the Dancer Library!
.RECIPEPREFIX = >
CC=/usr/bin/gcc
BASE_CFLAGS=-shared -fPIC -Wall -I/usr/local/include -I../../libs/inc
LD=/usr/bin/ld
LDFLAGS=-shared -fPIC \
		-L/usr/local/lib -lbcm2835 \
		-L../../libs/lib -lpinio  -lpthread_workers -lsignal_processors -lutils

srcfiles = $(wildcard *.c)
objfiles = $(srcfiles:.c=.o)
target = libdancer.so

default: build

debug: CFLAGS = -g -O0 -ggdb3 $(BASE_CFLAGS)
debug: $(target)

build: CFLAGS = $(BASE_CFLAGS)
build: $(target)

libdancer.so: $(objfiles)
>   $(LD) $(LDFLAGS) -o $@ $^;
>	rm -f *.o

%.o: %.c
>	$(CC) $(CFLAGS) -o $@ -c $^

.PHONY: clean
clean:
>   rm -f *.o libdancer.so;
