# Build libraries
.RECIPEPREFIX = >

default: build

debug: BUILD_TARGET = debug
debug: build_all

build: BUILD_TARGET = build
build: build_all
build_all: libpinio.so libpthread_workers.so libsignal_processors.so libutils.so
>	@echo ""
>	@echo "Finished building."

libpinio.so: libutils.so libsignal_processors.so
>   @echo ""
>   @echo "Building $@"
>	$(MAKE) -C pinio $(BUILD_TARGET)
>   mv pinio/$@ ./lib/$@
>   cp pinio/*.h inc/

libpthread_workers.so: libutils.so libsignal_processors.so
>   @echo ""
>   @echo "Building $@"
>	$(MAKE) -C pthread_workers $(BUILD_TARGET)
>   mv pthread_workers/$@ ./lib/$@
>   cp pthread_workers/*.h inc/

libsignal_processors.so: libutils.so
>	@echo ""
>   @echo "Building $@"
>   $(MAKE) -C signal_processors $(BUILD_TARGET)
>   mv signal_processors/libsignal_processors.so lib/libsignal_processors.so
>   cp signal_processors/*.h inc/

libutils.so:
>   @echo ""
>   @echo "Building $@"
>   $(MAKE) -C ./utils $(BUILD_TARGET)
>   mv ./utils/libutils.so ./lib/libutils.so
>   cp utils/*.h inc/

libbcm2835.so:
>   @echo ""
>   @echo "Building $@"
>   $(MAKE) -C ./bcm2835 $(BUILD_TARGET)
>   mv ./bcm2835/libbcm2835.so ./lib/libbcm2835.so
>   cp bcm2835/*.h inc/

.PHONY: clean
clean:
>	rm -f inc/* lib/*