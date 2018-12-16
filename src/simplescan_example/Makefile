# executable name
BIN=simplescan_example

# compiler and linker options
CC=gcc
LIBS=-lz -lbluetooth
CFLAGS=-std=c99
INCLUDES=

# directory paths
OBJDIR=../../obj
SRCDIR=.
BINDIR=../../bin/debug

# executable path
BINPATH=$(BINDIR)/$(BIN)

SOURCES := $(wildcard *.c)
OBJECTS := $(addprefix $(OBJDIR)/,$(SOURCES:.c=.o))

debug: CFLAGS += -g -Wall -Wextra

release: CC=$(RELEASE_TOOLPREFIX)gcc
release: CFLAGS += -g
release: BINDIR=../../bin/release

debug: $(BINPATH)
release: $(BINPATH)

$(BINPATH): $(OBJECTS)
	$(CC) $^ -o $@ $(LIBS)

$(OBJDIR)/%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@


.PHONY: debug release
