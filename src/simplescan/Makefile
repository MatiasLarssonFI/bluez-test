# executable name
BIN=simplescan

# compiler and linker options
CXX=g++
LIBS=-lz -lbluetooth
CXXFLAGS=-std=c++11
INCLUDES=

# directory paths
OBJDIR=../../obj
SRCDIR=.
BINDIR=../../bin/debug

# executable path
BINPATH=$(BINDIR)/$(BIN)

SOURCES := $(wildcard *.cxx)
OBJECTS := $(addprefix $(OBJDIR)/,$(SOURCES:.cxx=.o))

debug: CXXFLAGS += -g -Wall -Wextra

release: CXX=$(RELEASE_TOOLPREFIX)g++
release: CXXFLAGS += -O2
release: BINDIR=../../bin/release

debug: $(BINPATH)
release: $(BINPATH)

$(BINPATH): $(OBJECTS)
	$(CXX) $^ -o $@ $(LIBS)

$(OBJDIR)/%.o: %.cxx
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@


.PHONY: debug release
