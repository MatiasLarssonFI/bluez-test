OBJDIR=../obj


debug: TARGET=debug
release: TARGET=release

debug: all
release: all

all:
	(cd simplescan && make $(TARGET))

.PHONY: clean

dirs:
	mkdir -p ${OBJDIR} && \
	mkdir -p ../bin/debug
	mkdir -p ../bin/release

clean: dirs
	rm -f $(OBJDIR)/*.o
	rm -f ../bin/debug/*
	rm -f ../bin/release/*
