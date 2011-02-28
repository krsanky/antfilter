# need $GOROOT set

# run make go-env
include $(GOROOT)/src/Make.inc

PROJ = antfilter

# source files in package
GOFILES=\
	$(PROJ).go

# build "antfilter" executable
$(PROJ): $(GOFILES)
	$(GC) antfilter.go
	$(LD) -o $@ antfilter.$O
	@echo "Done. Executable is: $@"

clean:
	rm -rf *.[$(OS)o] *.a [$(OS)].out $(PROJ)

.phony: clean $(PROJ)
