BIN=simplescan

CXX=g++
LIBS=-lz -lbluetooth
CXXFLAGS=-std=c++11
INCLUDES=

OBJDIR=../../obj
SRCDIR=.
BINDIR=../../bin/debug
objects := $(patsubst %.cxx,%.o,$(wildcard *.cxx))

debug: CXXFLAGS += -g -Wall -Wextra

release: CXX=arm-linux-gnueabihf-g++
release: CXXFLAGS += -O2
release: BINDIR=../../bin/release

debug: $(BIN)
release: $(BIN)

$(BIN): $(objects)
	$(CXX) $(addprefix ${OBJDIR}/,$^) -o $(BINDIR)/$@ $(LIBS)

%.o: %.cxx
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o ${OBJDIR}/$@
