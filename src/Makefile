# This Makefile makes all the tests in subdirectories.
# Each subdirectory has their own Makefile.

# names of the executables, also subdirectories, one for each test
BINNAMES = simplescan

# output directory paths
OBJDIR = ../obj
BINDIR = ../bin/debug
DIRS   := $(OBJDIR) ../bin/debug ../bin/release

# output file paths
BINARIES = $(addprefix $(BINDIR)/,$(BINNAMES))
OBJECTS  = $(addsuffix .o,$(addprefix $(OBJDIR)/,$(BINNAMES)))
SOURCES  = $(wildcard */*.cxx)


debug: TARGET=debug

release: TARGET=release
release: BINDIR=../bin/release

debug: all
release: all

all: $(BINARIES)

# build all tests
$(BINARIES): $(OBJECTS) $(SOURCES)
	(cd $(notdir $@) && make $(TARGET))

clean: $(DIRS)
	rm -f $(addsuffix /*,$^)

$(DIRS):
	mkdir -p $@

.PHONY: clean all debug release
