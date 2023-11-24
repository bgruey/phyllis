# Build Puppet Program
.RECIPEPREFIX = >
CC=/usr/bin/gcc
CFLAGS=-g -O0 -ggdb3 -Wall -I../libs/inc
LD=/usr/bin/ld
LDFLAGS=-L../libs/lib -lpthread_workers -lsignal_processors -lutils -lm -L./dancer -ldancer
export LD_LIBRARY_PATH=../libs/lib:dancer

default: test




test2: build
>       gdb ./puppet.x

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
