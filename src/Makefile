# This Makefile makes all the tests in subdirectories.
# Each subdirectory has their own Makefile.

# cross compilation toolchain bin path
CROSS_TOOLCHAIN_BINDIR=$(HOME)/pi-toolchain/tools/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-

# names of the executables, also subdirectories, one for each test
BINNAMES = simplescan

# output directory paths
OBJDIR = ../obj
BINDIR = ../bin/debug
DIRS   := $(OBJDIR) ../bin/debug ../bin/release

# output file paths
BINARIES = $(addprefix $(BINDIR)/,$(BINNAMES))
SOURCES  = $(wildcard */*.cxx)


debug: TARGET=debug

release: TARGET=release
release: BINDIR=../bin/release

debug: all
release: all

all: $(BINARIES)

# build all tests
$(BINARIES): $(SOURCES)
	(cd $(notdir $@) && make RELEASE_TOOLPREFIX=$(CROSS_TOOLCHAIN_BINDIR) $(TARGET))

clean: $(DIRS)
	rm -f $(addsuffix /*,$^)

$(DIRS):
	mkdir -p $@

.PHONY: clean all debug release
