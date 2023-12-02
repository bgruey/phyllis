# Build Puppet Program
.RECIPEPREFIX = >
CC=/usr/bin/gcc
BASE_CFLAGS=-Wall -I/usr/local/include -I../libs/inc
#CFLAGS+=-g -O0 -ggdb3
export CFLAGS
LD=/usr/bin/ld
LDFLAGS=-lm \
        -L/usr/local/lib -lbcm2835 \
        -L../libs/lib -lpinio -lpthread_workers -lsignal_processors -lutils \
        -L./dancer -ldancer
export LD_LIBRARY_PATH=../libs/lib:dancer

default: debug

test: clean build 
>	valgrind --leak-check=full \
                --show-leak-kinds=all \
                --verbose \
                --log-file=valgrind-out.txt \
                --track-origins=yes \
                --num-callers=10 \
                ./puppet.x

debug: CFLAGS = -g -O0 -ggdb3 $(BASE_CFLAGS)
debug: BUILD_TARGET = debug
debug: test

run: CFLAGS = $(BASE_CFLAGS)
run: clean build
>       ./puppet.x

build: dancer 
>	$(CC) $(CFLAGS) -o puppet.x main.c $(LDFLAGS)

install: CFLAGS = $(BASE_CFLAGS)
install: clean build 
>       cp ../libs/lib/* /usr/local/lib/
>       cp puppet.x /usr/local/bin

dancer: libs
>       @echo ""
>       @echo "Building dancer"
>       $(MAKE) -C dancer $(BUILD_TARGET)

libs:
>       @echo ""
>       @echo "Building ../libs"
>       $(MAKE) -C ../libs $(BUILD_TARGET)

.PHONY: clean

clean:
>	rm -f *.x
>	$(MAKE) clean -C ../libs
>	$(MAKE) clean -C dancer
