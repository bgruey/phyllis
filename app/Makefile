# Build Puppet Program
.RECIPEPREFIX = >
CC=/usr/bin/gcc
CFLAGS=-g -O0 -ggdb3 -Wall -I/usr/local/include -I../libs/inc
LD=/usr/bin/ld
LDFLAGS=-lm \
        -L/usr/local/lib -lbcm2835 \
        -L../libs/lib -lpinio -lpthread_workers -lsignal_processors -lutils \
        -L./dancer -ldancer
export LD_LIBRARY_PATH=../libs/lib:dancer

default: test

test: clean build 
>	valgrind --leak-check=full \
                --show-leak-kinds=all \
                --verbose \
                --log-file=valgrind-out.txt \
                --track-origins=yes \
                --num-callers=10 \
                ./puppet.x

run: build
>       ./puppet.x

build: dancer 
>	$(CC) $(CFLAGS) -o puppet.x main.c $(LDFLAGS)

dancer: libs
>       @echo ""
>       @echo "Building dancer"
>       $(MAKE) -C dancer

libs:
>       @echo ""
>       @echo "Building ../libs"
>       $(MAKE) -C ../libs

.PHONY: clean

clean:
>	rm -f *.x
>	$(MAKE) clean -C ../libs
>	$(MAKE) clean -C dancer
>       cp ~/libbcm2835.so ../libs/lib
>       cp ~/bcm2835.h ../libs/inc

