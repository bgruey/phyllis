# Build libraries
.RECIPEPREFIX = >

default: build

build: libpthread_workers.so libsignal_processors.so libutils.so
>	@echo ""
>	@echo "Finished building."

libpthread_workers.so: libutils.so libsignal_processors.so
>   @echo ""
>   @echo "Building $@"
>	$(MAKE) -C pthread_workers
>   mv pthread_workers/$@ ./lib/$@
>   cp pthread_workers/*.h inc/

libsignal_processors.so:
>	@echo ""
>   @echo "Building $@"
>   $(MAKE) -C signal_processors
>   mv signal_processors/libsignal_processors.so lib/libsignal_processors.so
>   cp signal_processors/*.h inc/

libutils.so:
>   @echo ""
>   @echo "Building $@"
>   $(MAKE) -C ./utils
>   mv ./utils/libutils.so ./lib/libutils.so
>   cp utils/*.h inc/

.PHONY: clean
clean:
>	rm -f inc/* lib/*